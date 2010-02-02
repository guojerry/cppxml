// NavigatorBar.cpp : 实现文件
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "NavigatorBar.h"
#include "AudioDoc.h"
#include "math.h"
#include "WaveBar.h"

#define REFRESH_TIMER			1
#define SLIDER_RANGE_MAX		100000
#undef SubclassWindow

// CNavigatorBar Dialog
IMPLEMENT_DYNAMIC(CNavigatorBar, CDialog)

CNavigatorBar::CNavigatorBar(CWnd* pParent /*=NULL*/)
{
	m_hPlayIcon = NULL;
	m_hPauseIcon = NULL;
	m_hStopIcon = NULL;
	m_pWaveBar = NULL;
	m_pAudioDoc = new CAudioDoc(this);
	m_bDictation = TRUE;
	m_eDictationEndPos = 0;
	m_eDictationStartPos = 0;
	m_nTimerCount = 0;
	m_nSilCount = 0;
	m_dBreakPoint = 0;
}

CNavigatorBar::~CNavigatorBar()
{
	if(m_pAudioDoc)
		delete m_pAudioDoc;
	m_pAudioDoc = NULL;
}

void CNavigatorBar::OnStatusChange()
{
	if(!m_pAudioDoc)
		return;
	int nStatus = m_pAudioDoc->GetStatus();
	if(nStatus == 0)
	{
		KillTimer(REFRESH_TIMER);
		UpdateUIStatus();
	}
}

void CNavigatorBar::OnUpdateSoundData(double eTime, int nRelEnergy)
{
	if(m_bDictation)
	{
		if(nRelEnergy < 20)
			m_nSilCount++;
		else
			m_nSilCount = 0;

		double eSpeakTime = eTime - m_eDictationStartPos;
		double eStandardEnergy = eSpeakTime * m_nSilCount * SAMPLE_INTERVAL;
		if(eStandardEnergy > 800 && eSpeakTime > 2 && m_eDictationEndPos < 0.0001)
		{
			m_dBreakPoint = eTime;
		}
	}
}

void CNavigatorBar::DoDataExchange(CDataExchange* pDX)
{
}

LRESULT CNavigatorBar::OnInitDialog(UINT wParam,LONG lParam) 
{
	m_hPlayIcon = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_PLAY), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hPauseIcon= (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_PAUSE), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hStopIcon= (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_STOP), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hOpenIcon = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_OPEN), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	CButton* pPlayBtn = (CButton*)GetDlgItem(IDC_BTN_PLAY);
	if(pPlayBtn)
		pPlayBtn->SetIcon(m_hPlayIcon);

	CButton* pStopBtn = (CButton*)GetDlgItem(IDC_BTN_STOP);
	if(pStopBtn)
		pStopBtn->SetIcon(m_hStopIcon);

	CButton* pOpenBtn = (CButton*)GetDlgItem(IDC_BTN_OPEN);
	if(pOpenBtn)
		pOpenBtn->SetIcon(m_hOpenIcon);

	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_VOLUME);
	if(pSlider)
	{
		pSlider->SetRangeMax(100);
		pSlider->SetRangeMin(1);
		pSlider->SetPageSize(10);
		pSlider->SetPos(100);
	}
	CButton* pDictation = (CButton*)GetDlgItem(IDC_CHECK_TRANS);
	pDictation->SetCheck(m_bDictation);

	m_pWaveBar = new CWaveBar(this);
	CRect rect;
	GetClientRect(&rect);
	rect.top += 1;		//Margin
	rect.bottom = rect.top + 60;
	m_pWaveBar->Create(NULL, NULL, WS_CHILD|WS_VISIBLE, rect, this, IDW_WAVEBAR, NULL);

	if(!UpdateData(FALSE))
	{
		TRACE("InitCDataStatus Failed!");
	}

	//To eliminate the dialog flash issue.
	DWORD dwStyleEx = GetWindowExStyle(m_hWnd);
	dwStyleEx |= WS_EX_COMPOSITED;
	SetWindowLong(m_hWnd, GWL_EXSTYLE, dwStyleEx);

	//Initialize Slider
	HWND hSlider = NULL;
	GetDlgItem(IDC_MY_PROGRESS, &hSlider);
	if(hSlider && m_aSliderProgress.SubclassWindow(hSlider))
	{
		m_aSliderProgress.Init();
		m_aSliderProgress.SetRange(0, SLIDER_RANGE_MAX);
	}
	return 0; 
}

