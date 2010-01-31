#pragma once

// CBmpSlider

class CBmpSlider : public CStatic
{
	DECLARE_DYNAMIC(CBmpSlider)
public:
	CBmpSlider();
	virtual ~CBmpSlider();

public:
	void Init();
	int GetPos(void);
	void SetPos(int nPos);
	void SetAPoint(int nPos);
	void SetBPoint(int nPos);
	void SetRange(int nMin, int nMax);

protected:
	virtual void PreSubclassWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void DrawBK(CDC *pDC);
	BOOL NotifyPos(CPoint point);

protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	int m_nSliderIndex;			//滑块坐标(Min <= m_nSliderIndex <= Max)
	int m_nRangeMax;
	int m_nRangeMin;
	CDC m_progressLeftDC;		//左边进度条
	CDC m_progressRightDC;		//右边进度条
	CDC m_sliderNormalDC;		//正常状态的滑块
	CDC m_sliderPassDC;			//鼠标经过的滑过
	bool m_bSlidering;			//正在滑动滑块
	bool m_bPassSlider;			//鼠标是否在滑块上
	CSize m_bmpSize;			//图片尺寸
	int m_nAPos;
	int m_nBPos;
};
