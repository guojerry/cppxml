// EnTranscription.h : main header file for the EnTranscription application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEnTranscriptionApp:
// See EnTranscription.cpp for the implementation of this class
//

class CEnTranscriptionApp : public CWinApp
{
public:
	CEnTranscriptionApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEnTranscriptionApp theApp;