#include "mp3parse.h"
#include <initguid.h>
#include "guidmp3p.h"

int tabsel_123[2][3][16] = 
{
	{ 
		{0,32,64,96,128,160,192,224,256,288,320,352,384,416,448,},
		{0,32,48,56, 64, 80, 96,112,128,160,192,224,256,320,384,},
		{0,32,40,48, 56, 64, 80, 96,112,128,160,192,224,256,320,} 
	},

	{ 
		{0,32,48,56,64,80,96,112,128,144,160,176,192,224,256,},
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,},
		{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,} 
	}
};
long freqs[9] = { 44100, 48000, 32000, 22050, 24000, 16000, 11025 , 12000 , 8000};
int genre_last=147;

char *genre_list[]=
{
	"Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk",
	"Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies",
	"Other", "Pop", "R&B", "Rap", "Reggae", "Rock",
	"Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks",
	"Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz+Funk",
	"Fusion", "Trance", "Classical", "Instrumental", "Acid", "House",
	"Game", "Sound Clip", "Gospel", "Noise", "AlternRock", "Bass",
	"Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock",
	"Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk",
	"Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta",
	"Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American", "Cabaret",
	"New Wave", "Psychadelic", "Rave", "Showtunes", "Trailer", "Lo-Fi",
	"Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical",
	"Rock & Roll", "Hard Rock", "Folk", "Folk/Rock", "National Folk", "Swing",
	"Fast-Fusion", "Bebob", "Latin", "Revival", "Celtic", "Bluegrass", "Avantgarde",
	"Gothic Rock", "Progressive Rock", "Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band",
	"Chorus", "Easy Listening", "Acoustic", "Humour", "Speech", "Chanson",
	"Opera", "Chamber Music", "Sonata", "Symphony", "Booty Bass", "Primus",
	"Porn Groove", "Satire", "Slow Jam", "Club", "Tango", "Samba",
	"Folklore", "Ballad", "Power Ballad", "Rhythmic Soul", "Freestyle", "Duet",
	"Punk Rock", "Drum Solo", "A capella", "Euro-House", "Dance Hall",
	"Goa", "Drum & Bass", "Club House", "Hardcore", "Terror",
	"Indie", "BritPop", "NegerPunk", "Polsk Punk", "Beat",
	"Christian Gangsta", "Heavy Metal", "Black Metal", "Crossover", "Contemporary C",
	"Christian Rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "JPop",
	"SynthPop",
};
extern FRAMEINFO frameinfo = {0,0,NULL};

///////////////////////////////////////////////////////////////////////////////
const AMOVIESETUP_MEDIATYPE sudInputTypes[] = {
	{ &MEDIATYPE_Stream, &CLSID_mpeg1audio },
};

const AMOVIESETUP_MEDIATYPE sudAudioTypes[] = {
	{ &MEDIATYPE_Audio, &CLSID_mp3 },
};

const AMOVIESETUP_PIN sudPins[] = {
	{
		NULL,                // unused
		FALSE,               // bRendered
		FALSE,               // bOutput
		FALSE,               // bZero
		FALSE,               // bMany
		NULL,                // unused
		NULL,                // unused
		1,                   // nTypes
		sudInputTypes,       // lpTypes
	},{     
		NULL,                // unused
		FALSE,               // bRendered
		TRUE,                // bOutput
		TRUE,                // bZero
		TRUE,                // bMany
		NULL,                // unused
		NULL,                // unused
		1,                   // nTypes
		sudAudioTypes,
	},
}; 

const AMOVIESETUP_FILTER sudMp3Parser = {
	&CLSID_CMp3Parser,
	L"MP3 Parser Filter",
	MERIT_NORMAL+1,
	sizeof(sudPins)/sizeof(AMOVIESETUP_PIN),
        sudPins,
};                     

CFactoryTemplate g_Templates[] = {
	{
		L"MP3 Parser Filter",
		&CLSID_CMp3Parser,
		CWavDestFilter::CreateInstance,
		NULL,
		&sudMp3Parser,
	}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);

