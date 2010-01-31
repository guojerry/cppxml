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
	int m_nSliderIndex;			//��������(Min <= m_nSliderIndex <= Max)
	int m_nRangeMax;
	int m_nRangeMin;
	CDC m_progressLeftDC;		//��߽�����
	CDC m_progressRightDC;		//�ұ߽�����
	CDC m_sliderNormalDC;		//����״̬�Ļ���
	CDC m_sliderPassDC;			//��꾭���Ļ���
	bool m_bSlidering;			//���ڻ�������
	bool m_bPassSlider;			//����Ƿ��ڻ�����
	CSize m_bmpSize;			//ͼƬ�ߴ�
	int m_nAPos;
	int m_nBPos;
};
