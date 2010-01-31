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
#define GRAPH_HEIGHT		60
#define GRAPH_HEIGHT_HALF	30
#define M_PI				3.14159265358979323846

//////////////////////////////////////////////////////////////////////////
void CWaveIndicator::OnDraw(CDC* pDC)
{
	if(!m_bVisible || m_pParent == NULL || pDC == NULL)
		return;

	RECT rect;
	m_pParent->GetClientRect(&rect);

	HPEN hRed = CreatePen(PS_SOLID, 1, RGB_RED);
	HPEN hOld = (HPEN)pDC->SelectObject(hRed);
	int centerX = (rect.left + rect.right) / 2;
	pDC->MoveTo(centerX, rect.top);
	pDC->LineTo(centerX, rect.bottom);
	pDC->SelectObject(hOld);

	pDC->SetTextColor(RGB_WHITE);
	pDC->SetBkMode(TRANSPARENT);
	CString strTimePos = CNavigatorBar::FormatTime(m_TimePos);

	//Fix me: Need to learn how to calculate the word length
	pDC->TextOut(centerX - 18, rect.top + 2, strTimePos);
}

double CWaveIndicator::GetTimePos()
{
	return m_TimePos;
}

void CWaveIndicator::SetTimePos(double pos)
{
	m_TimePos = pos;
}

void CWaveIndicator::SetVisible(BOOL bVis)
{
	m_bVisible = bVis;
}

//////////////////////////////////////////////////////////////////////////
CWaveGraph::CWaveGraph(CWaveBar* pParent)
:m_pParent(pParent)
{
	m_pGraphData = NULL;
	m_eDuration = 0;
	m_eCurrentPos = 0;
	m_nTotalCount = 0;
	m_bVisible = TRUE;

	float freqstep = float(4 * M_PI / PIXEL_PER_WINDOW);

	for(int i = 0; i < PIXEL_PER_WINDOW; i++)
	{
		m_BaseLine[i] = cos(freqstep * i);
	}
}

CWaveGraph::~CWaveGraph()
{
	if(m_pGraphData != NULL)
		delete [] m_pGraphData;
	m_pGraphData = NULL;
}

void CWaveGraph::SetDuration(double eDuration)
{
	if(m_pGraphData != NULL)
		delete [] m_pGraphData;
	m_pGraphData = NULL;

	m_eDuration = eDuration;
	m_nTotalCount = long(m_eDuration * WINDOW_COUNT);
	m_pGraphData = new SAMPLE_DATA[m_nTotalCount];
	memset(m_pGraphData, 0, m_nTotalCount * sizeof(SAMPLE_DATA));
	m_eCurrentPos = 0;
}

void CWaveGraph::SetData(double eTime, float* eValue, char nType)
{
	if(m_pGraphData == NULL)
	{
		TRACE("CWaveGraph::SetData, You need to set duration firstly.");
		ASSERT(FALSE);
		return;
	}

	long nPos = long(eTime * WINDOW_COUNT);
	if(nPos >= m_nTotalCount)
	{
		TRACE("CWaveGraph::SetData, pos = %d >= duration = %d!", nPos, m_nTotalCount);
//		ASSERT(FALSE);
		return;
	}

	m_pGraphData[nPos].nType = nType;
	memcpy(m_pGraphData[nPos].eValue, eValue, sizeof(m_pGraphData[nPos].eValue));
}

void CWaveGraph::SetPosition(double eCurrentPos)
{
	m_eCurrentPos = eCurrentPos;
}

void CWaveGraph::SetVisible(BOOL bVis)
{
	m_bVisible = bVis;
}

void CWaveGraph::OnDraw(CDC* pDC)
{
	if(!m_bVisible || pDC == NULL || m_pGraphData == NULL)
		return;

	RECT rect;
	m_pParent->GetClientRect(&rect);

	int nLineNums = (rect.right -rect.left) / PIXEL_PER_WINDOW;
	int nLeftPixel = rect.left;
	long nStart = long(m_eCurrentPos * WINDOW_COUNT) - nLineNums;
	if(nStart < 0)
	{
		nStart = 0;
	}
	if(nStart > m_nTotalCount - nLineNums)
		nStart = m_nTotalCount - nLineNums;

	HPEN hGreen = CreatePen(PS_SOLID, 1, RGB_GREEN);
	HPEN hOld = (HPEN)pDC->SelectObject(hGreen);
	pDC->MoveTo(nLeftPixel, int(m_pGraphData[nStart].eValue[0]));

	long i = 0, j = 0;
	for(i = nStart; i < nStart + nLineNums; i++)
	{
		for(j = 0; j < PIXEL_PER_WINDOW; j++)
		{
			pDC->LineTo(nLeftPixel++, int(m_pGraphData[i].eValue[j]));
		}
	}
	pDC->SelectObject(hOld);
}

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(CWaveBar, CWnd)