STDAPI DllRegisterServer()
{
	return AMovieDllRegisterServer2( TRUE );
}

STDAPI DllUnregisterServer()
{
	return AMovieDllRegisterServer2( FALSE );
}
///////////////////////////////////////////////////////////////////////////////

HRESULT CWavDestFilter::Seek(REFERENCE_TIME rtStart)
{

	if (frameinfo_inited != true){
		return S_FALSE;
	}

	if (m_pInput == NULL){
		return E_UNEXPECTED;
	}

	if (m_pInput->IsConnected() == FALSE){
		return E_UNEXPECTED;
	}

	int AtStart = m_pInput->StartSeek();

	rtMediaStart = rtMediaStop = m_rtStart = rtStart;
//	m_llCurrent = time2address(m_rtStart);
	currentframe = time2frame(m_rtStart);

	seek_occured = true;

	return m_pInput->FinishSeek(AtStart);
}

HRESULT CWavDestFilter::CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin) 
{ 
	if (1/*direction == PINDIR_INPUT*/)
	{
		if(checked_input == false)
		{
			return S_OK;
		}
		
		if(frameinfo_inited == true)
		{
//			m_pOutput->SetDuration(info.duration);
//			Seek(0);
			return S_OK;
		}

		getframeinfo();
		frameinfo_inited = true;		//frameinfoは初期化された。

		m_pOutput->SetDuration(info.duration);
		Seek(0);
	}

	return S_OK; 
}

HRESULT CWavDestFilter::FillSample(IAsyncReader* pReader, IMediaSample* pSample)
{
	unsigned long head;
	int bitrate_index,lay,padding;
	long framesize;
	long data_used = 0;
	double time_used = 0.0;
	
	long sample_max = pSample->GetSize();
	PBYTE sampleBuffer(NULL);
	HRESULT hr = pSample->GetPointer(&sampleBuffer);
	if (FAILED(hr) || sampleBuffer == NULL)
		return E_FAIL;

	int isEOF = 0;

//	j = 0;
//	LONGLONG fpos = 0;
	while(1){

		if(ReaderRead(currentframe->offset,4,(BYTE *)&head,pReader) != S_OK){
			isEOF = 1;
			break;
		}

		if(!head_check(head = BSwap(head))){
			isEOF = 1;
			break;
		}
		
	    bitrate_index = ((head>>12)&0xf);
		padding       = ((head>>9)&0x1);
		lay           = 4-((head>>17)&3);
		framesize = tabsel_123[info.lsf][lay-1][bitrate_index]*144000/(info.freq<<info.lsf)+padding;
		
		if(sample_max - data_used < currentframe->size) break;
		
		if(ReaderRead(currentframe->offset,currentframe->size,(BYTE *)(sampleBuffer+data_used),pReader) == S_FALSE){
			isEOF = 1;
			break;
		}

		data_used += currentframe->size;
		time_used += (double)(framesize * 8) / (tabsel_123[info.lsf][lay-1][bitrate_index] * 1000);

		if(currentframe->next != NULL){
			currentframe = currentframe->next;
		}
		else {
			isEOF = 1;
			break;
		}
	}

//	m_llCurrent += data_used;
	pSample->SetActualDataLength(data_used);

	rtMediaStart = rtMediaStop;
	rtMediaStop  = (LONGLONG)(time_used * UNITS) + rtMediaStart;
	pSample->SetMediaTime(&rtMediaStart, &rtMediaStop);
	REFERENCE_TIME rtStart = rtMediaStart - m_rtStart;
	REFERENCE_TIME rtStop  = rtMediaStop  - m_rtStart;
	pSample->SetTime(&rtStart, &rtStop);

	if(seek_occured == true){
		pSample->SetDiscontinuity(TRUE);
		seek_occured = false;
	}
	else {
		pSample->SetDiscontinuity(FALSE);
	}
	pSample->SetSyncPoint(TRUE);
	pSample->SetPreroll(FALSE);

	return isEOF ? S_FALSE : S_OK;
}