BEGIN_MESSAGE_MAP(CNavigatorBar, CDialogBar)
	ON_MESSAGE(WM_INITDIALOG, &CNavigatorBar::OnInitDialog)
	ON_BN_CLICKED(IDC_BTN_PLAY, &CNavigatorBar::OnBnClickedBtnPlay)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CNavigatorBar::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_STOP, &CNavigatorBar::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_MY_PROGRESS, &CNavigatorBar::OnSliderChanged)
	ON_WM_TIMER()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_VOLUME, &CNavigatorBar::OnVolumePosChanging)
	ON_WM_DESTROY()
	ON_WM_SIZE()
ON_WM_KEYDOWN()
ON_BN_CLICKED(IDC_CHECK_TRANS, &CNavigatorBar::OnBnClickedCheckTrans)
END_MESSAGE_MAP()

void CNavigatorBar::OnBnClickedBtnPlay()
{
	if(m_pAudioDoc == NULL)
		return;

	if(!m_pAudioDoc->IsPlaying())
	{
		m_pAudioDoc->Play();
		m_pAudioDoc->SetPosition(0);
		m_aSliderProgress.SetAPoint(0);
		m_aSliderProgress.SetBPoint(0);
		UpdateVolume();
		UpdateUIStatus();
		m_dBreakPoint = 0;
		m_eDictationStartPos = 0;
		m_eDictationEndPos = 0;
		SetTimer(REFRESH_TIMER, 12, NULL);
	}
	else
		m_pAudioDoc->Pause();
	UpdateUIStatus();
}

void CNavigatorBar::OnBnClickedBtnOpen()
{
	CFileDialog dlg(TRUE);
	if(IDOK == dlg.DoModal())
	{
		CString sFilePath = dlg.GetPathName();
		CString sFileName = dlg.GetFileName();

		if(m_pAudioDoc)
		{
			HRESULT hr = m_pAudioDoc->MapFile(sFilePath);
			if(SUCCEEDED(hr))
				OnBnClickedBtnPlay();
		}
	}
}

void CNavigatorBar::OnBnClickedBtnStop()
{
	if(m_pAudioDoc == NULL || !m_pAudioDoc->IsPlaying())
		return;

	m_pAudioDoc->Stop();
	KillTimer(REFRESH_TIMER);
	UpdateUIStatus();
}

void CNavigatorBar::UpdateUIStatus()
{
	if(m_pAudioDoc == NULL)
		return;

	if(m_pWaveBar && m_pAudioDoc->GetStatus() == CAudioDoc::eStatusPlaying)
		m_pWaveBar->Invalidate(FALSE);

	BOOL bPaused = m_pAudioDoc->GetStatus() != 1;
	CButton* pPlayBtn = (CButton*)GetDlgItem(IDC_BTN_PLAY);
	if(pPlayBtn)
		pPlayBtn->SetIcon(bPaused ? m_hPlayIcon : m_hPauseIcon);

	REFTIME eDuration = m_pAudioDoc->GetDuration();
	REFTIME eCurrent = m_pAudioDoc->GetPosition();
	CString duration = FormatTime(eCurrent);
	CString current = FormatTime(eDuration);
	CString sTimeSpan = duration + _T(" / ") + current;
	CStatic* pTimeSpan = (CStatic*)GetDlgItem(IDC_TIMESPAN);
	if(pTimeSpan)
		pTimeSpan->SetWindowText(sTimeSpan);

	int ePos = int(eCurrent * SLIDER_RANGE_MAX / eDuration);
	m_aSliderProgress.SetPos(ePos);
}

CString CNavigatorBar::FormatTime(double time)
{
	CString sRet;
	int hour = int(time / 3600);
	int minutes = int((time - hour * 3600) / 60);
	int seconds = ((int)(time - hour * 3600 - 60 * minutes));
	CString sTemp;
	if(hour > 0)
	{
		sTemp.Format(_T("%02d:"), hour);
		sRet += sTemp;
	}

	sTemp.Format(_T("%02d:"), minutes);
	sRet += sTemp;

	sTemp.Format(_T("%02d"), seconds);
	sRet += sTemp;

	return sRet;
}

void CNavigatorBar::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == REFRESH_TIMER)
	{
		double eCur = GetCurrentPos();
		if(m_bDictation)
		{
			if(eCur > m_eDictationEndPos && m_eDictationEndPos > 0.001 && m_pAudioDoc && m_pAudioDoc->GetStatus() == 1)
			{
				m_pAudioDoc->Pause();
				UpdateUIStatus();
				return;
			}
		}
		m_nTimerCount++;
		if(m_nTimerCount >= 5)
		{
			m_nTimerCount = 0;
			UpdateUIStatus();
		}

		if(m_dBreakPoint > 0.001 && m_dBreakPoint < eCur && m_eDictationEndPos < 0.0001)
			SetRepeatB();
	}

	CDialogBar::OnTimer(nIDEvent);
}

