///////////////////////////////////////////////////////////////////////////////
// Name:        modulerootdir.cpp
// Purpose:     Getting root gmax directory
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "modulerootdir.h"

// Get root gmax directory
tstring GetModuleRootDir()
{
	static tstring rootDir;
	if(rootDir.empty())
	{
		TCHAR szFileName[MAX_PATH];
		GetModuleFileName(NULL, szFileName, MAX_PATH);
		rootDir = szFileName;
		while(rootDir.length() > 0 && rootDir[rootDir.length() - 1] != _T('\\'))
			rootDir.resize(rootDir.length() - 1);
	}
	return rootDir;
}