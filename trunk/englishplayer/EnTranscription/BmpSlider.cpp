// BmpSlider.cpp : 实现文件
//
#include "stdafx.h"
#include "BmpSlider.h"

IMPLEMENT_DYNAMIC(CBmpSlider, CStatic)

BEGIN_MESSAGE_MAP(CBmpSlider, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

//RGB(239,236,231)

//////////////////////////////////////////////////////////////////////////
// CBmpSlider
//////////////////////////////////////////////////////////////////////////
CBmpSlider::CBmpSlider()
{
	m_nSliderIndex = 0;
	m_bSlidering = false;
	m_bPassSlider = false;
	m_nAPos = -1;
	m_nBPos = -1;
	m_nRangeMin = 0;
	m_nRangeMax = 100;
}

CBmpSlider::~CBmpSlider()
{
}

void CBmpSlider::SetRange(int nMin, int nMax)
{
	ASSERT(nMax > nMin);
	m_nRangeMax = nMax;
	m_nRangeMin = nMin;
}

void CBmpSlider::Init()
{
	m_bmpSize = CSize(90, 10);

	CDC *pDC = GetDC();
	m_progressLeftDC.CreateCompatibleDC(pDC);
	m_progressRightDC.CreateCompatibleDC(pDC);
	m_sliderNormalDC.CreateCompatibleDC(pDC);
	m_sliderPassDC.CreateCompatibleDC(pDC);
	ReleaseDC(pDC); 

	HBITMAP hProgressLeftBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BAR_LEFT));
	m_progressLeftDC.SelectObject(hProgressLeftBmp);

	HBITMAP hProgressRightBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BAR_RIGHT));
	m_progressRightDC.SelectObject(hProgressRightBmp);

	HBITMAP hSliderNormalBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_KNOB_NORMAL));
	m_sliderNormalDC.SelectObject(hSliderNormalBmp);

	HBITMAP hSliderPassBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_KNOB_PRESSED));
	m_sliderPassDC.SelectObject(hSliderPassBmp);
}

void CBmpSlider::OnPaint()
{
	CPaintDC dc(this);
	DrawBK(&dc);
}

BOOL CBmpSlider::OnEraseBkgnd(CDC* pDC)
{
	return true;
}

void CBmpSlider::DrawBK(CDC *pDC)
{
	CRect wndRect;
	GetClientRect(wndRect);
	
	CBitmap panleBmp;
	CDC panleDC;
	panleDC.CreateCompatibleDC(pDC);
	panleBmp.CreateCompatibleBitmap(pDC, wndRect.Width(), wndRect.Height());
	panleDC.SelectObject(panleBmp);

	int height = wndRect.Height();
	int width = wndRect.Width();
	//Draw background, and do the stretch separately for left, center and right, or the edge is ugly.
	panleDC.StretchBlt(0, 0, 10, height, &m_progressRightDC, 0, 0, 10, m_bmpSize.cy, SRCCOPY);
	panleDC.StretchBlt(10, 0, width - 10, height, &m_progressRightDC, 10, 0, m_bmpSize.cx - 20, m_bmpSize.cy, SRCCOPY);
	panleDC.StretchBlt(width - 10, 0, 10, height, &m_progressRightDC, m_bmpSize.cx - 10, 0, 10, m_bmpSize.cy, SRCCOPY);

	int nWidth = m_bmpSize.cx * (m_nSliderIndex - m_nRangeMin) / (m_nRangeMax - m_nRangeMin);
	int nSliderPos = width * (m_nSliderIndex - m_nRangeMin) / (m_nRangeMax - m_nRangeMin);
	int nLeft = nSliderPos < 10 ? nSliderPos : 10;
	int nRemain = nSliderPos - nLeft;
	panleDC.StretchBlt(0, 0, nLeft, height, &m_progressLeftDC, 0, 0, nLeft, m_bmpSize.cy, SRCCOPY);
	if(nRemain > 0)
		panleDC.StretchBlt(nLeft, 0, nRemain, height, &m_progressLeftDC, nLeft, 0, m_bmpSize.cx - 20, m_bmpSize.cy, SRCCOPY);

	int nRepeatA = (m_nAPos - m_nRangeMin) * width / (m_nRangeMax - m_nRangeMin);
	int nRepeatY = 3 * height / m_bmpSize.cy;
	CBrush blackBrush(RGB(128,128,128));
	HGDIOBJ hOld = panleDC.SelectObject(&blackBrush);
	if(m_nBPos == 0 && m_nAPos >= 0)
	{
		panleDC.Rectangle(nRepeatA, 0, nRepeatA + 2, nRepeatY);
	}
	else if(m_nBPos > m_nAPos && m_nAPos >= 0)
	{
		int nRepeatB = (m_nBPos - m_nRangeMin) * width / (m_nRangeMax - m_nRangeMin);
		panleDC.Rectangle(nRepeatA, 0, nRepeatB, nRepeatY);
	}
	panleDC.SelectObject(hOld);

	//Draw the slider now
	int nMargin = (height - 10) / 2;

	CDC* pSrcKnob = m_bPassSlider ? &m_sliderPassDC : &m_sliderNormalDC;
	if (nSliderPos + 10 > width)
	{
		panleDC.TransparentBlt(width - 10, nMargin, 10, 10, pSrcKnob, 0, 0, 10, 10, RGB(0,255,0));
	}
	else
	{
		panleDC.TransparentBlt(nSliderPos, nMargin, 10, 10, pSrcKnob, 0, 0, 10, 10, RGB(0,255,0));
	}

	//Draw out
	pDC->BitBlt(0, 0, width, height, &panleDC, 0, 0, SRCCOPY);
}