void CNavigatorBar::UpdateVolume()
{
	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_VOLUME);
	long lPos = 0;
	if(pSlider)
	{
		double pos = pSlider->GetPos();
		lPos = -10000 + long(log10(pos) * 5000);
	}
	if(m_pAudioDoc && m_pAudioDoc->IsPlaying())
	{
		m_pAudioDoc->SetVolume(lPos);
	}
}

void CNavigatorBar::OnVolumePosChanging(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateVolume();
	*pResult = 0;
}

void CNavigatorBar::OnDestroy()
{
	if(m_pWaveBar)
	{
		m_pWaveBar->DestroyWindow();
		delete m_pWaveBar;
		m_pWaveBar = NULL;
	}
	CDialogBar::OnDestroy();
	if(m_pAudioDoc && m_pAudioDoc->IsPlaying())
	{
		KillTimer(REFRESH_TIMER);
		m_pAudioDoc->Stop();
	}
}

void CNavigatorBar::OnSize(UINT nType, int cx, int cy)
{
	if(m_pWaveBar)
	{
		RECT rc = {0};
		m_pWaveBar->GetClientRect(&rc);
		if(cx != 0 && rc.right - rc.left != cx)
		{
			rc.right = rc.left + cx;
			m_pWaveBar->MoveWindow(&rc, TRUE);
		}
	}
	CDialogBar::OnSize(nType, cx, cy);
}

double CNavigatorBar::GetCurrentPos()
{
	if(m_pAudioDoc)
		return m_pAudioDoc->GetPosition();
	return 0;
}

void CNavigatorBar::SetCurrentPos(double pos)
{
	if(m_pAudioDoc && m_pAudioDoc->IsPlaying())
	{
		m_pAudioDoc->SetPosition(pos);
		if(m_bDictation)
		{
			m_eDictationStartPos = pos;
			m_eDictationEndPos = 0;
			double eDuration = m_pAudioDoc->GetDuration();
			if(eDuration != 0)
			{
				m_aSliderProgress.SetAPoint(int(pos * SLIDER_RANGE_MAX / eDuration));
				m_aSliderProgress.SetBPoint(0);
			}
		}
	}
}

void CNavigatorBar::SetRepeatA()
{
	if(NULL == m_pAudioDoc)
		return;

	m_eDictationStartPos = GetCurrentPos() - 0.4;
	if(m_pAudioDoc->GetStatus() == 2)
	{
		m_pAudioDoc->Pause();
	}
	m_pAudioDoc->SetPosition(m_eDictationStartPos);
	double eDuration = m_pAudioDoc->GetDuration();
	if(eDuration != 0)
	{
		m_aSliderProgress.SetAPoint(int(m_eDictationStartPos * SLIDER_RANGE_MAX / eDuration));
	}
	m_aSliderProgress.SetBPoint(0);
	m_eDictationEndPos = 0;
	m_dBreakPoint = 0;
	UpdateUIStatus();
}

void CNavigatorBar::SetRepeatB()
{
	if(NULL == m_pAudioDoc)
		return;

	double eCurrPos = GetCurrentPos();
	if(m_pAudioDoc->GetStatus() == 1 && eCurrPos >= m_eDictationEndPos)
	{
		m_eDictationEndPos = eCurrPos;
		double eDuration = m_pAudioDoc->GetDuration();
		if(eDuration != 0)
		{
			m_aSliderProgress.SetBPoint(int(m_eDictationEndPos * SLIDER_RANGE_MAX / eDuration));
		}
	}
	else if(m_pAudioDoc->GetStatus() == 2 && eCurrPos >= m_eDictationEndPos)
	{
		m_pAudioDoc->Pause();
	}
	m_pAudioDoc->SetPosition(m_eDictationStartPos);
}

void CNavigatorBar::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_ESCAPE && m_pWaveBar)
	{
//		m_pWaveBar->EndDrag(FALSE);
	}
	else if(nChar == VK_F7 && m_bDictation && m_pAudioDoc)
	{
		SetRepeatA();
	}
	else if(nChar == VK_F8 && m_bDictation && m_pAudioDoc)
	{
		SetRepeatB();
	}
	CDialogBar::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CNavigatorBar::OnBnClickedCheckTrans()
{
	m_bDictation = !m_bDictation;
}

void CNavigatorBar::OnSliderChanged()
{
	if(!m_pAudioDoc)
		return;

	int nPos = m_aSliderProgress.GetPos();
	double eSetVal = nPos * m_pAudioDoc->GetDuration() / SLIDER_RANGE_MAX;
	SetCurrentPos(eSetVal);
}
