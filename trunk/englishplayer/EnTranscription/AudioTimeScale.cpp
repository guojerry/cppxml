#include "stdafx.h"

#if (1100 > _MSC_VER)
#include <olectlid.h>
#else
#include <olectl.h>
#endif
#include "AudioTimeScale.h"
#include "resource.h"
#include <tchar.h>
#include <stdio.h>

#define TRANSFORM_NAME L"AudioTimeScale Filter"

// Constructor
CAudioTimeScale::CAudioTimeScale(TCHAR *tszName, LPUNKNOWN punk, HRESULT *phr) :
    CTransformFilter(tszName, punk, CLSID_AudioTransformFrame)
{
} 

// ~CAudioTimeScale
CAudioTimeScale::~CAudioTimeScale() 
{
}

//
// CreateInstance
//
// Provide the way for COM to create a AudioTransformFrame object
//
CAudioTimeScale* CAudioTimeScale::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
    CAudioTimeScale *pNewObject = new CAudioTimeScale(NAME("AudioTransformFrame"), punk, phr);
    if (pNewObject == NULL) {
        *phr = E_OUTOFMEMORY;
    }
    return pNewObject;
}

//
// Transform
//
// Transforms the input and saves results in the the output
//
HRESULT CAudioTimeScale::Transform(IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	// input
    AM_MEDIA_TYPE* pTypeIn = &m_pInput->CurrentMediaType();
    WAVEFORMATEX *pihIn = (WAVEFORMATEX *)pTypeIn->pbFormat;
	unsigned char *pSrc = 0;
    pIn->GetPointer((unsigned char **)&pSrc);
	ASSERT(pSrc);

	// output
    AM_MEDIA_TYPE *pTypeOut = &m_pOutput->CurrentMediaType();
	WAVEFORMATEX *pihOut = (WAVEFORMATEX *)pTypeOut->pbFormat;
	short *pDst = 0;
    pOut->GetPointer((unsigned char **)&pDst);
	ASSERT(pDst);

	// TODO: insert procesing code here
	// for now, just make a copy of the input
    hr = Copy(pIn, pOut);
    if (hr != S_OK)
        return hr;
   
	return NOERROR;
}

//
// CheckInputType
//
// Check the input type is OK - return an error otherwise
//
HRESULT CAudioTimeScale::CheckInputType(const CMediaType *mtIn)
{
    // check this is an audio format that we can support
    if (*mtIn->FormatType() != FORMAT_WaveFormatEx) {
        return E_INVALIDARG;
    }

    // Can we transform this type
    if (CanPerformTransform(mtIn)) {
		CopyMediaType(&m_mt, mtIn);
    	return NOERROR;
    }
    return E_FAIL;
}

//
// Checktransform
//
// Check a transform can be done between these formats
//
HRESULT CAudioTimeScale::CheckTransform(const CMediaType *mtIn, const CMediaType *mtOut)
{
    if (CanPerformTransform(mtIn)) {
		return S_OK;
    }
    return VFW_E_TYPE_NOT_ACCEPTED;
}

//
// DecideBufferSize
//
// Tell the output pin's allocator what size buffers we
// require. Can only do this when the input is connected
//
HRESULT CAudioTimeScale::DecideBufferSize(IMemAllocator *pAlloc,ALLOCATOR_PROPERTIES *pProperties)
{
    // Is the input pin connected
    if (m_pInput->IsConnected() == FALSE) {
        return E_UNEXPECTED;
    }

	SetupSoundTouch();

    ASSERT(pAlloc);
    ASSERT(pProperties);
    HRESULT hr = NOERROR;

	// get input dimensions
	CMediaType inMediaType = m_pInput->CurrentMediaType();
	WAVEFORMATEX *pwfx = (WAVEFORMATEX *)m_mt.Format();
    pProperties->cBuffers = 1;
	int size = pwfx->nAvgBytesPerSec;	//pwfx->nAvgBytesPerSec / 2;
    pProperties->cbBuffer = size; // same as input pin
    ASSERT(pProperties->cbBuffer);

    // Ask the allocator to reserve us some sample memory, NOTE the function
    // can succeed (that is return NOERROR) but still not have allocated the
    // memory that we requested, so we must check we got whatever we wanted

    ALLOCATOR_PROPERTIES Actual;
    hr = pAlloc->SetProperties(pProperties,&Actual);
    if (FAILED(hr)) {
        return hr;
    }

    ASSERT( Actual.cBuffers == 1 );

    if (pProperties->cBuffers > Actual.cBuffers ||
            pProperties->cbBuffer > Actual.cbBuffer) {
                return E_FAIL;
    }
    return NOERROR;
}

