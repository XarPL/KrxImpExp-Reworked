///////////////////////////////////////////////////////////////////////////////
// Name:        ASCImporterDlg.h
// Purpose:     Declaration of class wxASCImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __ASCImporterDlg__
#define __ASCImporterDlg

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxASCImporterDlg
///////////////////////////////////////////////////////////////////////////////

class wxASCImporterDlg : public wxFB_ASCImporterDlg
{
protected:
	virtual void OnImport( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual void OnHelp( wxCommandEvent& event );
	virtual void OnOptions( wxCommandEvent& event );
	virtual void OnAutoPrefix( wxCommandEvent& event );
	virtual void OnNotebookPageChanging( wxNotebookEvent& event );
	virtual void OnCurSceneModeChanged( wxCommandEvent& event );
	virtual void OnSampleMeshesDir( wxCommandEvent& event );
	virtual void OnSkinTypeChanged( wxCommandEvent& event );
	virtual void OnSpaceTransform( wxCommandEvent& event );
	virtual void OnTimeTransform( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();

	bool TransferDataToWindow_MM();
	bool TransferDataToWindow_MA();
	bool TransferDataToWindow_SM();
	bool TransferDataToWindow_DM();
	bool TransferDataToWindow_DA();
	bool TransferDataFromWindow_MM();
	bool TransferDataFromWindow_MA();
	bool TransferDataFromWindow_SM();
	bool TransferDataFromWindow_DM();
	bool TransferDataFromWindow_DA();
	void UpdateSpaceTransformButton();
	void UpdateTimeTransformButton();

public:
	wxASCImporterDlg(wxWindow* parent, TASCImporterDlgInput& dlgInput, TASCImporterDlgOutput& dlgOutput);
	~wxASCImporterDlg();

private:
	TASCImporterDlgInput*  m_dlgInput;
	TASCImporterDlgOutput* m_dlgOutput;
};


#endif //__ASCImporterDlg
