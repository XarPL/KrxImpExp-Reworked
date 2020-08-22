///////////////////////////////////////////////////////////////////////////////
// Name:        datatransfer.cpp
// Purpose:     Interaction between running the "gmax.exe" program 
//              and the "KrxGMaxExtender.dll" library
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datatransfer.h"
#include "modulerootdir.h"

// Send the result of file operation to maxscript
void SendToMaxScript(long nResult)
{
	FILE* resf = _tfopen((GetModuleRootDir() + _T("KrxExtender.res")).c_str(), _T("wb"));
	fwrite(&nResult, 1, sizeof(nResult), resf);
	fclose(resf);
}
