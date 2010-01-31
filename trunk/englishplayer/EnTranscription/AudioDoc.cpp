#include "stdafx.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <dshow.h>
#include "Qedit.h"
#include <strsafe.h>
#include <AtlConv.h>
#include "DshowUtil.h"
#include "AudioDoc.h"
#include "AudioProcess.h"

#pragma comment(lib, "strmiids.lib")

#define REGISTER_FILTERGRAPH

DWORD WINAPI ThreadProc(PVOID);
DWORD WINAPI AnalyzeThreadProc(PVOID);

#pragma unmanaged

CAudioDoc::CAudioDoc(IAudioDocSink* pSink)
{
    m_bPlaying = FALSE;
	m_bPause = FALSE;

	m_bufferIndex = 0;
	m_hThread = 0;
	m_hSemphore = 0;
	m_hAnalyzeThread = 0;
	m_pGB = 0;
	m_pMC = 0;
	m_pME = 0;
	m_pBA = 0;
	m_pMS = 0;
	m_pMP = 0;
	m_pGrabberF = 0;	
	m_pGrabber = 0;
	m_pSink = pSink;
	g_dwGraphRegister = 0;
	m_stopTime = 0;
	m_Processer = new CAudioProcess(this);

	for (int x = 0; x < NBUFFER; x++)
		m_bufferIn[x] = 0;
}

CAudioDoc::~CAudioDoc()
{
    CloseMap();
	if(m_Processer)
		delete m_Processer;
}
	
HRESULT CAudioDoc::CloseMap()
{
	HRESULT hr = S_OK;
	Stop();

#ifdef REGISTER_FILTERGRAPH
	// Remove from Graph Edit remote control
	RemoveGraphFromRot(g_dwGraphRegister);
    if (FAILED(hr))
    {
        Msg(TEXT("Failed to register filter graph with ROT!  hr=0x%x"), hr);
        g_dwGraphRegister = 0;
    }
#endif
	// Release COM object
	SAFE_RELEASE(m_pGrabber);
	SAFE_RELEASE(m_pGrabberF);
	SAFE_RELEASE(m_pMP);
	SAFE_RELEASE(m_pMS);
	SAFE_RELEASE(m_pBA);
	SAFE_RELEASE(m_pME);
	SAFE_RELEASE(m_pMC);
	SAFE_RELEASE(m_pGB);
	
	m_bufferIndex = 0;
	m_currentSampleBufferIndex = 0;
	m_currentSpectrumBufferIndex = 0;
	m_currentSampleTime = 0;
	for (int x = 0; x < NBUFFER; x++)
	{
		delete [] m_bufferIn[x];
		m_bufferIn[x] = 0;
	}

	return S_OK;
}

HRESULT CAudioDoc::MapFile(LPCWSTR wFile)
{
    if(!wFile)
        return FALSE;
    
    if(IsPlaying())
        Stop();
    
    // Close last time map
    CloseMap();
    
	HRESULT hr;

	// Create Filter Graph
    JIF(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
                         IID_IGraphBuilder, (void **)&m_pGB));

	if(SUCCEEDED(hr))
    {
		// Automatically render the file and establish the graph
        JIF(m_pGB->RenderFile(wFile, NULL));

		//Create Grabber Factory object
		JIF(CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (void **)&m_pGrabberF));
		JIF(m_pGB->AddFilter(m_pGrabberF, L"SampleGrabber"));

		// Prepare for the callback
		JIF(PrepareGrabber());

        // Query other interfaces
        JIF(m_pGB->QueryInterface(IID_IMediaControl, (void **)&m_pMC));
        JIF(m_pGB->QueryInterface(IID_IMediaEventEx, (void **)&m_pME));
        JIF(m_pGB->QueryInterface(IID_IMediaSeeking, (void **)&m_pMS));
        JIF(m_pGB->QueryInterface(IID_IMediaPosition, (void **)&m_pMP));
		JIF(m_pGB->QueryInterface(IID_IBasicAudio, (void **)&m_pBA));

#ifdef REGISTER_FILTERGRAPH
		// Add to ROT
		hr = AddGraphToRot(m_pGB, &g_dwGraphRegister);
        if (FAILED(hr))
        {
            Msg(TEXT("Failed to register filter graph with ROT!  hr=0x%x"), hr);
            g_dwGraphRegister = 0;
        }
