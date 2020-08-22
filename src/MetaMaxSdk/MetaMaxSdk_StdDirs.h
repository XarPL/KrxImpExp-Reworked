///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_StdDirs.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
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
#ifdef APP_MAX_SYS_ROOT_DIR
	int which = APP_MAX_SYS_ROOT_DIR;
#else
	int which = APP_MAXROOT_DIR;
#endif
	static std::tstring dir = AppendSlashIfNeeded(GetInterface()->GetDir(which));
	return dir;
}

static const std::tstring& GetPlugCfgDir()
{
	int which = APP_PLUGCFG_DIR;
	static std::tstring dir = AppendSlashIfNeeded(GetInterface()->GetDir(which));
	return dir;
}

// Get main max executable folder full path. 
// For example, "C:\\Program Files\\Autodesk\\3ds max 2009\\" 
#define ROOT_DIR		(GetRootDir())

// Get folder for plug-in configuration files. 
// For example, "C:\\Program Files\\Autodesk\\3ds max 5\\plugcfg" 
// or "C:\\Documents and Settings\\Username\\Local Settings\\Application Data\\Autodesk\\3ds max\\2009 - 32bit\\enu\\plugcfg\\".
#define PLUGCFG_DIR		(GetPlugCfgDir())

