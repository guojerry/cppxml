// EnTranscriptionDoc.h : interface of the CEnTranscriptionDoc class
//


#pragma once


#define TUTORIAL_FILENAME		_T("tutorial.htm")
#define TEMPLATE_FILENAME		_T("template.htm")
#define HIDDEN_SCRIPT_DIR		_T(".transcriptions")

class CEnTranscriptionDoc : public CHtmlEditDoc
{
protected: // create from serialization only
	CEnTranscriptionDoc();
	DECLARE_DYNCREATE(CEnTranscriptionDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);

	// Implementation
public:
	virtual ~CEnTranscriptionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString GetDefaultPath(LPCTSTR lpszPathName);

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


