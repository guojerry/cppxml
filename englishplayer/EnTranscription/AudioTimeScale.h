#pragma once

#include "SoundTouch.h"
#include <streams.h>
#include <initguid.h>

using namespace soundtouch;

// these GUID's need to change if you clone this filter
// 12EC712A-46F6-4A3D-A934-EFB6354906A5
DEFINE_GUID(CLSID_AudioTransformFrame, 
			0x12ec712a, 0x46f6, 0x4a3d, 0xa9, 0x34, 0xef, 0xb6, 0x35, 0x49, 0x6, 0xa5);

class CAudioTimeScale : public CTransformFilter
{
public:
    DECLARE_IUNKNOWN;
    static CAudioTimeScale* CreateInstance(LPUNKNOWN punk, HRESULT *phr);

    // Overrriden from CTransformFilter base class
    HRESULT Transform(IMediaSample *pIn, IMediaSample *pOut);
    HRESULT CheckInputType(const CMediaType *mtIn);
    HRESULT CheckTransform(const CMediaType *mtIn, const CMediaType *mtOut);
    HRESULT DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProperties);
    HRESULT GetMediaType(int iPosition, CMediaType *pMediaType);
	/// Sets new tempo control value as a difference in percents compared
	/// to the original tempo (-50 .. +100 %)
	void SetRate(float nRate);

private:
    // Constructor
    CAudioTimeScale(TCHAR *tszName, LPUNKNOWN punk, HRESULT *phr);
	~CAudioTimeScale();

	HRESULT Copy(IMediaSample *pSource, IMediaSample *pDest);
	void SetupSoundTouch();
    BOOL CanPerformTransform(const CMediaType *pMediaType) const;

private:
	CMediaType m_mt;
	SoundTouch m_soundTouch;
};

