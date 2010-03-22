// EnTranscriptionView.h : interface of the CEnTranscriptionView class
//


#pragma once

#define MAX_LINE	32

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
	void OpenTranscription(const CString& sFilePath);
	void ShowTutorial();
	void SetTimeMarker(double eTime);
	void HightLightCurrent(double eTime);
	void RemoveHighlightDiv();

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate();
	virtual void OnNavigateComplete2(LPCTSTR strURL);
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
	virtual HRESULT OnShowContextMenu(DWORD dwID, LPPOINT ppt, LPUNKNOWN pcmdtReserved, LPDISPATCH pdispReserved);
	void CreateHighlightDiv(IHTMLElement** pDiv, const RECT& rc);
	void ResetHighlightDiv();

	// Implementation
public:
	virtual ~CEnTranscriptionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double m_eStartPos;
	double m_eEndPos;
	CComPtr<IHTMLElement> m_pHighlightDiv[MAX_LINE];
	BOOL m_bAutoSave;
	BOOL m_bFirstLoad;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTMLEDITING_CMDMAP(CEnTranscriptionView);
public:
	afx_msg void OnButtonColor(UINT);
	afx_msg void OnButtonHighLight(UINT);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

class CDomExplore
{
public:
	CDomExplore(double eTime);
	CDomExplore(long lCurrChars);

public:
	void FindTimePos(IHTMLDOMNode* pNode);
	long GetStartChars() { return m_lStartChars; }
	long GetEndChars() { return m_lEndChars; }
	long GetTotalChars() { return m_lTotalChars; }
	double GetStartPos() { return m_eStartPos; }
	double GetEndPos() { return m_eEndPos; }
	double GetNextTimerPos() {return m_eNextTime;}

protected:
	double m_eTime;
	double m_eNextTime;
	double m_eStartPos;
	double m_eEndPos;

	long m_lCurrentChars;
	long m_lTotalChars;
	long m_lStartChars;
	long m_lEndChars;

	BOOL m_bFindNextMode;
};

#ifndef _DEBUG  // debug version in EnTranscriptionView.cpp
inline CEnTranscriptionDoc* CEnTranscriptionView::GetDocument() const
   { return reinterpret_cast<CEnTranscriptionDoc*>(m_pDocument); }
#endif

