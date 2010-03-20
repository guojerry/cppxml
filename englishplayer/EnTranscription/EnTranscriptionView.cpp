// EnTranscriptionView.cpp : implementation of the CEnTranscriptionView class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "EnTranscriptionDoc.h"
#include "EnTranscriptionView.h"
#include "shlwapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CALLCOM(x)	if(FAILED(x)) return;

// CEnTranscriptionView
IMPLEMENT_DYNCREATE(CEnTranscriptionView, CHtmlEditView)

BEGIN_MESSAGE_MAP(CEnTranscriptionView, CHtmlEditView)
	ON_WM_CREATE()
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
	m_eStartPos = 0;
	m_eEndPos = 0;
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

void CEnTranscriptionView::OpenTranscription(const CString& sFilePath)
{
	if(sFilePath.IsEmpty())
		return;

	TCHAR szFilePath[MAX_PATH] = {0};
	_tcscpy_s(szFilePath, MAX_PATH, (LPCTSTR)sFilePath);
	CString strCmdLine;
	CString sFileName = PathFindFileName(szFilePath);
	PathRemoveFileSpec(szFilePath);
	PathAppend(szFilePath, HIDDEN_SCRIPT_DIR);
	if(!PathIsDirectory(szFilePath))
	{
		CreateDirectory(szFilePath, NULL);
		SetFileAttributes(szFilePath, FILE_ATTRIBUTE_HIDDEN);
	}
	else
	{
		sFileName += _T(".htm");
		PathAppend(szFilePath, sFileName);
		if(PathFileExists(szFilePath))
		{
			strCmdLine = _T("file:///");
			strCmdLine += szFilePath;
		}
	}
	if(strCmdLine.IsEmpty())
	{
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		PathRemoveFileSpec(szFilePath);
		PathAppend(szFilePath, TEMPLATE_FILENAME);
		strCmdLine = _T("file:///");
		strCmdLine += szFilePath;
	}
	NewDocument();
	Navigate(strCmdLine);
}

void CEnTranscriptionView::ShowTutorial()
{
	TCHAR szFilePath[MAX_PATH] = {0};

	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	PathRemoveFileSpec(szFilePath);
	PathAppend(szFilePath, TUTORIAL_FILENAME);
	CString strCmdLine = _T("file:///");
	strCmdLine += szFilePath;

	Navigate(strCmdLine);
}

void CEnTranscriptionView::SetTimeMarker(double eTime)
{
	CComPtr<IHTMLDocument2> pDocPtr;
	GetDHtmlDocument(&pDocPtr);
	if(pDocPtr == NULL)
		return;
	HRESULT hr = E_FAIL;

	CString sTimeBookMark;
	sTimeBookMark.Format(_T("t_%.0f"), eTime*1000);

	CComPtr<IHTMLSelectionObject> pSelObjPtr;
	CComPtr<IDispatch> pTmp;
	CComPtr<IHTMLTxtRange> pCurSelPtr;
	if(pDocPtr)
		pDocPtr->get_selection(&pSelObjPtr);

	if(pSelObjPtr != NULL)
		hr = pSelObjPtr->createRange(&pTmp);

	if(pTmp == NULL)
		return;

	pTmp->QueryInterface(IID_IHTMLTxtRange, (LPVOID*)&pCurSelPtr);
	if(pCurSelPtr == NULL)
		return;

	CComPtr<IHTMLElement> pElePtr;
	CComPtr<IHTMLBodyElement> pBodyPtr;
	CALLCOM(pDocPtr->get_body(&pElePtr));
	CALLCOM(pElePtr->QueryInterface(IID_IHTMLBodyElement, (void**)&pBodyPtr));
	CComPtr<IHTMLDOMNode> pBodyDomPtr;
	CALLCOM(pBodyPtr->QueryInterface(IID_IHTMLDOMNode, (void**)&pBodyDomPtr));

	long nMoved = 0;
	hr = pCurSelPtr->moveStart(_T("character"), -10000000, &nMoved);
	BSTR bstrTxt;
	pCurSelPtr->get_text(&bstrTxt);
	long nUpperLen = _tcslen(bstrTxt);
	SysFreeString(bstrTxt);
	pCurSelPtr->collapse(FALSE);

	CDomExplore aDom(nUpperLen);
	aDom.FindTimePos(pBodyDomPtr);
	double eNextTime = aDom.GetNextTimerPos();
	if(eTime > eNextTime)
		return;

	long nEmpty = 0;
	while(1)
	{
		hr = pCurSelPtr->moveStart(_T("character"), -1, &nMoved);
		if(FAILED(hr) || nMoved != -1)
			break;
		nEmpty -= 1;
		BSTR bstrTxt = NULL;
		hr = pCurSelPtr->get_text(&bstrTxt);
		TCHAR sEmpty = _T('');
		TCHAR sBlank = _T(' ');
		if(bstrTxt != NULL && bstrTxt[0] != _T(' '))
		{
			SysFreeString(bstrTxt);
			break;
		}
	}
	pCurSelPtr->collapse(TRUE);

	CString sAnchor;
	sAnchor.Format(_T("<a id='%s' name='%s'></a>"), sTimeBookMark, sTimeBookMark);
	BSTR bstrTmp = sAnchor.AllocSysString();
	hr = pCurSelPtr->pasteHTML(bstrTmp);
	SysFreeString(bstrTmp);

	pCurSelPtr->move(_T("character"), -nEmpty, &nMoved);
}

