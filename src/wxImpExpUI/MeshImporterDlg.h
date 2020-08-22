///////////////////////////////////////////////////////////////////////////////
// Name:        MeshImporterDlg.h
// Purpose:     Declaration of class wxMeshImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __MeshImporterDlg__
#define __MeshImporterDlg

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxMeshImporterDlg
///////////////////////////////////////////////////////////////////////////////

class wxMeshImporterDlg : public wxFB_MeshImporterDlg
{
protected:
	virtual void OnSpaceTransform( wxCommandEvent& event );
	virtual void OnShowInfoWnd( wxCommandEvent& event );
	virtual void OnAutoClose( wxCommandEvent& event );
	virtual void OnImport( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual void OnHelp( wxCommandEvent& event );
	virtual void OnOptions( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	virtual void UpdateSpaceTransformButton();

public:
	wxMeshImporterDlg(wxWindow* parent, TMeshImporterDlgInput& dlgInput, TMeshImporterDlgOutput& dlgOutput);
	~wxMeshImporterDlg();

private:
	TMeshImporterDlgInput*  m_dlgInput;
	TMeshImporterDlgOutput* m_dlgOutput;
};


#endif //__MeshImporterDlg
