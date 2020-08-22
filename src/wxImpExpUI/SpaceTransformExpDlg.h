///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformExpDlg.h
// Purpose:     Declaration of class wxSpaceTransformExpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __SpaceTransformExpDlg__
#define __SpaceTransformExpDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxSpaceTransformExpDlg
///////////////////////////////////////////////////////////////////////////////

class wxSpaceTransformExpDlg : public wxFB_SpaceTransformExpDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();

public:
	wxSpaceTransformExpDlg(wxWindow* parent, TSpaceTransform& spaceTransform);
	~wxSpaceTransformExpDlg();

private:
	TSpaceTransform*  m_spaceTransform;
};


#endif //__SpaceTransformExpDlg__