void CEnTranscriptionView::HightLightCurrent(double eTime)
{
	if(eTime <= m_eEndPos && eTime >= m_eStartPos)
		return;

	CComPtr<IHTMLDocument2> pDocPtr;
	GetDHtmlDocument(&pDocPtr);
	if(pDocPtr == NULL)
		return;
	CComPtr<IHTMLElement> pElePtr;
	CComPtr<IHTMLBodyElement> pBodyPtr;
	CALLCOM(pDocPtr->get_body(&pElePtr));
	CALLCOM(pElePtr->QueryInterface(IID_IHTMLBodyElement, (void**)&pBodyPtr));
	CComPtr<IHTMLDOMNode> pBodyDomPtr;
	CALLCOM(pBodyPtr->QueryInterface(IID_IHTMLDOMNode, (void**)&pBodyDomPtr));

	CDomExplore aDom(eTime);
	aDom.FindTimePos(pBodyDomPtr);
	m_eEndPos = aDom.GetEndPos();
	m_eStartPos = aDom.GetStartPos();

	TRACE("CEnTranscriptionView::HightLightCurrent, %f, %f - %f\r\n", eTime, m_eStartPos, m_eEndPos);
	if(m_eStartPos < 0 && m_eEndPos > 99999.0)
	{
		m_eStartPos = 0;
		m_eEndPos = 0;
	}

	long lEndChars = aDom.GetEndChars();
	long lStartChars = aDom.GetStartChars();
	long lTotalChars = aDom.GetTotalChars();
	if(lEndChars < lStartChars)
		lEndChars = lTotalChars;

	CComPtr<IHTMLTxtRange> pBodySelPtr;
	CALLCOM(pBodyPtr->createTextRange(&pBodySelPtr));
	pBodySelPtr->collapse(TRUE);
	long lOut = 0;
	HRESULT hr = pBodySelPtr->moveStart(_T("character"), lStartChars, &lOut);
	hr = pBodySelPtr->moveEnd(_T("character"), lEndChars - lStartChars, &lOut);
	pBodySelPtr->select();
}

CDomExplore::CDomExplore(double eTime)
:m_eTime(eTime),
m_lStartChars(0),
m_lEndChars(0),
m_lTotalChars(0),
m_eStartPos(-1.0),
m_eEndPos(100000.0),
m_eNextTime(0),
m_lCurrentChars(0),
m_bFindNextMode(FALSE)
{
}

CDomExplore::CDomExplore(long lCurrChars)
:m_eTime(0),
m_lStartChars(0),
m_lEndChars(0),
m_lTotalChars(0),
m_eStartPos(0),
m_eEndPos(0),
m_eNextTime(100000.0),
m_lCurrentChars(lCurrChars),
m_bFindNextMode(TRUE)
{
}

