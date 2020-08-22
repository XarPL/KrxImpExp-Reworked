///////////////////////////////////////////////////////////////////////////////
// Name:        TimeTransformImpDlg.h
// Purpose:     Declaration of class wxTimeTransformImpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __TimeTransformImpDlg__
#define __TimeTransformImpDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxTimeTransformImpDlg
///////////////////////////////////////////////////////////////////////////////

class wxTimeTransformImpDlg : public wxFB_TimeTransformImpDlg
{
protected:
	virtual void OnOK( wxCommandEvent& event );
	virtual void OnCancel( wxCommandEvent& event );
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	virtual void OnFirstInFileChanged( wxSpinEvent& event );
	virtual void OnFirstInSceneChanged( wxSpinEvent& event );
	virtual void OnLastInFileChanged( wxSpinEvent& event );
	void UpdateRestValues();

public:
	wxTimeTransformImpDlg(wxWindow* parent, TTimeTransform& spaceTransform);
	~wxTimeTransformImpDlg();

private:
	TTimeTransform*  m_timeTransform;
};


#endif //__TimeTransformImpDlg__
