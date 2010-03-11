// EnTranscriptionView.cpp : implementation of the CEnTranscriptionView class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "RichEditThemed.h"
#include "EnTranscriptionDoc.h"
#include "EnTranscriptionView.h"
#include "shlwapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TUTORIAL_FILENAME		_T("tutorial.htm")
#define TEMPLATE_FILENAME		_T("template.htm")

// CEnTranscriptionView

IMPLEMENT_DYNCREATE(CEnTranscriptionView, CHtmlEditView)

BEGIN_MESSAGE_MAP(CEnTranscriptionView, CHtmlEditView)
	// Standard printing commands
//	ON_COMMAND(ID_FILE_PRINT, &CHtmlEditView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CHtmlEditView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHtmlEditView::OnFilePrintPreview)
END_MESSAGE_MAP()
BEGIN_DHTMLEDITING_CMDMAP(CEnTranscriptionView)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_CUT, IDM_CUT)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_COPY, IDM_COPY)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_PASTE, IDM_PASTE)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_UNDO, IDM_UNDO)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_SELECT_ALL, IDM_SELECTALL)
	DHTMLEDITING_CMD_ENTRY(ID_BUTTON_HYPERLINK, IDM_HYPERLINK)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_BUTTON_BOLD, IDM_BOLD, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_BUTTON_ITALIC, IDM_ITALIC, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_BUTTON_UNDERLINE, IDM_UNDERLINE, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY(ID_BUTTON_FONT, IDM_FONT)
	DHTMLEDITING_CMD_ENTRY_FUNC(ID_BUTTON_COLOR, IDM_FONT, &CEnTranscriptionView::OnButtonColor)
	DHTMLEDITING_CMD_ENTRY_FUNC(ID_BUTTON_HIGHLIGHT, IDM_FONT, &CEnTranscriptionView::OnButtonHighLight)
END_DHTMLEDITING_CMDMAP()

// CEnTranscriptionView construction/destruction

CEnTranscriptionView::CEnTranscriptionView()
{
	// TODO: add construction code here
}

CEnTranscriptionView::~CEnTranscriptionView()
{
}

BOOL CEnTranscriptionView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CHtmlEditView::PreCreateWindow(cs);
//	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping
//	cs.style |= ES_SELECTIONBAR;

	return bPreCreated;
}

void CEnTranscriptionView::OnInitialUpdate()
{
	CString strCmdLine(AfxGetApp()->m_lpCmdLine);
	if(strCmdLine.IsEmpty())
	{
		TCHAR szFilePath[MAX_PATH] = {0};
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		PathRemoveFileSpec(szFilePath);
		PathAppend(szFilePath, TUTORIAL_FILENAME);
		strCmdLine = _T("file:///");
		strCmdLine += szFilePath;
	}
	else
	{
	}
	Navigate(strCmdLine);
	CHtmlEditView::OnInitialUpdate();
}

void CEnTranscriptionView::OnNavigateComplete2(LPCTSTR strURL)
{
	CString sURL(strURL);
	if(sURL.FindOneOf(TUTORIAL_FILENAME) > 0)
		SetDesignMode(TRUE);
	else
		SetDesignMode(TRUE);
}

UINT_PTR CALLBACK CdlgHook(  HWND hdlg,UINT uiMsg,WPARAM /*wParam*/, LPARAM lParam)
{
	if(uiMsg == WM_INITDIALOG)
	{
		SetWindowText(hdlg, _T("Choose a Foreground Color"));
	}
	return 0;
}

void CEnTranscriptionView::OnButtonHighLight(UINT)
{
	SetForeColor(_T("3d85c6"));
	SetBackColor(_T("ffe599"));
	SetFontSize(4);
	Italic();
	Bold();
}

void CEnTranscriptionView::OnButtonColor(UINT)
{
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_ENABLEHOOK;
	dlg.m_cc.lpfnHook = CdlgHook;
	dlg.m_cc.lCustData = NULL;

	if(dlg.DoModal()==IDOK)
	{
		CString szColor;
		COLORREF cr = dlg.GetColor();

		//change the COLORREF into an RGB.
		szColor.Format(_T("%.2x%.2x%.2x"),GetRValue(cr),GetGValue(cr),GetBValue(cr));
		SetForeColor(szColor);
	}
}

HRESULT CEnTranscriptionView::OnShowContextMenu(DWORD dwID,
												LPPOINT ppt,
												LPUNKNOWN pcmdtReserved,
												LPDISPATCH pdispReserved)
{
	CMenu pMenuMain;
	pMenuMain.LoadMenu(MAKEINTRESOURCE(IDR_TEXT_POPUP));
	CMenu *pPopup = pMenuMain.GetSubMenu(0);

	// enable/disable items based on the status of the command
	UINT nCount = pPopup->GetMenuItemCount();
	for (UINT i = 0; i<nCount; i++)
	{
		int nID = (int)pPopup->GetMenuItemID(i);
		if (nID != 0 && nID != -1)
		{
			BOOL bHasFunc;
			UINT uiElemType;
			UINT dhtmlCmdID = GetDHtmlCommandMapping(nID, bHasFunc, uiElemType);
			long nStatus = QueryStatus(dhtmlCmdID);
			if (!(nStatus & OLECMDF_ENABLED))
			{
				pPopup->EnableMenuItem(nID, MF_DISABLED|MF_GRAYED);
			}
			else
				pPopup->EnableMenuItem(nID, MF_ENABLED);
		}
	}
	pPopup->TrackPopupMenu(TPM_LEFTALIGN, ppt->x, ppt->y, this);
	return S_OK;
}

// CEnTranscriptionView printing
BOOL CEnTranscriptionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CHtmlEditView::OnPreparePrinting(pInfo);
}

void CEnTranscriptionView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CHtmlEditView::OnBeginPrinting(pDC, pInfo);
}

void CEnTranscriptionView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CHtmlEditView::OnEndPrinting(pDC, pInfo);
}

// CEnTranscriptionView diagnostics

#ifdef _DEBUG
void CEnTranscriptionView::AssertValid() const
{
	CHtmlEditView::AssertValid();
}

void CEnTranscriptionView::Dump(CDumpContext& dc) const
{
	CHtmlEditView::Dump(dc);
}

CEnTranscriptionDoc* CEnTranscriptionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnTranscriptionDoc)));
	return (CEnTranscriptionDoc*)m_pDocument;
}
#endif //_DEBUG


// CEnTranscriptionView message handlers