void CDomExplore::FindTimePos(IHTMLDOMNode* pNode)
{
	if(pNode == NULL)
		return;

	BSTR bstrNodeName;
	pNode->get_nodeName(&bstrNodeName);
	CString sNodeName(bstrNodeName);
	SysFreeString(bstrNodeName);

	if(sNodeName.CompareNoCase(_T("A")) == 0)
	{
		VARIANT vtName;
		CComPtr<IDispatch> pDispatchPtr;
		CComPtr<IHTMLAttributeCollection> pAttrCollectPtr;
		CComPtr<IHTMLDOMAttribute> pAttrPtr;
		pNode->get_attributes(&pDispatchPtr);
		if(pDispatchPtr != NULL)
			pDispatchPtr->QueryInterface(IID_IHTMLAttributeCollection, (void**)&pAttrCollectPtr);
		pDispatchPtr = NULL;
		if(pAttrCollectPtr != NULL)
		{
			vtName.vt = VT_BSTR;
			vtName.bstrVal = SysAllocString(_T("id"));
			HRESULT hr = pAttrCollectPtr->item(&vtName, &pDispatchPtr);
			SysFreeString(vtName.bstrVal);

			if(pDispatchPtr != NULL)
				pDispatchPtr->QueryInterface(IID_IHTMLDOMAttribute, (void**)&pAttrPtr);

			vtName.bstrVal = NULL;
			if(pAttrPtr != NULL)
				pAttrPtr->get_nodeValue(&vtName);
		}
		if(vtName.bstrVal != NULL)
		{
			CString sID(vtName.bstrVal);
			SysFreeString(vtName.bstrVal);
			if(sID.Left(2) == _T("t_"))
			{
				long lTimeTmp = _ttol(sID.Mid(2));
				double eTimeTmp = lTimeTmp / 1000.0;
				if(m_bFindNextMode)
				{
					if(m_lCurrentChars < m_lTotalChars && eTimeTmp < m_eNextTime)
					{
						m_eNextTime = eTimeTmp;
					}
				}
				else
				{
					if(m_eTime <= eTimeTmp && eTimeTmp < m_eEndPos)
					{
						m_eEndPos = eTimeTmp;
						m_lEndChars = m_lTotalChars + 1;
					}
					if(m_eTime > eTimeTmp && eTimeTmp > m_eStartPos)
					{
						m_eStartPos = eTimeTmp;
						m_lStartChars = m_lTotalChars + 1;
					}
				}
			}
		}
	}

	long nodeType = 0;
	pNode->get_nodeType(&nodeType);
	if(nodeType == 3)
	{
		long lRet = 0;
		CComPtr<IHTMLDOMTextNode> pTxtNodePtr;
		pNode->QueryInterface(IID_IHTMLDOMTextNode, (void**)&pTxtNodePtr);
		if(pTxtNodePtr != NULL)
			pTxtNodePtr->get_length(&lRet);
		m_lTotalChars += lRet;
	}

	CComPtr<IHTMLDOMNode> pChildNodePtr;
	pNode->get_firstChild(&pChildNodePtr);
	if(pChildNodePtr != NULL)
		FindTimePos(pChildNodePtr);

	if(!m_bFindNextMode)
	{
		if(sNodeName.CompareNoCase(_T("BR")) == 0 || sNodeName.CompareNoCase(_T("P")) == 0)
		{
			m_lTotalChars += 1;
		}
	}

	CComPtr<IHTMLDOMNode> pNextNodePtr;
	pNode->get_nextSibling(&pNextNodePtr);
	if(pNextNodePtr != NULL)
		FindTimePos(pNextNodePtr);
}

void CEnTranscriptionView::OnInitialUpdate()
{
	CHtmlEditView::OnInitialUpdate();
}

int CEnTranscriptionView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	return CHtmlEditView::OnCreate(lpCreateStruct);
}

void CEnTranscriptionView::OnNavigateComplete2(LPCTSTR strURL)
{
	CString sURL(strURL);
	int nPos = sURL.Find(TUTORIAL_FILENAME);
	if(nPos > 0)
		SetDesignMode(FALSE);
	else
	{
		SetDesignMode(TRUE);
		m_eStartPos = 0;
		m_eEndPos = 0;
	}
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
	SetForeColor(_T("ffe599"));
	SetBackColor(_T("3d85c6"));
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
