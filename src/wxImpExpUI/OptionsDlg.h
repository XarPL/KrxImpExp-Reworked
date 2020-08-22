///////////////////////////////////////////////////////////////////////////////
// Name:        OptionsDlg.h
// Purpose:     Definition of class wxOptionsDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __OptionsDlg__
#define __OptionsDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxOptionsDlg
///////////////////////////////////////////////////////////////////////////////

class wxOptionsDlg : public wxFB_OptionsDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();

public:
	wxOptionsDlg(wxWindow* parent);
	~wxOptionsDlg();

private:
};


#endif //__OptionsDlg__
