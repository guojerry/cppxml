#include "StdAfx.h"
#include "LocaleTool.h"
#include "shlwapi.h"

CLocaleTool g_LocaleTool(_T("main.txt"));

CLocaleTool* CLocaleTool::Instance()
{
	return &g_LocaleTool;
}

CLocaleTool::CLocaleTool(LPCTSTR lpszFileName)
{
	TCHAR szFilePath[MAX_PATH] = {0};

	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	PathRemoveFileSpec(szFilePath);

	TCHAR szLocalePath[MAX_PATH] = {0};
	_tcscpy_s(szLocalePath, MAX_PATH, szFilePath);
	PathAppend(szLocalePath, GetDefaultLocale());
	PathAppend(szLocalePath, lpszFileName);

	m_sFileName = szLocalePath;
	Load();
}

CLocaleTool::~CLocaleTool(void)
{
}

CString CLocaleTool::GetDefaultLocale()
{
	TCHAR szLocaleName[MAX_PATH] = {0};
	GetLocaleInfo(LOCALE_USER_DEFAULT , LOCALE_SNAME, szLocaleName, MAX_PATH);

	return szLocaleName;
}

void CLocaleTool::Load()
{
	HANDLE hFile = CreateFile(m_sFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == NULL || hFile == INVALID_HANDLE_VALUE)
		return;

	char* pData = NULL;
	do 
	{
		DWORD dwFileSize = GetFileSize(hFile, NULL);
		pData = new char[dwFileSize + sizeof(TCHAR)];
		if(pData == NULL)
			break;

		DWORD dwRead = 0;
		if(!ReadFile(hFile, pData, dwFileSize, &dwRead, NULL))
			break;

		TCHAR* szData = (TCHAR*)pData;
		int nRemainSize = dwFileSize / sizeof(TCHAR);
		szData[nRemainSize] = _T('\0');
		if(szData[0] == 0xFEFF)	//Unicode file header
		{
			szData++;
			nRemainSize--;
		}
		while(1)
		{
			CString sGroupName = GetNextGroup(szData, nRemainSize);
			if(sGroupName.IsEmpty() || nRemainSize == 0)
				break;
			m_lSections.push_back(make_pair(sGroupName, LOCALEITEMLIST()));
			LOCALEITEMLIST& lItems = m_lSections.back().second;
			if(!ParseGroup(lItems, szData, nRemainSize) || nRemainSize == 0)
				break;
		}
	} while(FALSE);

	CloseHandle(hFile);
	if(pData != NULL)
		delete [] pData;
}

CString CLocaleTool::GetNextGroup(TCHAR*& szData, int& nRemainSize)
{
	CString sRet;
	while(1)
	{
		if(nRemainSize <= 0)
			break;

		TCHAR* pNextLine = _tcsstr(szData, _T("\n"));

		if(pNextLine == NULL)
			break;
		nRemainSize -= (pNextLine - szData + 1);
		CString sTxt(szData, (pNextLine - szData)); 
		szData = pNextLine + 1;
		sTxt.Trim();
		if(sTxt.GetAt(0) == _T('[') && sTxt.GetAt(sTxt.GetLength() - 1) == _T(']'))
		{
			sRet = sTxt.Mid(1, sTxt.GetLength() - 2);
			break;
		}
	}

	return sRet;
}

BOOL CLocaleTool::ParseGroup(LOCALEITEMLIST& lItems, TCHAR*& szData, int& nRemainSize)
{
	while(1)
	{
		CLocaleItem aItem;
		if(!ParseItem(aItem, szData, nRemainSize))
			break;
		lItems.push_back(aItem);
		if(nRemainSize <= 0)
			break;
	}
	return TRUE;
}

BOOL CLocaleTool::ParseItem(CLocaleItem& aItem, TCHAR*& szData, int& nRemainSize)
{
	BOOL bRet = FALSE;
	while(1)
	{
		if(nRemainSize <= 0)
			break;

		TCHAR* pNextLine = _tcsstr(szData, _T("\n"));

		if(pNextLine == NULL)
			break;
		CString sTxt(szData, (pNextLine - szData)); 
		sTxt.Trim();
		if(sTxt.GetAt(0) == _T('['))
			break;

		nRemainSize -= (pNextLine - szData + 1);
		szData = pNextLine + 1;

		if(sTxt.GetAt(0) == _T('{') && sTxt.GetAt(sTxt.GetLength() - 1) == _T('}'))
		{
			CString sID, sDesc, sLocale;
			int nIdx = sTxt.Find(_T(','));
			if(nIdx > 0)
			{
				sID = sTxt.Mid(1, nIdx - 1);
				int nNext = sTxt.Find(_T(','), nIdx + 1);
				if(nNext > nIdx)
				{
					sLocale = sTxt.Mid(nIdx + 1, nNext - nIdx - 1);
					sDesc = sTxt.Mid(nNext + 1, sTxt.GetLength() - nNext - 2);
				}
			}
			sID.Trim();
			sLocale.Trim();
			sDesc.Trim();
			aItem.dwResID = _ttoi(sID);
			aItem.sTitle = sLocale.Mid(1, sLocale.GetLength() - 2);
			aItem.sDesc = sDesc.Mid(1, sDesc.GetLength() - 2);
			aItem.sTitle.Replace(_T("\\t"), _T("\t"));
			bRet = TRUE;
			break;
		}
	}

	return bRet;
}

void CLocaleTool::UpdateMenu(CMenu* pMenu, LPCTSTR lpszGroupName)
{
	if(pMenu == NULL || lpszGroupName == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	LOCALEITEMLIST* pItemList = NULL;
	SECTIONLIST::iterator it = m_lSections.begin();
	for(; it != m_lSections.end(); it++)
	{
		if(it->first.CompareNoCase(lpszGroupName) == 0)
		{
			pItemList = &(it->second);
			break;
		}
	}
	if(pItemList == NULL)
		return;

	LOCALEITEMLIST::iterator itItem = pItemList->begin();
	for(; itItem != pItemList->end(); itItem++)
	{
		CLocaleItem& item = *itItem;
		if(item.dwResID < 16)
		{
			pMenu->ModifyMenu(item.dwResID, MF_BYPOSITION|MF_STRING, 0, item.sTitle);
		}
		else
		{
			pMenu->ModifyMenu(item.dwResID, MF_BYCOMMAND|MF_STRING, item.dwResID, item.sTitle);
		}
	}
}

void CLocaleTool::UpdateButtons(CWnd* pDlg, LPCTSTR lpszGroupName)
{
	if(pDlg == NULL || lpszGroupName == NULL)
	{
		ASSERT(FALSE);
		return;
	}
	LOCALEITEMLIST* pItemList = NULL;
	SECTIONLIST::iterator it = m_lSections.begin();
	for(; it != m_lSections.end(); it++)
	{
		if(it->first.CompareNoCase(lpszGroupName) == 0)
		{
			pItemList = &(it->second);
			break;
		}
	}
	if(pItemList == NULL)
		return;

	LOCALEITEMLIST::iterator itItem = pItemList->begin();
	for(; itItem != pItemList->end(); itItem++)
	{
		CLocaleItem& item = *itItem;
		CWnd* pItemWnd = pDlg->GetDlgItem(item.dwResID);
		if(pItemWnd)
			pItemWnd->SetWindowText(item.sTitle);
	}
}