void CAudioTimeScale::SetupSoundTouch()
{
	WAVEFORMATEX *pwfx = (WAVEFORMATEX *)m_mt.Format();
	m_soundTouch.setSampleRate(pwfx->nSamplesPerSec);
	m_soundTouch.setChannels(pwfx->nChannels);

	m_soundTouch.setTempoChange(0);
	m_soundTouch.setPitchSemiTones(0);
	m_soundTouch.setRateChange(0);

	m_soundTouch.setSetting(SETTING_USE_QUICKSEEK, TRUE);
	m_soundTouch.setSetting(SETTING_USE_AA_FILTER, TRUE);

	if(1)
	{
		// use settings for speech processing
		m_soundTouch.setSetting(SETTING_SEQUENCE_MS, 40);
		m_soundTouch.setSetting(SETTING_SEEKWINDOW_MS, 15);
		m_soundTouch.setSetting(SETTING_OVERLAP_MS, 8);
	}
}

void CAudioTimeScale::SetRate(float nRate)
{
	if(nRate < -50 || nRate > 100)
	{
		ASSERT(FALSE);
		return;
	}
	m_soundTouch.setTempoChange(nRate);
}

//
// GetMediaType
//
// Returns the supported media types for the output pin in order of preferred types 
// starting with iPosition=0
//
HRESULT CAudioTimeScale::GetMediaType(int iPosition, CMediaType *pMediaType)
{
    // Is the input pin connected
    if (m_pInput->IsConnected() == FALSE)
        return E_UNEXPECTED;

    // This should never happen
    if (iPosition < 0)
        return E_INVALIDARG;

    // Do we have more items to offer
    if (iPosition >= 2)
        return VFW_S_NO_MORE_ITEMS;

	WAVEFORMATEX *pwfxin = (WAVEFORMATEX *)m_mt.pbFormat;

	if (iPosition == 0)
	{	// advertise the extensible format first
		WAVEFORMATEXTENSIBLE *pwfx = 
			(WAVEFORMATEXTENSIBLE *)pMediaType->AllocFormatBuffer(sizeof(WAVEFORMATEXTENSIBLE));

		pwfx->Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
		pwfx->Format.cbSize = sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);
		pwfx->Format.nChannels = pwfxin->nChannels;
		pwfx->Format.nSamplesPerSec = pwfxin->nSamplesPerSec;
		pwfx->Format.wBitsPerSample = pwfxin->wBitsPerSample;
		pwfx->Format.nAvgBytesPerSec = pwfx->Format.nSamplesPerSec * pwfx->Format.wBitsPerSample * pwfx->Format.nChannels / 8;
		pwfx->Format.nBlockAlign = pwfx->Format.wBitsPerSample * pwfxin->nChannels / 8;
		pwfx->dwChannelMask = (1 << pwfx->Format.nChannels) - 1;
		pwfx->Samples.wValidBitsPerSample = pwfx->Format.wBitsPerSample;
		pwfx->SubFormat = MEDIASUBTYPE_PCM;

		pMediaType->SetFormat((BYTE*)pwfx, sizeof(WAVEFORMATEXTENSIBLE));

		// Clear source and target rectangles
		pMediaType->SetType(&MEDIATYPE_Audio);
		pMediaType->SetFormatType(&FORMAT_WaveFormatEx);
		pMediaType->SetTemporalCompression(FALSE);

		GUID SubTypeGUID = MEDIASUBTYPE_PCM;
		pMediaType->SetSubtype(&SubTypeGUID);
		pMediaType->SetSampleSize(1);
	}
	else if (iPosition == 1)
	{	// our backup legacy format
		WAVEFORMATEX *pwfx = 
			(WAVEFORMATEX *)pMediaType->AllocFormatBuffer(sizeof(WAVEFORMATEX));
		pwfx->wFormatTag = WAVE_FORMAT_PCM;
		pwfx->cbSize = 0; // no extra data for basic PCM
		pwfx->nChannels = pwfxin->nChannels;
		pwfx->nSamplesPerSec = pwfxin->nSamplesPerSec;
		pwfx->wBitsPerSample = pwfxin->wBitsPerSample;
		pwfx->nAvgBytesPerSec = pwfx->nSamplesPerSec * pwfx->wBitsPerSample * pwfx->nChannels / 8;
		pwfx->nBlockAlign = pwfx->wBitsPerSample * pwfxin->nChannels / 8;
		
		pMediaType->SetFormat((BYTE*)pwfx, sizeof(WAVEFORMATEX));

		pMediaType->SetType(&MEDIATYPE_Audio);
		pMediaType->SetFormatType(&FORMAT_WaveFormatEx);
		pMediaType->SetTemporalCompression(FALSE);

		GUID SubTypeGUID = MEDIASUBTYPE_PCM;
		pMediaType->SetSubtype(&SubTypeGUID);
		pMediaType->SetSampleSize(1);
	}

    return NOERROR;
}

