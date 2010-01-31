#pragma once

class CWaveIndicator;
class CNavigatorBar;
class CWaveGraph;

// CWaveBar
class CWaveBar : public CWnd
{
	DECLARE_DYNAMIC(CWaveBar)

public:
	CWaveBar(CNavigatorBar* pNav);
	virtual ~CWaveBar();

protected:
	DECLARE_MESSAGE_MAP()

private:
	HBITMAP m_hBackgroundBitmap;
	BOOL m_bLMouseDown;
	BOOL m_bDraging;
	CPoint m_ptLastPoint;
	CNavigatorBar* m_pNavigatorBar;
	CWaveGraph* m_pCurve;
	int m_nUpdateCount;
	float m_waveform[FFT_LEN];

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
};

enum
{
	eTypeNormal,
	eTypeSentenceEnd,
	eTypeParagraphEnd,
};

class CWaveGraph
{
public:
	CWaveGraph(CWaveBar* pParent);
	virtual ~CWaveGraph();

public:
	void DrawWaveform(CDC* pDC, float* pDataIn, int nLen);
	void SetVisible(BOOL bVis);

private:
	BOOL m_bVisible;
	CWaveBar* m_pParent;
};
