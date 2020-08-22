///////////////////////////////////////////////////////////////////////////////
// Name:        TimeTransformExpDlg.h
// Purpose:     Declaration of class wxTimeTransformExpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __TimeTransformExpDlg__
#define __TimeTransformExpDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxTimeTransformExpDlg
///////////////////////////////////////////////////////////////////////////////

class wxTimeTransformExpDlg : public wxFB_TimeTransformExpDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	virtual void OnFirstInSceneChanged( wxSpinEvent& event );
	virtual void OnFirstInFileChanged( wxSpinEvent& event );
	virtual void OnLastInSceneChanged( wxSpinEvent& event );
	void UpdateRestValues();

public:
	wxTimeTransformExpDlg(wxWindow* parent, TTimeTransform& spaceTransform);
	~wxTimeTransformExpDlg();

private:
	TTimeTransform*  m_timeTransform;
};


#endif //__TimeTransformExpDlg__
