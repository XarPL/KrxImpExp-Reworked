///////////////////////////////////////////////////////////////////////////////
// Name:        3DSImporterDlg.h
// Purpose:     Declaration of class wx3DSImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __3DSImporterDlg__
#define __3DSImporterDlg

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wx3DSImporterDlg
///////////////////////////////////////////////////////////////////////////////

class wx3DSImporterDlg : public wxFB_3DSImporterDlg
{
protected:
	virtual void OnCurSceneModeChanged( wxCommandEvent& event );
	virtual void OnWeldVertices( wxCommandEvent& event );
	virtual void OnThresholdSpin( wxSpinEvent& event );
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
	wx3DSImporterDlg(wxWindow* parent, T3DSImporterDlgInput& dlgInput, T3DSImporterDlgOutput& dlgOutput);
	~wx3DSImporterDlg();

private:
	T3DSImporterDlgInput*  m_dlgInput;
	T3DSImporterDlgOutput* m_dlgOutput;
};


#endif //__3DSImporterDlg
