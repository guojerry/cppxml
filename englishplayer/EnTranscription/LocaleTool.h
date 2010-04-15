#pragma once

#include <list>

using namespace std;

#define MAIN_MENU_GROUP		_T("MainMenu")
#define RIGHT_MENU_GROUP	_T("RightMenu")
#define TOOLBAR_GROUP		_T("Buttons")

class CLocaleItem
{
public:
	DWORD dwResID;
	CString sTitle;
	CString sDesc;
};
typedef list<CLocaleItem> LOCALEITEMLIST;
typedef list<pair<CString, LOCALEITEMLIST> > SECTIONLIST;

class CLocaleTool
{
public:
	CLocaleTool(LPCTSTR lpszFileName);
	virtual ~CLocaleTool(void);

public:
	static CLocaleTool* Instance();
	static CString GetDefaultLocale();
	void UpdateMenu(CMenu* pMenu, LPCTSTR lpszGroupName);
	void UpdateButtons(CWnd* pDlg, LPCTSTR lpszGroupName);

protected:
	void Load();
	CString GetNextGroup(TCHAR*& szData, int& nRemainSize);
	BOOL ParseItem(CLocaleItem& aItem, TCHAR*& szData, int& nRemainSize);
	BOOL ParseGroup(LOCALEITEMLIST& lItems, TCHAR*& szData, int& nRemainSize);

private:
	CString m_sFileName;
	SECTIONLIST m_lSections;
};
