///////////////////////////////////////////////////////////////////////////////
// Name:        AboutDlg.h
// Purpose:     Declaration of class wxAboutDlg.
// Author:      Vitaly Baranov
// Created:     February 20, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __AboutDlg__
#define __AboutDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxAboutDlg
///////////////////////////////////////////////////////////////////////////////

class wxAboutDlg : public wxFB_AboutDlg
{
protected:
	virtual void OnClose( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();

public:
	wxAboutDlg(wxWindow* parent);
	~wxAboutDlg();
};


#endif //__AboutDlg__