CWaveBar::CWaveBar(CNavigatorBar* pNav)
:m_pNavigatorBar(pNav),m_nUpdateCount(0)
{
	m_hBackgroundBitmap = NULL;
	m_bLMouseDown = FALSE;
	m_bDraging = FALSE;
	m_pWaveIndicator = new CWaveIndicator(this);
	m_pCurve = new CWaveGraph(this);
}

CWaveBar::~CWaveBar()
{
	if(m_pWaveIndicator)
		delete m_pWaveIndicator;
	if(m_pCurve)
		delete m_pCurve;
	m_pWaveIndicator = NULL;
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
	CPaintDC dc(this); // device context for painting

	m_bLMouseDown = TRUE;
	m_bDraging = TRUE;
	m_ptLastPoint = point;
	OnSetCursor(this, 0, 0);
	SetCapture();
	if(m_pWaveIndicator && m_pNavigatorBar)
	{
		if(m_pNavigatorBar->GetAudioDoc()->IsPlaying())
			m_pWaveIndicator->SetTimePos(m_pNavigatorBar->GetCurrentPos());
		m_pWaveIndicator->SetVisible(TRUE);
		Invalidate(FALSE);
	}

	CWnd::OnLButtonDown(nFlags, point);
}

void CWaveBar::EndDrag(BOOL bNormal)
{
	if(!m_bDraging)
		return;

	m_bLMouseDown = FALSE;
	m_bDraging = FALSE;
	m_ptLastPoint.x = 0;
	m_ptLastPoint.y = 0;
	OnSetCursor(this, 0, 0);
	ReleaseCapture();

	if(m_pWaveIndicator)
	{
		double ePos = m_pWaveIndicator->GetTimePos();
		m_pWaveIndicator->SetVisible(FALSE);
		if(m_pNavigatorBar && bNormal)
		{
			double eCurr = m_pNavigatorBar->GetCurrentPos();
			if(fabs(ePos - eCurr) > 0.05)
				m_pNavigatorBar->SetCurrentPos(ePos);
		}
		Invalidate(FALSE);
	}
}

void CWaveBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	EndDrag();
	CWnd::OnLButtonUp(nFlags, point);
}

void CWaveBar::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bLMouseDown)
	{
		int distance = point.x - m_ptLastPoint.x;
		if(distance != 0)
			OnDrag(distance);
		m_ptLastPoint = point;
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CWaveBar::OnTimer(UINT_PTR nIDEvent)
{
	CWnd::OnTimer(nIDEvent);
}

void CWaveBar::OnDrag(int nValue)
{
	if(m_pWaveIndicator == NULL)
		return;

	//We set the whole screen with 30s / 640 pixel.
	double eChange = m_pWaveIndicator->GetTimePos() + nValue * SECONDS_PER_PIXEL * 20;
	if(eChange > 0)
	{
		m_pWaveIndicator->SetTimePos(eChange);
		Invalidate(TRUE);
	}
}

BOOL CWaveBar::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if(m_bDraging)
		SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR_MOVE)));
	else
		SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR_PAN)));
	return TRUE;
}

void CWaveBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if(m_pWaveIndicator == NULL || m_pCurve == NULL || m_pNavigatorBar == NULL)
		return;

	m_pWaveIndicator->OnDraw(&dc);

	if(m_bDraging || !m_pNavigatorBar->GetAudioDoc()->IsPlaying())
	{
		if(m_pWaveIndicator)
			m_pCurve->SetPosition(m_pWaveIndicator->GetTimePos());
	}
	else
	{
		m_pCurve->SetPosition(m_pNavigatorBar->GetCurrentPos());
	}
	m_pCurve->OnDraw(&dc);
}

void CWaveBar::StartPlay(double duration)
{
	if(m_pCurve)
		m_pCurve->SetDuration(duration);
}

void CWaveBar::UpdateSoundData(double ePos, float* eVal, char nType)
{
	if(!m_bDraging && m_pCurve)
	{
		m_pCurve->SetData(ePos, eVal, nType);
		m_nUpdateCount++;
		if(m_nUpdateCount == 8)
		{
			m_nUpdateCount = 0;
			Invalidate(FALSE);
		}
	}
}
