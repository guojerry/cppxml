#pragma unmanaged

#ifndef _AUDIODOC_H_
#define _AUDIODOC_H_

#include "Qedit.h"
#include <dshow.h>

void Msg(TCHAR *szFormat, ...);

#define FREQBAND 12
#define NBUFFER 20

#define SAMPLE_RATE			44100
#define SAMPLE_INTERVAL		11.61							//It is a basic value, 25ms we can change it.
#define FFT_LEN				512								//=(SAMPLE_RATE*SAMPLE_INTERVAL/1000) 25ms samples for analysis, based on 44100Hz, 16Bits, 2 Channel
#define WINDOW_COUNT		1000 / SAMPLE_INTERVAL			//Windows count per second.
#define SECONDS_PER_PIXEL	0.00145125						//Seconds per pixel, =SAMPLE_INTERVAL / (PIXEL_PER_WINDOW * 1000)
#define PIXEL_PER_WINDOW	8								//Pixels per 512 samples

#define JIF(x) if (FAILED(hr=(x))) \
    {Msg(TEXT("FAILED(hr=0x%x) in ") TEXT(#x) TEXT("\n\0"), hr); return hr;}

#define LIF(x) if (FAILED(hr=(x))) \
    {Msg(TEXT("FAILED(hr=0x%x) in ") TEXT(#x) TEXT("\n\0"), hr);}

#define REGISTER_FILTERGRAPH

#define JIF(x) if (FAILED(hr=(x))) \
    {Msg(TEXT("FAILED(hr=0x%x) in ") TEXT(#x) TEXT("\n\0"), hr); return hr;}
#define LIF(x) if (FAILED(hr=(x))) \
    {Msg(TEXT("FAILED(hr=0x%x) in ") TEXT(#x) TEXT("\n\0"), hr);}

#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }
#define SAFE_DELETEARR(x) { if (x) delete [] x; x = NULL; }

class CMfcc;
class IAudioDocSink
{
public:
	virtual ~IAudioDocSink() {}

public:
	virtual void OnStatusChange() = 0;
	virtual void OnUpdateSoundData(double eTime, float* eVal, char nType, int nRelEnergy) = 0;
};

class CAudioDoc : public ISampleGrabberCB
{
public:
    CAudioDoc(IAudioDocSink* pSink);
    ~CAudioDoc();
    
    HRESULT MapFile(LPCWSTR wFile);
	HRESULT PrepareGrabber();
    HRESULT CloseMap();
    REFTIME GetPosition();
	REFTIME GetDuration();
	HRESULT SetPosition(REFTIME position);
	HRESULT SetVolume(long lVolume);
	long GetVolume();
    HRESULT Play();
    HRESULT Pause();
    HRESULT Stop();
	HRESULT EndStream();
	int GetStatus() {
		if (m_bPause) return 2;
		if (m_bPlaying) return 1;
		return 0;
	};
    BOOL IsPlaying()const{return m_bPlaying;}
    
	// ISampleGrabberCB
	STDMETHODIMP BufferCB(double SampleTime, BYTE *pBuffer, long BufferLen);
	STDMETHODIMP SampleCB(double SampleTime, IMediaSample *pSample);
	STDMETHODIMP_(ULONG) AddRef() { return 2; }
	STDMETHODIMP_(ULONG) Release() { return 1; }
	STDMETHODIMP QueryInterface(REFIID riid, void ** ppv)
	{
		if( riid == IID_ISampleGrabberCB || riid == IID_IUnknown ) 
		{
			*ppv = (void *) static_cast<ISampleGrabberCB*> ( this );
			return NOERROR;
		}    

		return E_NOINTERFACE;
	}

	void AnalyseThreadProc();
	void MonitorThreadProc();

protected:
	IMediaEventEx *m_pME;
	char* m_bufferIn[NBUFFER];
	WORD* m_leftbuffer;
	WORD* m_rightbuffer;
	float* m_waveform;
	float m_cep[32];
	double m_eTotalEnergy;
	long m_nTotalWindow;

	HANDLE m_hSemphore;
	int m_currentSampleBufferIndex;
	int m_currentSpectrumBufferIndex;
	BOOL m_bExit;
	REFTIME m_currentSampleTime;
	WAVEFORMATEX  m_wfx;
	IAudioDocSink* m_pSink;
	CMutex m_Lock;

private:
	HRESULT StartCheckTread();

	int m_bufferIndex;
	double* m_spectrumData[2];
	HANDLE m_hThread;
	HANDLE m_hAnalyzeThread;

    BOOL          m_bPause;
    BOOL          m_bPlaying;
    
	// DirectShow
	IGraphBuilder *m_pGB;
	IMediaControl *m_pMC;
	IBasicAudio   *m_pBA;
	IMediaSeeking *m_pMS;
	IMediaPosition *m_pMP;
	IBaseFilter *m_pGrabberF;
	CMfcc* m_mfcc;
	ISampleGrabber *m_pGrabber;
	DWORD g_dwGraphRegister;
	REFTIME m_stopTime;
};

#endif
