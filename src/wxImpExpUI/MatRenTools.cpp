///////////////////////////////////////////////////////////////////////////////
// Name:        MatRenTools.h
// Purpose:     Material renaming utilities
// Author:      Vitaly Baranov
// Created:     June 1, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// wxImpExpUI headers
#include "ImpExpUIApp.h"
#include "MatRenTools.h"

wxString GetMatRenParamsPath()
{
	wxString cfgDir = wxGetApp().argv[3];
	for(int i = cfgDir.Length() - 1; i >= 0; --i)
		if(cfgDir[i] == _T('\\') || cfgDir[i] == _T('/'))
		{
			cfgDir = cfgDir.Left(i);
			break;
		}

	return cfgDir + _T("\\KrxImpExpMatRenParams.txt");
}
