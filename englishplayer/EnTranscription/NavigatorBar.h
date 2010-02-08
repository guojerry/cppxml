#pragma once

#include "AudioDoc.h"
#include "BmpSlider.h"

class CWaveBar;
// CNavigatorBar Dialog
class CNavigatorBar : public CDialogBar, public IAudioDocSink
{
	DECLARE_DYNAMIC(CNavigatorBar)

public:
	CNavigatorBar(CWnd* pParent = NULL); 
	virtual ~CNavigatorBar();
	enum { IDD = IDD_NAVIGATORBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	static CString FormatTime(double time);
	CAudioDoc* GetAudioDoc() {return m_pAudioDoc;}
	double GetCurrentPos();
	void SetCurrentPos(double pos);
	virtual void OnStatusChange();
	virtual void OnUpdateSoundData(double eTime, int nRelEnergy);

protected:
	void UpdateUIStatus();
	void UpdateVolume();
	void SetRepeatA();
	void SetRepeatB();

	HICON m_hPlayIcon;
	HICON m_hPauseIcon;
	HICON m_hStopIcon;
	HICON m_hOpenIcon;
	CAudioDoc* m_pAudioDoc;
	CWaveBar* m_pWaveBar;
	BOOL m_bDictation;
	double m_eDictationStartPos;
	double m_eDictationEndPos;
	int m_nTimerCount;
	CBmpSlider m_aSliderProgress;
	BOOL m_nSilCount;
	double m_dBreakPoint;

public:
	afx_msg void OnBnClickedBtnPlay();
	afx_msg LRESULT OnInitDialog(UINT wParam,LONG lParam);
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnSliderChanged();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVolumePosChanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedCheckTrans();
	afx_msg void OnBnClickedBtnContinue();
	afx_msg void OnBnClickedBtnRepeat();
	afx_msg void OnBnClickedBtnSlowrepeat();
};
