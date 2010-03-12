// EnTranscriptionView.h : interface of the CEnTranscriptionView class
//


#pragma once


class CEnTranscriptionView : public CHtmlEditView
{
protected: // create from serialization only
	CEnTranscriptionView();
	DECLARE_DYNCREATE(CEnTranscriptionView)

// Attributes
public:
	CEnTranscriptionDoc* GetDocument() const;

// Operations
public:
	void AutoSave(const CString& szCurrentPlay);

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate();
	virtual void OnNavigateComplete2(LPCTSTR strURL);
	virtual HRESULT OnShowContextMenu(DWORD dwID, LPPOINT ppt, LPUNKNOWN pcmdtReserved, LPDISPATCH pdispReserved);

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
	DECLARE_DHTMLEDITING_CMDMAP(CEnTranscriptionView);
public:
	afx_msg void OnButtonColor(UINT);
	afx_msg void OnButtonHighLight(UINT);
};

#ifndef _DEBUG  // debug version in EnTranscriptionView.cpp
inline CEnTranscriptionDoc* CEnTranscriptionView::GetDocument() const
   { return reinterpret_cast<CEnTranscriptionDoc*>(m_pDocument); }
#endif

