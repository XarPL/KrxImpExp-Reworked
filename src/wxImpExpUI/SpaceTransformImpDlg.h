///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformImpDlg.h
// Purpose:     Declaration of class wxSpaceTransformImpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __SpaceTransformImpDlg__
#define __SpaceTransformImpDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxSpaceTransformImpDlg
///////////////////////////////////////////////////////////////////////////////

class wxSpaceTransformImpDlg : public wxFB_SpaceTransformImpDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	virtual void OnRadioChanged( wxCommandEvent& event );
	virtual void OnSystemUnitChanged( wxCommandEvent& event );

public:
	wxSpaceTransformImpDlg(wxWindow* parent, TSpaceTransform& spaceTransform);
	~wxSpaceTransformImpDlg();

private:
	TSpaceTransform*  m_spaceTransform;
};


#endif //__SpaceTransformImpDlg__
