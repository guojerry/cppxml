// EnTranscriptionDoc.cpp : implementation of the CEnTranscriptionDoc class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "MainFrm.h"
#include "EnTranscriptionDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEnTranscriptionDoc

IMPLEMENT_DYNCREATE(CEnTranscriptionDoc, CHtmlEditDoc)

BEGIN_MESSAGE_MAP(CEnTranscriptionDoc, CHtmlEditDoc)
END_MESSAGE_MAP()


// CEnTranscriptionDoc construction/destruction

CEnTranscriptionDoc::CEnTranscriptionDoc()
{
	// TODO: add one-time construction code here

}

CEnTranscriptionDoc::~CEnTranscriptionDoc()
{
}

BOOL CEnTranscriptionDoc::OnNewDocument()
{
	if (!CHtmlEditDoc::OnNewDocument())
		return FALSE;

	reinterpret_cast<CHtmlEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

BOOL CEnTranscriptionDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	if(pFrame)
		return pFrame->OpenMediaFile(lpszPathName);
	return TRUE;
}

// CEnTranscriptionDoc serialization
void CEnTranscriptionDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
}


// CEnTranscriptionDoc diagnostics

#ifdef _DEBUG
void CEnTranscriptionDoc::AssertValid() const
{
	CHtmlEditDoc::AssertValid();
}

void CEnTranscriptionDoc::Dump(CDumpContext& dc) const
{
	CHtmlEditDoc::Dump(dc);
}
#endif //_DEBUG


// CEnTranscriptionDoc commands