// ------------------------------------------------------------------------
// constructor
//
CWavDestFilter::CWavDestFilter(LPUNKNOWN pUnk, HRESULT *phr) :
	CParserFilter(NAME("MP3 Parser Filter"), pUnk, CLSID_CMp3Parser)
{
	Init();
}

// ------------------------------------------------------------------------
// destructor
//
CWavDestFilter::~CWavDestFilter()
{
}

void CWavDestFilter::Init()
{
//	m_llCurrent = 0;				//ソースファイル上の現在の位置
	currentframe = NULL;			//現在再生中のフレームの情報を入れた構造体へのアドレス。
	m_rtStart = 0;					//シーク後の開始位置

	rtMediaStart = 0;				//処理しているサンプルの最初の時間
	rtMediaStop = 0;				//処理しているサンプルの終わりの時間

	frameinfo_inited = false;		//frameinfoはまだ初期化していない。
	checked_input = false;			//getmp3infoでチェックされてない。
	seek_occured = false;
}

CUnknown * WINAPI CWavDestFilter::CreateInstance(LPUNKNOWN pUnk, HRESULT * phr)
{
    return new CWavDestFilter(pUnk, phr);
}

//
// CWavDestFilter::CheckTransform
//
HRESULT CWavDestFilter::CheckTransform(const CMediaType *mtIn, const CMediaType *mtOut)
{
    HRESULT hr;
    if (FAILED(hr = CheckInputType(mtIn))) 
	{
		return hr;
    }

    return S_OK;
} // CheckTransform

//
// CheckInputType
//
HRESULT CWavDestFilter::CheckInputType(const CMediaType* mtIn)
{
    HRESULT hr;

	if (IsEqualGUID(*mtIn->Type(), MEDIATYPE_Stream) && IsEqualGUID(*mtIn->Subtype(), MEDIASUBTYPE_MPEG1Audio)){

		//すでに初期化済みなら正常終了させる
		if(checked_input == true){			//getmp3infoでチェック済み
			return S_OK;
		}
	
		hr = getmp3info();
		if (hr != S_OK){
			return VFW_E_TYPE_NOT_ACCEPTED;
		}

		checked_input = true;
		return S_OK;
	}

	return VFW_E_TYPE_NOT_ACCEPTED;
}

void CWavDestFilter::BuildWaveFormatEx(PWAVEFORMATEX * ppwfe,DWORD * pdwLength)
{
	PWAVEFORMATEX p = PWAVEFORMATEX(malloc(sizeof(WAVEFORMATEX)+MPEGLAYER3_FLAG_PADDING_ON));

	p->wFormatTag = 0x55;
	p->nChannels = info.nch;
	p->nSamplesPerSec = info.freq;
	p->nBlockAlign = 4;
	p->nAvgBytesPerSec = (DWORD)(info.nbytes * UNITS / info.duration);
	p->wBitsPerSample = 16;
	p->cbSize = MPEGLAYER3_FLAG_PADDING_ON;

	*pdwLength = (sizeof(WAVEFORMATEX)+MPEGLAYER3_FLAG_PADDING_ON);
	*ppwfe = p;
}

//
// GetMediaType
//
HRESULT CWavDestFilter::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (iPosition < 0){
		return E_INVALIDARG;
	}

	if (iPosition > 0){
		return VFW_S_NO_MORE_ITEMS;
	}

	PWAVEFORMATEX pwfe;
	DWORD dwLength;
	BuildWaveFormatEx(&pwfe, &dwLength);
	pMediaType->SetType(&MEDIATYPE_Audio);
	pMediaType->SetSubtype(&CLSID_mp3);
//	pMediaType->SetSubtype(&FOURCCMap(WAVE_FORMAT_MPEGLAYER3));
	pMediaType->SetFormatType(&FORMAT_WaveFormatEx);
	pMediaType->SetFormat((BYTE *)pwfe, dwLength);
	::free(pwfe);

	return NOERROR;
}

