// EnTranscriptionDoc.h : interface of the CEnTranscriptionDoc class
//


#pragma once


class CEnTranscriptionDoc : public CDocument
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
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CEnTranscriptionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


