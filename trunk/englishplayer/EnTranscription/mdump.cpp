#include "stdafx.h"
#include "mdump.h"
#include "shlwapi.h"
#include "LocaleTool.h"

#define ID_MINIDUMP_CONFIRM		200
#define ID_MINIDUMP_REPORT		201
#define ID_MINIDUMP_REPORT_ERR	202

LPCTSTR CMiniDumper::m_szAppName;
BOOL CMiniDumper::m_bHaveDumped = FALSE;

CMiniDumper::CMiniDumper(LPCTSTR szAppName)
{
	// if this assert fires then you have two instances of MiniDumper
	// which is not allowed
	ASSERT(m_szAppName==NULL );

	m_szAppName = szAppName ? _tcsdup(szAppName) : _T("Application");
	m_bHaveDumped = FALSE;

	::SetUnhandledExceptionFilter(TopLevelFilter);
}

LONG CMiniDumper::TopLevelFilter(struct _EXCEPTION_POINTERS *pExceptionInfo)
{
	//Only dump once.
	if(m_bHaveDumped)
		return 0;

	m_bHaveDumped = TRUE;
	LONG retval = EXCEPTION_CONTINUE_SEARCH;

	// firstly see if dbghelp.dll is around and has the function we need
	// look next to the EXE first, as the one in System32 might be old 
	// (e.g. Windows 2000)
	HMODULE hDll = NULL;
	TCHAR szDbgHelpPath[_MAX_PATH] = {0};

	if(GetModuleFileName( NULL, szDbgHelpPath, _MAX_PATH ))
	{
		PathRemoveFileSpec(szDbgHelpPath);
		PathAppend(szDbgHelpPath, _T("DBGHELP.DLL"));
		hDll = ::LoadLibrary( szDbgHelpPath );
	}
	if(hDll == NULL)		// load any version we can
		hDll = ::LoadLibrary(_T("DBGHELP.DLL"));

	if(hDll == NULL)
	{
		ASSERT(FALSE);
		return retval;
	}

	LPCTSTR szResult = NULL;
	MINIDUMPWRITEDUMP pDump = (MINIDUMPWRITEDUMP)::GetProcAddress( hDll, "MiniDumpWriteDump" );
	if(pDump == NULL)
	{
		ASSERT(FALSE);
		return retval;
	}

	TCHAR szDumpPath[_MAX_PATH] = {0};
	TCHAR szScratch [_MAX_PATH] = {0};

	//Save it to the desktop
	SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, szDumpPath);
	CString szFileName;
	szFileName.Format(_T("%s_%d.dmp"), m_szAppName, BUILD_NO);
	PathAppend(szDumpPath, szFileName);

	CString sMsg = CLocaleTool::Instance()->LoadString(ID_MINIDUMP_CONFIRM, _T("Something bad happened in your program, would you like to save a diagnostic file?"));
	CString sErrFormat = CLocaleTool::Instance()->LoadString(ID_MINIDUMP_REPORT_ERR, _T("Failed to save dump file to '%s' (error %d)"));

	if (::MessageBox(NULL, sMsg, m_szAppName, MB_YESNO )==IDYES)
	{
		HANDLE hFile = ::CreateFile(szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile!=INVALID_HANDLE_VALUE)
		{
			_MINIDUMP_EXCEPTION_INFORMATION ExInfo;

			ExInfo.ThreadId = ::GetCurrentThreadId();
			ExInfo.ExceptionPointers = pExceptionInfo;
			ExInfo.ClientPointers = NULL;

			// write the dump
			BOOL bOK = pDump( GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, &ExInfo, NULL, NULL );
			if(bOK)
			{
				CString sFormat = CLocaleTool::Instance()->LoadString(ID_MINIDUMP_REPORT, _T("Saved dump file to '%s'"));
				_stprintf_s(szScratch,_MAX_PATH, sFormat, szDumpPath );
				szResult = szScratch;
				retval = EXCEPTION_EXECUTE_HANDLER;
			}
			else
			{
				_stprintf_s(szScratch, _MAX_PATH, sErrFormat, szDumpPath, GetLastError() );
				szResult = szScratch;
			}
			::CloseHandle(hFile);
		}
		else
		{
			_stprintf_s(szScratch, _MAX_PATH, sErrFormat, szDumpPath, GetLastError());
			szResult = szScratch;
		}
	}

	if (szResult)
		::MessageBox( NULL, szResult, m_szAppName, MB_OK );

	return retval;
}