//
// DecideBufferSize
//
HRESULT CWavDestFilter::DecideBufferSize(IMemAllocator *pAlloc,ALLOCATOR_PROPERTIES *pProperties)
{
/*	//入力が接続されていなければ強制終了
	if (m_pInput->IsConnected() == FALSE) {
        return E_UNEXPECTED;
    }
*/
	pProperties->cbAlign = 1;
	pProperties->cbBuffer = 8000;
	pProperties->cbPrefix = 0;
	pProperties->cBuffers = 10;

	if (pAlloc)
	{
		// Ask the allocator to reserve us some sample memory, NOTE the function
		// can succeed (that is return NOERROR) but still not have allocated the
		// memory that we requested, so we must check we got whatever we wanted
		ALLOCATOR_PROPERTIES Actual;
		HRESULT hr = pAlloc->SetProperties(pProperties, &Actual);
		if (FAILED(hr))
			return hr;

		ASSERT( Actual.cBuffers >= 1 );

		if (pProperties->cBuffers > Actual.cBuffers || pProperties->cbBuffer > Actual.cbBuffer)
		{
			return E_FAIL;
		}
	}

	return NOERROR;
}

HRESULT CWavDestFilter::BreakConnect(PIN_DIRECTION dir)
{
	if (dir == PINDIR_INPUT){
		if(frameinfo_inited == true){
			FRAMEINFO * _frameinfo,* nextframeinfo;

			_frameinfo = frameinfo.next;

			while(1){
				if(_frameinfo == NULL) break;
				nextframeinfo = _frameinfo->next;
				delete _frameinfo;
				_frameinfo = nextframeinfo;
			}

			frameinfo.next = NULL;

			Init();
		}
	}

	return S_OK;
}


//ソースフィルタを同期読み込みするための関数
IAsyncReader * CWavDestFilter::ReaderOpen(void)
{
	IAsyncReader * pIAsyncReader(NULL);
	m_pInput->GetReader(&pIAsyncReader);
	return pIAsyncReader;
}
HRESULT CWavDestFilter::ReaderLength(LONGLONG *pTotal,IAsyncReader *reader)
{
	LONGLONG pAvailable;
	return reader->Length(pTotal,&pAvailable);
}

HRESULT CWavDestFilter::ReaderRead(LONGLONG llPosition,LONG llength,void *pBuffer,IAsyncReader *reader)
{
	return reader->SyncRead(llPosition,llength,(BYTE *)pBuffer);
}

HRESULT CWavDestFilter::ReaderClose(IAsyncReader *reader)
{
	reader->Release();
	return S_OK;
}