#endif
	}
    
    return S_OK;
}

HRESULT CAudioDoc::PrepareGrabber()
{	
	// Query Sample Grabber interface
	HRESULT hr;
	m_pGrabberF->QueryInterface(IID_ISampleGrabber, (void**)&m_pGrabber);	

	// Prepare media type for PCM WAV
	AM_MEDIA_TYPE mt;
	//pGrabber->GetConnectedMediaType(&mt);
	//CopyMemory(&m_wfx, mt.pbFormat, sizeof(m_wfx));

	ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
	mt.majortype = MEDIATYPE_Audio;
	mt.subtype = MEDIASUBTYPE_PCM;
	mt.formattype = FORMAT_WaveFormatEx;
	
	ZeroMemory(&m_wfx, sizeof(m_wfx));

	// Default setting
	m_wfx.nChannels = 2;
	m_wfx.nSamplesPerSec = 44100; 
	m_wfx.wBitsPerSample = 16;
	m_wfx.nBlockAlign = m_wfx.nChannels * m_wfx.wBitsPerSample / 8;
	m_wfx.nAvgBytesPerSec = m_wfx.nSamplesPerSec * m_wfx.nBlockAlign;
	m_wfx.wFormatTag = WAVE_FORMAT_PCM;
	mt.lSampleSize = FFT_LEN * m_wfx.nBlockAlign;
	mt.bFixedSizeSamples = TRUE;
	mt.cbFormat = sizeof(m_wfx);
	mt.pbFormat = (BYTE *)&m_wfx;

	if(m_Processer)
		m_Processer->Init(m_wfx.nChannels);

	// Set Media Type
	JIF(m_pGrabber->SetMediaType(&mt));

	for (int x = 0; x < NBUFFER; x++)
		m_bufferIn[x] = new char[mt.lSampleSize];

	//FreeMediaType(mt);

	IPin *inPin;
	IBaseFilter *renderer;
	IBaseFilter *source;

	// Find the render and the first input pin
	FindFilterRenderer(m_pGB, &renderer);
	FindPinByIndex(renderer, PINDIR_INPUT, 0, &inPin);
	GetConnectedFilter(inPin, &source);
	// Insert the Grabber Filter before the render
	DisconnectPin(m_pGB, inPin);
	ConnectFilters(m_pGB, source, m_pGrabberF);
	ConnectFilters(m_pGB, m_pGrabberF, renderer);

	return S_OK;
}

/*******************************************************************************
* Play :
*
*******************************************************************************/
HRESULT CAudioDoc::Play()
{
    if (m_bPlaying || !(m_pMC))
        return S_OK;

	HRESULT hr;
	DWORD dwThreadId;

	m_hSemphore = CreateSemaphore(NULL, 0, NBUFFER, NULL);
	m_bExit = FALSE;
	m_hAnalyzeThread = CreateThread(NULL, 0, AnalyzeThreadProc, this, 0, &dwThreadId);
	
	// Set callback, second parameter: 0 -- SampleCB, 1 -- BufferCB
	JIF(m_pGrabber->SetCallback(this, 0));

	// Run the graph to play the media file
    JIF(m_pMC->Run());
    m_bPlaying = TRUE;

	StartCheckTread();
	if(m_pMP)
		m_pMP->get_StopTime(&m_stopTime);

	if(m_pSink)
		m_pSink->OnStatusChange();

	return S_OK;
}

/*******************************************************************************
* Pause :
*
*******************************************************************************/
HRESULT CAudioDoc::Pause()
{   
	HRESULT hr;
    if((m_bPlaying)&&(m_bPause))
    {
		JIF(m_pMC->Run());
        m_bPause = FALSE;
		StartCheckTread();
    }
    else if((m_bPlaying)&&(!m_bPause))
    {
		JIF(m_pMC->Pause());
        m_bPause = TRUE;
    }

	if(m_pSink)
		m_pSink->OnStatusChange();

	return S_OK;
}

