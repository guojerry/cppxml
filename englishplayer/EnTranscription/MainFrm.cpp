// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "NavigatorBar.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
//	ON_WM_ERASEBKGND()
//ON_WM_KEYDOWN()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndNavigator.Create(this, IDD_NAVIGATORBAR, WS_VISIBLE | WS_CHILD | CBRS_SIZE_FIXED
		| CBRS_TOP, IDD_NAVIGATORBAR))
	{
		TRACE0("Failed to create navigator bar\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.cx = 800;
	cs.cy = 600;
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

// CMainFrame message handlers

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	if(m_wndNavigator.OnCmdMsg(nID,nCode,pExtra,pHandlerInfo))
		return TRUE;

	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg && pMsg->message == WM_KEYDOWN)
	{
		if( pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_F7 || 
			pMsg->wParam == VK_F8 || pMsg->wParam == VK_F9 || pMsg->wParam == VK_F6)
		{
			if(m_wndNavigator.SendMessage(WM_KEYDOWN, pMsg->wParam, 0))
				return TRUE;
		}
	}

	return CFrameWnd::PreTranslateMessage(pMsg);
}
