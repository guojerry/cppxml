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

public:
	virtual void OnDrag(int nValue);
	virtual void EndDrag(BOOL bNormal = TRUE);
	void StartPlay(double duration);
	void UpdateSoundData(double ePos, float* eVal, char nType);

protected:
	DECLARE_MESSAGE_MAP()

private:
	HBITMAP m_hBackgroundBitmap;
	BOOL m_bLMouseDown;
	BOOL m_bDraging;
	CPoint m_ptLastPoint;
	CWaveIndicator* m_pWaveIndicator;
	CNavigatorBar* m_pNavigatorBar;
	CWaveGraph* m_pCurve;
	int m_nUpdateCount;

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

class CWaveIndicator
{
public:
	CWaveIndicator(CWaveBar* pParent)
		:m_pParent(pParent),m_TimePos(0), m_bVisible(FALSE) {}
	virtual ~CWaveIndicator() {}

public:
	void SetVisible(BOOL bVis);
	void SetTimePos(double pos);
	double GetTimePos();
	void OnDraw(CDC* pDC);

private:
	double m_TimePos;
	CWaveBar* m_pParent;
	BOOL m_bVisible;
};

enum
{
	eTypeNormal,
	eTypeSentenceEnd,
	eTypeParagraphEnd,
};

#pragma pack(1)
typedef struct tagSampleData
{
	float eValue[PIXEL_PER_WINDOW];
	char nType;
}SAMPLE_DATA, *LPSAMPLE_DATA;
#pragma pack()

class CWaveGraph
{
public:
	CWaveGraph(CWaveBar* pParent);
	virtual ~CWaveGraph();

public:
	void SetDuration(double eDuration);
	void SetPosition(double eCurrentPos);
	void SetData(double eTime, float* eValue, char nType = eTypeNormal);
	void OnDraw(CDC* pDC);
	void SetVisible(BOOL bVis);

private:
	LPSAMPLE_DATA m_pGraphData;
	float m_BaseLine[PIXEL_PER_WINDOW];
	double m_eDuration;
	double m_eCurrentPos;
	long m_nTotalCount;
	BOOL m_bVisible;
	CWaveBar* m_pParent;
};