HRESULT CAudioDoc::Stop()
{
	HRESULT hr;

	// Clear callback
	if (m_pGrabber)
		JIF(m_pGrabber->SetCallback(NULL, 0));

	if (m_hAnalyzeThread)
	{
		m_bExit = TRUE;
		ReleaseSemaphore(m_hSemphore, 1, NULL);
		WaitForSingleObject(m_hAnalyzeThread, 2000);
		CloseHandle(m_hAnalyzeThread);
		m_hAnalyzeThread = NULL;
	}
	if (m_hSemphore)
	{
		CloseHandle(m_hSemphore);
		m_hSemphore = NULL;
	}

	// Close the thread
	if (m_hThread)
	{
		if(m_pME)
		{
			IMediaEventSink* pSink = NULL;
			JIF(m_pGB->QueryInterface(IID_IMediaEventSink, (void**)&pSink));
			if(pSink)
			{
				pSink->Notify(EC_COMPLETE, NULL, NULL);
				SAFE_RELEASE(pSink);
			}
		}

		WaitForSingleObject(m_hThread, 2000);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}

	// Terminate the graph
	if (m_bPlaying)
	{
	    m_bPlaying = FALSE;
		JIF(m_pMC->Stop());
		JIF(m_pMP->put_CurrentPosition(0));
		if(m_pSink)
			m_pSink->OnStatusChange();
	}

	m_currentSampleBufferIndex = 0;
	m_currentSpectrumBufferIndex = 0;
	m_currentSampleTime = 0;

	return S_OK;
}

HRESULT CAudioDoc::StartCheckTread()
{
	if (m_hThread)
		CloseHandle(m_hThread);
	DWORD dwThreadId;
	m_hThread = CreateThread(NULL, 0, ThreadProc, this, 0, &dwThreadId);

	return S_OK;
}

HRESULT CAudioDoc::SetVolume(long lVolume)
{
	if (!(m_pMP)) return S_OK;

	return m_pBA->put_Volume(lVolume);
}

long CAudioDoc::GetVolume()
{
	if (!(m_pMP)) return 0;

	long plVolume;
	if (m_pBA->get_Volume(&plVolume))
		return plVolume;
	else
		return 0;
}

REFTIME CAudioDoc::GetDuration()
{
	if (!(m_pMP)) return 0;
	REFTIME pllTime;
	m_pMP->get_Duration(&pllTime);
	return pllTime;
}

REFTIME CAudioDoc::GetPosition()
{
	if (!(m_pMP) || (!m_bPlaying && !m_bPause)) 
		return 0;

	REFTIME pllTime;
	m_pMP->get_CurrentPosition(&pllTime);
	return pllTime;
}

HRESULT CAudioDoc::SetPosition(REFTIME position)
{
	if (!(m_pMP)) return S_OK;

	m_Lock.Lock();
	HRESULT hr = m_pMP->put_CurrentPosition(position);
	m_Lock.Unlock();
	m_currentSampleTime = position;

	return hr;
}

HRESULT CAudioDoc::EndStream()
{
	m_bPlaying = FALSE;

	if(m_pSink)
		m_pSink->OnStatusChange();

	return S_OK;
}

STDMETHODIMP CAudioDoc::BufferCB(double SampleTime, BYTE *pBuffer, long BufferLen)
{
	return 0;
}

STDMETHODIMP CAudioDoc::SampleCB(double SampleTime, IMediaSample *pSample)
{
	if (m_wfx.nChannels == 0) return 0;

	long dwSizeBuf = FFT_LEN * m_wfx.nBlockAlign;

	// Actual Data buffer length
	long BufferLen = pSample->GetActualDataLength();
	BYTE *pBuffer;
	pSample->GetPointer(&pBuffer);

	// Check if the last sample arrived.
	REFTIME t2;
	t2 = SampleTime + (1 / (double)m_wfx.nBlockAlign);
	BOOL flush = FALSE;
	if (t2 >= m_stopTime)
		flush = TRUE;

	long dataIndex = 0;

	// Copy the sample buffer to cache for process thread access
	while (dataIndex < BufferLen && m_bufferIn)
	{
		// If the buffer is first to use, initialize it with zero
		if (m_bufferIndex == 0)
			ZeroMemory(m_bufferIn[m_currentSampleBufferIndex], dwSizeBuf);

		// If the buffer has some data, then try to append
		// If the data is not enough to fill the buffer, set m_bufferIndex for next time.
		DWORD memToCopy;
		if (m_bufferIndex > 0)
			memToCopy = min(dwSizeBuf - m_bufferIndex, BufferLen - dataIndex);
		else
			memToCopy = min(dwSizeBuf, BufferLen - dataIndex);
		CopyMemory(m_bufferIn[m_currentSampleBufferIndex] + m_bufferIndex, &((char*)pBuffer)[dataIndex], memToCopy); 

		// Move bufferIndex forward, and check if all data copied
		// If the m_bufferIndex < dwSizeBuf, then no more data for copy, so break.
		// But for the last time, we need to reset and flush to the process thread.
		m_bufferIndex += memToCopy;
		if(m_bufferIndex < dwSizeBuf && !flush)
			break;
		m_bufferIndex = 0;

		LONG PreviousCount = 0;
		ReleaseSemaphore(m_hSemphore, 1, &PreviousCount);

		m_currentSampleBufferIndex++;
		if (m_currentSampleBufferIndex >= NBUFFER)
			m_currentSampleBufferIndex = 0;

		dataIndex += memToCopy;
	}

//	Msg(_T("C: %f - Pos: %f - Size: %d\n"), SampleTime, GetPosition(), BufferLen);

	return 0;
}

