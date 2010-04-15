// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "NavigatorBar.h"
#include "MainFrm.h"
#include "EnTranscriptionDoc.h"
#include "EnTranscriptionView.h"
#include "shlwapi.h"
#include "LocaleTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
//	ON_WM_ERASEBKGND()
//	ON_WM_KEYDOWN()
	ON_COMMAND(ID_PLAY_PREVIOUS, &CMainFrame::OnPlayPrevious)
	ON_COMMAND(ID_PLAY_CONTINUE, &CMainFrame::OnPlayContinue)
	ON_COMMAND(ID_PLAY_REPEAT, &CMainFrame::OnPlayRepeat)
	ON_COMMAND(ID_PLAY_REPEATSLOWLY, &CMainFrame::OnPlayRepeatslowly)
	ON_COMMAND(ID_FILE_MY_SAVE_AS, &CMainFrame::OnFileMySaveAs)
	ON_COMMAND(ID_FILE_MY_SAVE, &CMainFrame::OnFileSave)
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

	CMenu* pMenu = GetMenu();
	if(CLocaleTool::Instance())
		CLocaleTool::Instance()->UpdateMenu(pMenu, MAIN_MENU_GROUP);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.cx = 800;
	cs.cy = 600;
	cs.style &= ~FWS_ADDTOTITLE;	//Prevent "no title" in the title bar

	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

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
	return CFrameWnd::PreTranslateMessage(pMsg);
}

BOOL CMainFrame::OpenMediaFile(LPCTSTR lpszPath)
{
	TCHAR szAppTitle[MAX_PATH] = {0};
	LoadString(AfxGetInstanceHandle(), AFX_IDS_APP_TITLE, szAppTitle, MAX_PATH);
	TCHAR* sFileName = PathFindFileName(lpszPath);
	CString sTitle;
	sTitle.Format(_T("%s - %s"), sFileName, szAppTitle);
	SetWindowText(sTitle);

	if(lpszPath == NULL)
		return FALSE;
	
	if(m_wndNavigator.GetPlayingFileName().CompareNoCase(lpszPath) == 0)
		return TRUE;

	BOOL bRet = m_wndNavigator.OpenMediaFile(lpszPath);
	CEnTranscriptionView* pView = dynamic_cast<CEnTranscriptionView*>(GetActiveView());
	if(pView)
	{
		pView->OpenTranscription(lpszPath);
	}
	return bRet;
}

void CMainFrame::ShowTutorial()
{
	CEnTranscriptionView* pView = dynamic_cast<CEnTranscriptionView*>(GetActiveView());
	if(pView)
		pView->ShowTutorial();
}

void CMainFrame::OnPlayPrevious()
{
	m_wndNavigator.OnBnClickedBtnPrevious();
}

void CMainFrame::OnPlayContinue()
{
	if(m_wndNavigator.IsDictation())
	{
		CEnTranscriptionView* pView = dynamic_cast<CEnTranscriptionView*>(GetActiveView());
		if(pView)
			pView->SetTimeMarker(m_wndNavigator.GetCurrentPos());
	}

	m_wndNavigator.OnBnClickedBtnContinue();
}

void CMainFrame::SeekTo(double eTime)
{
	m_wndNavigator.SeekTo(eTime);
}

void CMainFrame::HightLightCurrent(double eTime)
{
	CEnTranscriptionView* pView = dynamic_cast<CEnTranscriptionView*>(GetActiveView());
	if(pView)
		pView->HightLightCurrent(eTime);
}

void CMainFrame::OnPlayRepeat()
{
	m_wndNavigator.OnBnClickedBtnRepeat();
}

void CMainFrame::OnPlayRepeatslowly()
{
	m_wndNavigator.OnBnClickedBtnSlowrepeat();
}

void CMainFrame::OnFileMySaveAs()
{
	CEnTranscriptionView* pView = dynamic_cast<CEnTranscriptionView*>(GetActiveView());
	if(pView)
		pView->SaveAs(NULL);
}

void CMainFrame::OnFileSave()
{
	CEnTranscriptionDoc* pDoc = dynamic_cast<CEnTranscriptionDoc*>(GetActiveDocument());
	if(pDoc)
		pDoc->OnSaveDocument(pDoc->GetPathName());
}

CString CMainFrame::GetLocaleName()
{
	TCHAR szLocaleName[MAX_PATH] = {0};
	GetLocaleInfo(LOCALE_USER_DEFAULT , LOCALE_SNAME, szLocaleName, MAX_PATH);

	return szLocaleName;
}