BOOL CBmpSlider::NotifyPos(CPoint point)
{
	CRect wndRect;
	GetClientRect(wndRect);

	int nNewPos = point.x * (m_nRangeMax - m_nRangeMin)/ wndRect.Width() + m_nRangeMin;
	if(nNewPos < m_nRangeMin || nNewPos > m_nRangeMax || nNewPos == m_nSliderIndex)
		return FALSE;

	m_nSliderIndex = nNewPos;
	::SendMessage(GetParent()->m_hWnd, WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), STN_CLICKED), (LPARAM)m_hWnd);

	return TRUE;
}

void CBmpSlider::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(!m_bSlidering)
		return;

	ReleaseCapture();
	
	Invalidate();
	m_bSlidering = false;
	NotifyPos(point);
}

void CBmpSlider::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect wndRect;
	GetClientRect(wndRect);
	BOOL bNeedInvalidate = FALSE;
	if(!m_bPassSlider)
		bNeedInvalidate = TRUE;

	m_bPassSlider = true;
	if (m_bSlidering)//如果是拖拽鼠标
		bNeedInvalidate = NotifyPos(point);

	if(bNeedInvalidate)
		Invalidate();

	TRACKMOUSEEVENT ET;
	ET.cbSize=sizeof(TRACKMOUSEEVENT);   
	ET.dwFlags=TME_LEAVE;   
	ET.dwHoverTime=NULL;   
	ET.hwndTrack=this->m_hWnd;  
	_TrackMouseEvent(&ET);
}

void CBmpSlider::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	m_bSlidering = true;
}

BOOL CBmpSlider::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_MOUSELEAVE)
	{
		m_bSlidering = false;
		m_bPassSlider = false;
		this->Invalidate();
	}
	return CStatic::PreTranslateMessage(pMsg);
}

int CBmpSlider::GetPos(void)
{
	return m_nSliderIndex;
}

void CBmpSlider::PreSubclassWindow()
{
	ModifyStyle(0, SS_NOTIFY);
	CStatic::PreSubclassWindow();
}

void CBmpSlider::SetPos(int nPos)
{
	m_nSliderIndex = nPos;
	Invalidate();
}

void CBmpSlider::SetAPoint(int nPos)
{
	m_nAPos = nPos;
	Invalidate();
}

void CBmpSlider::SetBPoint(int nPos)
{
	m_nBPos = nPos;
	Invalidate();
}