///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_System.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static int OSExecute(const std::tstring& cmd)
{
	DWORD dwExitCode = 1;
	STARTUPINFO startinfo;
	PROCESS_INFORMATION procinfo;

	ZeroMemory( &startinfo, sizeof(STARTUPINFO) );
	startinfo.cb = sizeof(STARTUPINFO);
	ZeroMemory( &procinfo, sizeof(PROCESS_INFORMATION) );
  
	LPTSTR pszCmd = _tcsdup(cmd.c_str());
	BOOL bOk = CreateProcess(NULL, pszCmd, NULL, NULL, FALSE, 0, NULL, NULL, &startinfo, &procinfo);
	free(pszCmd);

	if(bOk)
	{
		WaitForSingleObject(procinfo.hProcess, INFINITE);
		GetExitCodeProcess(procinfo.hProcess, &dwExitCode);
	}
	return (int) dwExitCode;
}

// Passes the cmd to the command interpreter, which executes the string as an operation-system command
#define SYSTEM(cmd)		(OSExecute(cmd))