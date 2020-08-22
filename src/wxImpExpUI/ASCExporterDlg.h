///////////////////////////////////////////////////////////////////////////////
// Name:        ASCExporterDlg.h
// Purpose:     Declaration of class wxASCExporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __ASCExporterDlg__
#define __ASCExporterDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxASCExporterDlg
///////////////////////////////////////////////////////////////////////////////

class wxASCExporterDlg : public wxFB_ASCExporterDlg
{
protected:
	virtual void OnPrefixChanged( wxCommandEvent& event );
	virtual void OnTypeOfExportChanged( wxCommandEvent& event );
	virtual void OnObjectSelected( wxCommandEvent& event );
	virtual void OnSelectAll( wxCommandEvent& event );
	virtual void OnSelectNone( wxCommandEvent& event );
	virtual void OnSpaceTransform( wxCommandEvent& event );
	virtual void OnTimeTransform( wxCommandEvent& event );
	virtual void OnExport( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual void OnHelp( wxCommandEvent& event );
	virtual void OnOptions( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	void UpdateSpaceTransformButton();
	void UpdateTimeTransformButton();

public:
	wxASCExporterDlg(wxWindow* parent, TASCExporterDlgInput& dlgInput, TASCExporterDlgOutput& dlgOutput);
	~wxASCExporterDlg();

private:
	TASCExporterDlgInput*  m_dlgInput;
	TASCExporterDlgOutput* m_dlgOutput;
	TModelHierarchy*       m_curModelHierarchy;
};


#endif //__ASCExporterDlg__
