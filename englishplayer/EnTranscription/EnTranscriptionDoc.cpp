// EnTranscriptionDoc.cpp : implementation of the CEnTranscriptionDoc class
//

#include "stdafx.h"
#include "EnTranscription.h"

#include "EnTranscriptionDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEnTranscriptionDoc

IMPLEMENT_DYNCREATE(CEnTranscriptionDoc, CDocument)

BEGIN_MESSAGE_MAP(CEnTranscriptionDoc, CDocument)
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
	if (!CDocument::OnNewDocument())
		return FALSE;

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

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
	CDocument::AssertValid();
}

void CEnTranscriptionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CEnTranscriptionDoc commands
