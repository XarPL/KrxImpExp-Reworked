///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_StdDirs.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::tstring AppendSlashIfNeeded(const TCHAR* pszDir)
{
	std::tstring strDir = pszDir;
	TCHAR chLast = strDir[strDir.length() - 1];
	if(chLast != _T('\\'))
	{
		strDir += _T('\\');
	}
	return strDir;
}

static const std::tstring& GetRootDir()
{
	static std::tstring dir;
	if(dir.empty())
	{
		String str = GeGetStartupPath().GetString();
		UWORD ubuf[MAX_PATH];
		str.GetUcBlockNull(ubuf, MAX_PATH);
		char path[MAX_PATH];
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) ubuf, -1, path, MAX_PATH, NULL, NULL);
		dir = AppendSlashIfNeeded(path);
	}
	return dir;
}

static const std::tstring& GetPlugCfgDir()
{
	static std::tstring dir;
	if(dir.empty())
	{
		String str = GeGetC4DPath(C4D_PATH_PREFS).GetString();
		UWORD ubuf[MAX_PATH];
		str.GetUcBlockNull(ubuf, MAX_PATH);
		char path[MAX_PATH];
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) ubuf, -1, path, MAX_PATH, NULL, NULL);
		dir = AppendSlashIfNeeded(path);
	}
	return dir;
}

// Get main max executable folder full path. 
// For example, "C:\\Program Files\\Cinema4D\\" 
#define ROOT_DIR		(GetRootDir())

// Get folder for plug-in configuration files. 
// For example, "C:\\Documents and Settings\\Username\\Application Data\\MAXON\\Cinema4D_FFFFFFFF\\prefs"
#define PLUGCFG_DIR		(GetPlugCfgDir())

