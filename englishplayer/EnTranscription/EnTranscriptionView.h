// EnTranscriptionView.h : interface of the CEnTranscriptionView class
//


#pragma once


class CEnTranscriptionView : public CEditView
{
protected: // create from serialization only
	CEnTranscriptionView();
	DECLARE_DYNCREATE(CEnTranscriptionView)

// Attributes
public:
	CEnTranscriptionDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CEnTranscriptionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
};

#ifndef _DEBUG  // debug version in EnTranscriptionView.cpp
inline CEnTranscriptionDoc* CEnTranscriptionView::GetDocument() const
   { return reinterpret_cast<CEnTranscriptionDoc*>(m_pDocument); }
#endif