//
// CanPerformAudioTransformFrame
//
// Check that it is audio and a PCM format.  Can get more specific here if needed (i.e. samplerate, channels etc)
//
BOOL CAudioTimeScale::CanPerformTransform(const CMediaType *pMediaType) const
{
    if (IsEqualGUID(*pMediaType->Type(), MEDIATYPE_Audio)) {
		GUID SubTypeGUID = MEDIASUBTYPE_PCM;

        if (IsEqualGUID(*pMediaType->Subtype(), SubTypeGUID)) {
            WAVEFORMATEX *pwfx = (WAVEFORMATEX *) pMediaType->Format();
            return TRUE;
        }
    }
	return FALSE;
} 

#define WRITEOUT(var)  hr = pStream->Write(&var, sizeof(var), NULL); \
		       if (FAILED(hr)) return hr;

#define READIN(var)    hr = pStream->Read(&var, sizeof(var), NULL); \
		       if (FAILED(hr)) return hr;

//
// Copy
//
// Make destination an identical copy of source
//
HRESULT CAudioTimeScale::Copy(IMediaSample *pSource, IMediaSample *pDest)
{
    // Copy the sample data

    BYTE *pSourceBuffer, *pDestBuffer;
    long lSourceSize = pSource->GetActualDataLength();
    long lDestSize	= pDest->GetSize();

    ASSERT(lDestSize >= lSourceSize);

    pSource->GetPointer(&pSourceBuffer);
    pDest->GetPointer(&pDestBuffer);

	WAVEFORMATEX *pwfx = (WAVEFORMATEX *)m_mt.Format();
	int nSamples = lSourceSize / pwfx->nBlockAlign;
	// Feed the samples into SoundTouch processor
	m_soundTouch.putSamples((const SAMPLETYPE*)pSourceBuffer, nSamples);
	int nDestSize = pDest->GetSize();
	nSamples = m_soundTouch.receiveSamples((SAMPLETYPE*)pDestBuffer, nDestSize);

    REFERENCE_TIME TimeStart, TimeEnd;
    if (NOERROR == pSource->GetTime(&TimeStart, &TimeEnd)) {
        pDest->SetTime(&TimeStart, &TimeEnd);
    }

    LONGLONG MediaStart, MediaEnd;
    if (pSource->GetMediaTime(&MediaStart,&MediaEnd) == NOERROR) {
        pDest->SetMediaTime(&MediaStart,&MediaEnd);
    }

    // Copy the Sync point property

    HRESULT hr = pSource->IsSyncPoint();
    if (hr == S_OK) {
        pDest->SetSyncPoint(TRUE);
    }
    else if (hr == S_FALSE) {
        pDest->SetSyncPoint(FALSE);
    }
    else {  // an unexpected error has occured...
        return E_UNEXPECTED;
    }

    // Copy the media type

    AM_MEDIA_TYPE *pMediaType;
    pSource->GetMediaType(&pMediaType);
    pDest->SetMediaType(pMediaType);
    DeleteMediaType(pMediaType);

    // Copy the preroll property

    hr = pSource->IsPreroll();
    if (hr == S_OK) {
        pDest->SetPreroll(TRUE);
    }
    else if (hr == S_FALSE) {
        pDest->SetPreroll(FALSE);
    }
    else {  // an unexpected error has occured...
        return E_UNEXPECTED;
    }

    // Copy the discontinuity property

    hr = pSource->IsDiscontinuity();
    if (hr == S_OK) {
	pDest->SetDiscontinuity(TRUE);
    }
    else if (hr == S_FALSE) {
        pDest->SetDiscontinuity(FALSE);
    }
    else {  // an unexpected error has occured...
        return E_UNEXPECTED;
    }

    // Copy the actual data length
    pDest->SetActualDataLength(nSamples * pwfx->nBlockAlign);

    return NOERROR;
}