HRESULT CWavDestFilter::getmp3info(void)
{
	unsigned long head;
	int lsf,srate;
	int bitrate_index,mode,nch,lay,extension,mpeg25,padding;
	int i;
	IAsyncReader *reader;
	LONGLONG Total;
	LONGLONG hpos;
	HRESULT hr;

	reader = ReaderOpen();

	ReaderLength(&Total,reader);
	info.nbytes = Total;

	hpos = 0;

	{
		unsigned char c1,c2,c3,c4;

		ReaderRead(hpos,1,&c1,reader);	hpos ++;
		ReaderRead(hpos,1,&c2,reader);	hpos ++;
		ReaderRead(hpos,1,&c3,reader);	hpos ++;
		ReaderRead(hpos,1,&c4,reader);	hpos ++;

		if (c1 == 'I' && c2 == 'D' && c3 == '3'/* && c4 == 2*/) {
			hpos = 6;
			ReaderRead(hpos,1,&c1,reader);	hpos ++;
			ReaderRead(hpos,1,&c2,reader);	hpos ++;
			ReaderRead(hpos,1,&c3,reader);	hpos ++;
			ReaderRead(hpos,1,&c4,reader);	hpos ++;
			hpos = c1*2097152+c2*16384+c3*128+c4;
		}
		else hpos = 0;
	}

	bool	FindHeader = false;

	for(i = 0;i < 65536;i++) {
		hr = ReaderRead(hpos+i,4,(BYTE *)&head,reader);
		if(hr == S_FALSE) break;

		head = BSwap(head);

		// MPEG ヘッダ検出で終了。
		// なぜかMPEGシステムの時も接続されそうになるのでその対策
		{
			if((head & 0xffffff00) == 0x00000100){
				ReaderClose(reader);
				return S_FALSE;
			}
		}

		//ADTS ヘッダ検出で終了。
		{
			//MP3 のヘッダとよく似ているが、Layer-4は存在しない。
		    if ((head & 0xfff00000) == 0xfff00000 && 4-((head>>17)&0x3) == 4){
				ReaderClose(reader);
			    return S_FALSE;
			}
		}

		//MP3 のヘッダか確認。
		if(head_check(head)) {
			FindHeader = true;
			break;
		}
	}

	if(FindHeader == false) {
		ReaderClose(reader);
		return S_FALSE;
	}

	hpos += i;
	info.hpos = hpos;

	// read ID3 tag
	ReaderRead(Total-128,128,(BYTE *)&id3,reader);

	if (strncmp(id3.tag,"TAG",3) == 0) info.nbytes = info.nbytes - 128;

    if( head & (1<<20) ) {
		lsf = (head & (1<<19)) ? 0x0 : 0x1;
		mpeg25 = 0;
    } else {
		lsf = 1;
		mpeg25 = 1;
    }

    bitrate_index = ((head>>12)&0xf);
	padding       = ((head>>9)&0x1);
    mode          = ((head>>6)&0x3);
    nch           = (mode == MPG_MD_MONO) ? 1 : 2;
	lay           = 4-((head>>17)&3);
	extension     = ((head>>8)&0x1);

	if(mpeg25) srate = 6 + ((head>>10)&0x3);
    else srate = ((head>>10)&0x3) + (lsf*3);

	if (lay != 3)
	{
		ReaderClose(reader);
		return S_FALSE;
	}

	info.lsf  = lsf;
	info.freq = freqs[srate];
	info.nch  = nch;
	

	ReaderClose(reader);

//	m_llCurrent = info.hpos;

	return S_OK; 
}

