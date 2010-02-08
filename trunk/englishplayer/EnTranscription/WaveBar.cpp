// WaveBar.cpp : 实现文件
//

#include "stdafx.h"
#include "AudioDoc.h"
#include "EnTranscription.h"
#include "WaveBar.h"
#include "NavigatorBar.h"
#include "math.h"

#define RGB_RED				RGB(255,0,0)
#define RGB_WHITE			RGB(255,255,255)
#define RGB_GREEN			RGB(152,208,31)

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CWaveBar, CWnd)

CWaveBar::CWaveBar(CNavigatorBar* pNav)
:m_pNavigatorBar(pNav),m_nUpdateCount(0)
{
	m_hBackgroundBitmap = NULL;
	m_bLMouseDown = FALSE;
	m_bDraging = FALSE;
	m_pCurve = new CWaveGraph(this);
}

CWaveBar::~CWaveBar()
{
	if(m_pCurve)
		delete m_pCurve;
}

BEGIN_MESSAGE_MAP(CWaveBar, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL CWaveBar::OnEraseBkgnd(CDC* pDC)
{
	if(m_hBackgroundBitmap != NULL)
	{
		CRect r;
		GetClientRect(&r);

		CDC dcBmp;
		dcBmp.CreateCompatibleDC(pDC);
		dcBmp.SelectObject(m_hBackgroundBitmap);

		BITMAP bm; 
		GetObject(m_hBackgroundBitmap, sizeof(BITMAP), (PSTR)&bm); 
		int bx=bm.bmWidth;
		int by=bm.bmHeight;

		pDC->StretchBlt(r.left, r.top, r.right, r.bottom, &dcBmp, 0, 0, bx, by, SRCCOPY);
	}
	return CWnd::OnEraseBkgnd(pDC);
}

int CWaveBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_hBackgroundBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_WAVEBK), IMAGE_BITMAP,
		0, 0, LR_DEFAULTCOLOR);
	return 0;
}

void CWaveBar::OnDestroy()
{
	CWnd::OnDestroy();

	if(m_hBackgroundBitmap)
	{
		DeleteObject(m_hBackgroundBitmap);
		m_hBackgroundBitmap = NULL;
	}
}

void CWaveBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);
}

void CWaveBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonUp(nFlags, point);
}

void CWaveBar::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd::OnMouseMove(nFlags, point);
}

void CWaveBar::OnTimer(UINT_PTR nIDEvent)
{
	CWnd::OnTimer(nIDEvent);
}

BOOL CWaveBar::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	return TRUE;
}

void CWaveBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if(m_pCurve == NULL || m_pNavigatorBar == NULL)
		return;

	CAudioDoc* pAudioDoc = m_pNavigatorBar->GetAudioDoc();
	if(pAudioDoc != NULL)
	{
		int nLen = FFT_LEN;
		pAudioDoc->GetDrawData(CAudioDoc::eDrawWaveform, m_waveform, nLen);
		m_pCurve->DrawWaveform(&dc, m_waveform, nLen);
	}
}

//////////////////////////////////////////////////////////////////////////
CWaveGraph::CWaveGraph(CWaveBar* pParent)
:m_pParent(pParent)
{
	m_bVisible = TRUE;
}

CWaveGraph::~CWaveGraph()
{
}

void CWaveGraph::SetVisible(BOOL bVis)
{
	m_bVisible = bVis;
}
#include <math.h>
void CWaveGraph::DrawWaveform(CDC* pDC, float* pDataIn, int nLen)
{
	if(!m_bVisible || pDC == NULL || pDataIn == NULL || nLen == 0)
		return;

	RECT rect;
	m_pParent->GetClientRect(&rect);

	double nScaleY = (rect.bottom - rect.top) / 32768.0;
	int nMiddle = (rect.bottom + rect.top) / 2;

	HPEN hGreen = CreatePen(PS_SOLID, 2, RGB_GREEN);
	HPEN hOld = (HPEN)pDC->SelectObject(hGreen);
	int nY = int(nMiddle + pDataIn[0] * nScaleY);
	pDC->MoveTo(rect.left, nY);

	long i = 0;
	for(i = 0; i < nLen; i++)
	{
		nY = int(nMiddle + pDataIn[i] * nScaleY);
		pDC->LineTo(rect.left + i, nY);
	}
	pDC->SelectObject(hOld);
}
