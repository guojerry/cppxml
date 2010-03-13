// EnTranscriptionDoc.cpp : implementation of the CEnTranscriptionDoc class
//

#include "stdafx.h"
#include "EnTranscription.h"
#include "MainFrm.h"
#include "EnTranscriptionDoc.h"
#include "EnTranscriptionView.h"
#include "shlwapi.h"

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

CString CEnTranscriptionDoc::GetDefaultPath(LPCTSTR lpszPathName)
{
	TCHAR szFilePath[MAX_PATH] = {0};
	_tcscpy_s(szFilePath, MAX_PATH, lpszPathName);

	CString sFileName = PathFindFileName(szFilePath);
	PathRemoveFileSpec(szFilePath);
	PathAppend(szFilePath, HIDDEN_SCRIPT_DIR);
	if(!PathIsDirectory(szFilePath))
	{
		CreateDirectory(szFilePath, NULL);
		SetFileAttributes(szFilePath, FILE_ATTRIBUTE_HIDDEN);
	}
	sFileName += _T(".htm");
	PathAppend(szFilePath, sFileName);

	return CString(szFilePath);
}

void CEnTranscriptionDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU)
{
	if(m_strPathName.CompareNoCase(lpszPathName) != 0)
	{
		CString sDocPath = GetDefaultPath(lpszPathName);
		CHtmlEditDoc::SetPathName(sDocPath, bAddToMRU);
	}
	else
		CHtmlEditDoc::SetPathName(lpszPathName, bAddToMRU);
}

BOOL CEnTranscriptionDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return CHtmlEditDoc::OnSaveDocument(lpszPathName);
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
