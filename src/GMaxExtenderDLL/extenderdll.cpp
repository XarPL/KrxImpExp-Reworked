///////////////////////////////////////////////////////////////////////////////
// Name:        extenderdll.cpp
// Purpose:     KrxGMaxExtenderDll main source file
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cmdgen.h"

// Find output window MaxScript Listener window
HWND FindOutputWnd()
{
	static HWND s_hwndOutput = NULL;
 	if(!s_hwndOutput)
	{
		// find MaxScript Listener window
		HWND hwndListener = NULL;
		while(hwndListener = FindWindowEx(NULL, hwndListener, _T("#32770"), _T("MAXScript Listener")))
		{
			DWORD dwProcessId;
			DWORD dwThreadId = GetWindowThreadProcessId(hwndListener, &dwProcessId);
			if(dwProcessId == GetCurrentProcessId())
				break;
		}
 
		if(hwndListener == NULL)
		{
			MessageBox(NULL, _T("Could not find a MAXScript Listener dialog."), _T("KrxGMaxAgent"), MB_ICONSTOP);
			return NULL;
		}

		// find output window (output window is dialog item of MaxScript Listener window)
		HWND hwndOutput = GetDlgItem(hwndListener, 0x03E9);
		if(hwndOutput == NULL)
		{
			MessageBox(NULL, _T("The found MAXScript Listener dialog has not an output window (item with id = 0x03E9)."), _T("KrxGMaxAgent"), MB_ICONSTOP);
			return NULL;
		} 

		// check class name of output window
		TCHAR szClassName[64];
		if(!GetClassName(hwndOutput, szClassName, sizeof(szClassName) / sizeof(szClassName[0]))
			|| _tcsicmp(szClassName, _T("RICHEDIT")) != 0)
		{
			MessageBox(NULL, _T("The MAXScript Listener's output window is not RICHEDIT."), _T("KrxGMaxAgent"), MB_ICONSTOP);
			return NULL;
		}

		// save handle to output window for following using
		s_hwndOutput = hwndOutput;
 
#ifdef _DEBUG
		// MessageBox(NULL, _T("MAXScript Listener dialog and its output window were successfully found."), _T("KrxGMaxAgent"), MB_ICONINFORMATION);
#endif
	}
	return s_hwndOutput;
}

// Hook procedure that monitors messages before the system sends them to the destination window procedure
LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(nCode >= 0) 
	{
		CWPSTRUCT* pCWP = (CWPSTRUCT*)lParam;
		if(pCWP->message == EM_REPLACESEL)
			if(pCWP->hwnd == FindOutputWnd())
			{
				tstring strText = (LPCTSTR) (pCWP->lParam);
				RunAgentCommand(strText);
			} 
 	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Find and close window with invitation to visit gmax on-line
void CloseOnlineInvitationWnd()
{
	HWND hwndOnlineInvit = NULL;
	while(hwndOnlineInvit = FindWindowEx(NULL, hwndOnlineInvit, _T("#32770"), _T("gmax")))
	{
		DWORD dwProcessId;
		DWORD dwThreadId = GetWindowThreadProcessId(hwndOnlineInvit, &dwProcessId);
		if(dwProcessId == GetCurrentProcessId())
		{
			HWND hwndVisit = FindWindowEx(hwndOnlineInvit, NULL, _T("Button"), _T("&Visit"));
			HWND hwndContinue = FindWindowEx(hwndOnlineInvit, NULL, _T("Button"), _T("Continue"));
			int idContinue = GetWindowLong(hwndContinue, GWL_ID);
			PostMessage(hwndOnlineInvit, WM_COMMAND, idContinue, 0);
		}
	}
}

// Send a string "loaded/unloaded" to the debugger to display
void MsgBoxLoaded(BOOL bLoaded)
{
	TCHAR szFileName[MAX_PATH];
	GetModuleFileName(NULL, szFileName, MAX_PATH);
	tostringstream strmMsg;
	strmMsg << _T("KrxGMaxAgent ") << (bLoaded ? _T("loaded") : _T("unloaded"))
		<< _T(" by process '") << szFileName << _T("'.");
	MessageBox(NULL, strmMsg.str().c_str(), _T("KrxGMaxAgent"), MB_ICONINFORMATION);
}

// Main entry
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
#ifdef _DEBUG
		// MsgBoxLoaded(TRUE);

#endif
		CloseOnlineInvitationWnd();
	}
	else if(ul_reason_for_call == DLL_PROCESS_DETACH)
	{
#ifdef _DEBUG
		// MsgBoxLoaded(FALSE);
#endif
	}
    return TRUE;
}

