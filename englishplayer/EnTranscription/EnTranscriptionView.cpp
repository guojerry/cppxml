// EnTranscriptionView.cpp : implementation of the CEnTranscriptionView class
//

#include "stdafx.h"
#include "EnTranscription.h"

#include "EnTranscriptionDoc.h"
#include "EnTranscriptionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEnTranscriptionView

IMPLEMENT_DYNCREATE(CEnTranscriptionView, CEditView)

BEGIN_MESSAGE_MAP(CEnTranscriptionView, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

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
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CEnTranscriptionView printing

BOOL CEnTranscriptionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CEnTranscriptionView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CEnTranscriptionView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CEnTranscriptionView diagnostics

#ifdef _DEBUG
void CEnTranscriptionView::AssertValid() const
{
	CEditView::AssertValid();
}

void CEnTranscriptionView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CEnTranscriptionDoc* CEnTranscriptionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnTranscriptionDoc)));
	return (CEnTranscriptionDoc*)m_pDocument;
}
#endif //_DEBUG


// CEnTranscriptionView message handlers