void CAudioDoc::AnalyseThreadProc()
{
	HRESULT hr = E_FAIL;
	while((WaitForSingleObject(m_hSemphore, INFINITE) == WAIT_OBJECT_0))
	{
		if(m_bExit)
			break;

		m_Lock.Lock();
		double wait = GetPosition();
		m_Lock.Unlock();
		m_currentSampleTime += SAMPLE_INTERVAL/1000.0;//wait;

		//Do process
		if(m_Processer)
			m_Processer->ProcessSample(m_bufferIn[m_currentSpectrumBufferIndex], FFT_LEN);

		m_currentSpectrumBufferIndex++;
		if (m_currentSpectrumBufferIndex >= NBUFFER)
			m_currentSpectrumBufferIndex = 0;
//		Msg(_T("AnalyzeThreadProc, current sample time=%f, value=%e\r\n"), p->m_currentSampleTime, lsum * 100 / 65536);
	}
}

void CAudioDoc::UpdateEnergy(int nRelEnergy)
{
	if(m_pSink)
		m_pSink->OnUpdateSoundData(m_currentSampleTime, nRelEnergy);
}

DWORD WINAPI AnalyzeThreadProc(PVOID param)
{
    CAudioDoc * pThis = (CAudioDoc*)param;
	if(pThis)
		pThis->AnalyseThreadProc();

	return 0;
}

void CAudioDoc::MonitorThreadProc()
{
	HRESULT hr = E_FAIL;
	long evCode = 0;

	while(m_pME && m_pME->WaitForCompletion(INFINITE, &evCode) != VFW_E_WRONG_STATE)
	{
		if(m_bExit)
			break;

		if (evCode == EC_COMPLETE)
		{
			EndStream();
		}
	}
}

int CAudioDoc::GetStatus()
{
	if(m_bPause) 
		return eStatusPause;
	if(m_bPlaying) 
		return eStatusPlaying;
	return eStatusStop;
}

void CAudioDoc::GetDrawData(int eType, float* pData, int& nLen)
{
	if(m_Processer != NULL)
		m_Processer->GetDrawData(eType, pData, nLen);
	else
		ASSERT(FALSE);
}

//////////////////////////////////////////////////////////////////////////
//Thread Proc
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI ThreadProc(PVOID param)
{
    CAudioDoc * p = (CAudioDoc*)param;
	if(p)
		p->MonitorThreadProc();

	return 0;
}

void Msg(TCHAR *szFormat, ...)
{
    TCHAR szBuffer[1024];  // Large buffer for long filenames or URLs
    const size_t NUMCHARS = sizeof(szBuffer) / sizeof(szBuffer[0]);
    const int LASTCHAR = NUMCHARS - 1;

    // Format the input string
    va_list pArgs;
    va_start(pArgs, szFormat);

    // Use a bounded buffer size to prevent buffer overruns.  Limit count to
    // character size minus one to allow for a NULL terminating character.
    (void)StringCchVPrintf(szBuffer, NUMCHARS - 1, szFormat, pArgs);
    va_end(pArgs);

    // Ensure that the formatted string is NULL-terminated
    szBuffer[LASTCHAR] = TEXT('\0');

    // Display a message box with the formatted string
    //MessageBox(NULL, szBuffer, TEXT("PlayWnd Sample"), MB_OK);
	OutputDebugString(szBuffer);
}
