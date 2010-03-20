// MainFrm.h : interface of the CMainFrame class
//


#pragma once
#include "NavigatorBar.h"

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:
	BOOL OpenMediaFile(LPCTSTR lpszPath);
	void ShowTutorial();
	void HightLightCurrent(double eTime);

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar m_wndStatusBar;
	CNavigatorBar m_wndNavigator;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPlayPrevious();
	afx_msg void OnPlayContinue();
	afx_msg void OnPlayRepeat();
	afx_msg void OnPlayRepeatslowly();
	afx_msg void OnFileMySaveAs();
	afx_msg void OnFileSave();
};
