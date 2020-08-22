///////////////////////////////////////////////////////////////////////////////
// Name:        MatRenParamsDlg.h
// Purpose:     Declaration of class wxMatRenParamsDlg.
// Author:      Vitaly Baranov
// Created:     June 1, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __MatRenParamsDlg__
#define __MatRenParamsDlg

#include "FB_ImpExpUI.h"


///////////////////////////////////////////////////////////////////////////////
/// Class wxMatRenParamsDlg
///////////////////////////////////////////////////////////////////////////////

class wxMatRenParamsDlg : public wxFB_MatRenParamsDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual void OnBrowseMatLibIni( wxCommandEvent& event );
	virtual void OnLoadMaterialFilter( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	void UpdateListKnownMaterials();

public:
	wxMatRenParamsDlg(wxWindow* parent);
	~wxMatRenParamsDlg();

private:
	TMatRenParams* m_matRenParams;
};


#endif //__MatRenParamsDlg
