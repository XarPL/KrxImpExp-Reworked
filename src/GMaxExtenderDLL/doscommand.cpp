///////////////////////////////////////////////////////////////////////////////
// Name:        doscommand.cpp
// Purpose:     Functions to work with command line
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "doscommand.h"
#include "datatransfer.h"

// Execute an external program
void DOSCommand(const tstring& strCommandLine)
{
	DWORD dwExitCode = 1;

	STARTUPINFO si;
    PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
  
	LPTSTR pszCmdLineNC = _tcsdup( (_T("cmd /c ") + strCommandLine).c_str() );
	BOOL bOk = CreateProcess(NULL, pszCmdLineNC, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	free(pszCmdLineNC);

	if(bOk)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		GetExitCodeProcess(pi.hProcess, &dwExitCode);
	}
	else
	{
		DWORD err = ::GetLastError();
	}
	SendToMaxScript( (long)dwExitCode );
} 