HRESULT CWavDestFilter::getframeinfo(void)
{
	IAsyncReader *reader;
	LONGLONG fpos;
	DWORD framesize;
	double duration;
	FRAMEINFO * _frameinfo,* preframeinfo;
	unsigned long head;
	int i;
	HRESULT hr;
	int lsf,srate;
	int bitrate_index,mode,nch,extension,mpeg25,padding;
	
	reader = ReaderOpen();

	fpos = info.hpos;
	duration = 0;

	/*Initialize frameinfo structure*/
	frameinfo.time = -1;
	frameinfo.offset = -1;
	frameinfo.size = -1;
	frameinfo.before = NULL;
	frameinfo.next = NULL;

	preframeinfo = &frameinfo;
//	preframeinfo->offset = fpos;

	int j;						//エンコーダの不正でフレームサイズが
								//正しくない場合の補正カウンタ。
								//-1 ~ 1
	bool supplementary_framesize = false;

	for(i = 0; ; i++)
	{
		hr = ReaderRead(fpos,4,&head,reader);
		if(hr != S_OK)
		{
			break;
		}

		if(!head_check(head = BSwap(head)))	//フレームヘッダが見つからない時は、
		{									// +-1の範囲をチェック
			if(supplementary_framesize == false)
			{
				supplementary_framesize = true;
				fpos -= 1;
				j = -1;
				continue;
			}
			//Wilson Chen, 2010.4.18, comments these lines out to be more compatible with kinds of weird media file.
//			if(j > 1)
//				break;
			fpos ++;
			j ++;
			continue;
		}

	    if(head & (1<<20))
		{
			lsf = (head & (1<<19)) ? 0x0 : 0x1;
			mpeg25 = 0;
		}
		else 
		{
			lsf = 1;
			mpeg25 = 1;
	    }
	    bitrate_index = ((head>>12)&0xf);
		padding       = ((head>>9)&0x1);
	    mode          = ((head>>6)&0x3);
	    nch           = (mode == MPG_MD_MONO) ? 1 : 2;
		extension     = ((head>>8)&0x1);

		if(mpeg25) 
			srate = 6 + ((head>>10)&0x3);
	    else 
			srate = ((head>>10)&0x3) + (lsf*3);

		framesize = tabsel_123[lsf][3-1][bitrate_index] * 144000 / (freqs[srate] << lsf) + padding;
		duration += (double)framesize * 8.0 / (tabsel_123[lsf][3-1][bitrate_index] * 1000);

		_frameinfo = new FRAMEINFO;
		_frameinfo->time = (REFERENCE_TIME)(duration * 10000000);
		_frameinfo->offset = fpos;
		_frameinfo->size = framesize;
		_frameinfo->before = preframeinfo;
		_frameinfo->next = NULL;
		if(supplementary_framesize == true)
			preframeinfo->size += j;
		preframeinfo->next = _frameinfo;
		preframeinfo = _frameinfo;

		supplementary_framesize = false;
		fpos += framesize;
	}

	info.duration = (REFERENCE_TIME)(duration * 10000000);
	info.frames = i;

	ReaderClose(reader);

//	m_llCurrent = info.hpos;

	return S_OK; 
}


STDMETHODIMP CWavDestFilter::NonDelegatingQueryInterface(REFIID riid, void **p)
{
//	if(riid == IID_ISpecifyPropertyPages){
//		return GetInterface((CLSID_CMp3ParserPropertyPage *)(this), p);
//	}
	return CBaseFilter::NonDelegatingQueryInterface(riid, p);
}

//////////////////////////////////////////////////////////////////////////

int ExtractI4(unsigned char *buf)
{
	int x;
	x = buf[0];
	x <<= 8;
	x |= buf[1];
	x <<= 8;
	x |= buf[2];
	x <<= 8;
	x |= buf[3];
	return x;
}

int head_check(unsigned long head)
{
	if((head & 0xffe00000) != 0xffe00000) 
		return FALSE;

	//	if (!((head>>17)&0x3)) return FALSE;
	if(((head >> 12) & 0xf) == 0xf)
		return FALSE;

	if(((head >> 10) & 0x3) == 0x3)
		return FALSE;
	
	if((4 - ((head >> 17) & 3)) != 3) 
		return FALSE;

	return TRUE;
}

unsigned int BSwap(unsigned int Num)
{
	_asm {
		mov eax, Num
		bswap eax
		mov Num, eax
	}

	return Num;
}

REFERENCE_TIME address2time(LONGLONG address)
{
	FRAMEINFO * _frameinfo;

	_frameinfo = frameinfo.next;

	for(;;){
		if(_frameinfo->offset >= address) break;
		if(_frameinfo->next == NULL) break;
		_frameinfo = _frameinfo->next;
	}

	return _frameinfo->time;
}

LONGLONG time2address(REFERENCE_TIME time)
{
	FRAMEINFO * _frameinfo;

	_frameinfo = frameinfo.next;

	for(;;){
		if(_frameinfo->time >= time) break;
		if(_frameinfo->next == NULL) break;
		_frameinfo = _frameinfo->next;
	}

	return _frameinfo->offset;
}

FRAMEINFO * time2frame(REFERENCE_TIME time)
{
	FRAMEINFO * _frameinfo;

	_frameinfo = frameinfo.next;

	for(;;){
		if(_frameinfo->time >= time) break;
		if(_frameinfo->next == NULL) break;
		_frameinfo = _frameinfo->next;
	}

	return _frameinfo;
}