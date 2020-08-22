///////////////////////////////////////////////////////////////////////////////
// Name:        3DSExporterDlg.h
// Purpose:     Declaration of class wx3DSExporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __3DSExporterDlg__
#define __3DSExporterDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wx3DSExporterDlg
///////////////////////////////////////////////////////////////////////////////

class wx3DSExporterDlg : public wxFB_3DSExporterDlg
{
protected:
	virtual void OnObjectDClicked( wxCommandEvent& event );
	virtual void OnObjectSelected( wxCommandEvent& event );
	virtual void OnSelectAll( wxCommandEvent& event );
	virtual void OnSelectNone( wxCommandEvent& event );
	virtual void OnShowInfoWnd( wxCommandEvent& event );
	virtual void OnAutoClose( wxCommandEvent& event );
	virtual void OnSpaceTransform( wxCommandEvent& event );
	virtual void OnRenameMaterials( wxCommandEvent& event );
	virtual void OnMatRenParams( wxCommandEvent& event );
	virtual void OnExport( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual void OnHelp( wxCommandEvent& event );
	virtual void OnOptions( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	virtual void UpdateSpaceTransformButton();

public:
	wx3DSExporterDlg(wxWindow* parent, T3DSExporterDlgInput& dlgInput, T3DSExporterDlgOutput& dlgOutput);
	~wx3DSExporterDlg();

private:
	T3DSExporterDlgInput*  m_dlgInput;
	T3DSExporterDlgOutput* m_dlgOutput;
};


#endif //__3DSExporterDlg__
