///////////////////////////////////////////////////////////////////////////////
// Name:        extender.cpp
// Purpose:     KrxGMaxExtender main source file
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	// check existance of executable "gmax.exe"
	if(_taccess(_T("gmax.exe"), 0x00) != 0)
	{
		MessageBox(NULL, _T("Cound not find \"gmax.exe\"."), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}

	// check existance of startup script "KrxGMaxExtender.ms"
	if(_taccess(_T("scripts\\startup\\KrxGMaxExtender.ms"), 0x00) != 0)
	{
		MessageBox(NULL, _T("Cound not find maxscript \"scripts\\startup\\KrxGMaxExtender.ms\"."), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}

	// load library with hook procedures
	LPCTSTR pszDllFileName = _T("KrxGMaxExtender.dll");
	HINSTANCE hinstDLL = LoadLibrary(pszDllFileName); 
	if(!hinstDLL)
	{
		tostringstream strmMsg;
		strmMsg << _T("Could not load library \"") << pszDllFileName << _T("\".");
		MessageBox(NULL, strmMsg.str().c_str(), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}
	
	HOOKPROC hkprcCallWnd = (HOOKPROC) GetProcAddress(hinstDLL, "CallWndProc"); 
	if(!hkprcCallWnd)
	{
		tostringstream strmMsg;
		strmMsg << _T("Unable to get the address of function \"") << _T("CallWndProc");
		strmMsg << _T("\" in the \"") << pszDllFileName << _T("\" library.");
		MessageBox(NULL, strmMsg.str().c_str(), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}

    // start "gmax.exe"
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
 
	ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

	TCHAR szGMaxPath[MAX_PATH];
	_tcscpy(szGMaxPath, _T("gmax.exe"));
	if(!CreateProcess(NULL, szGMaxPath, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		MessageBox(NULL, _T("Cound not start \"gmax.exe\"."), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	} 
  
	if(WaitForInputIdle(pi.hProcess, INFINITE) != 0)
	{
		MessageBox(NULL, _T("Failed to wait for input idle for running process \"gmax.exe\"."), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}

	// Install hooks
	HHOOK hhookCallWnd = SetWindowsHookEx(WH_CALLWNDPROC, hkprcCallWnd, hinstDLL, pi.dwThreadId); 
	if(!hhookCallWnd)
	{
		MessageBox(NULL, _T("Failed to install hook."), _T("KrxGMaxExtender"), MB_ICONSTOP);
		return -1;
	}

	// Debugging message 
#ifdef _DEBUG
	// MessageBox(NULL, _T("Hook was successfully installed."), _T("KrxGMaxExtender"), MB_ICONINFORMATION);
#endif

	// Wait for closing gmax
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Uninstall hooks
	UnhookWindowsHookEx(hhookCallWnd);

	return 0;
}


