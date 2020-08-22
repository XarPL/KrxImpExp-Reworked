///////////////////////////////////////////////////////////////////////////////
// Name:        MeshInfoDlg.h
// Purpose:     Declaration of class wxMeshInfoDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __MeshInfoDlg__
#define __MeshInfoDlg__

#include "FB_ImpExpUI.h"

///////////////////////////////////////////////////////////////////////////////
/// Class wxMeshInfoDlg
///////////////////////////////////////////////////////////////////////////////

class wxMeshInfoDlg : public wxFB_MeshInfoDlg
{
protected:
	virtual void OnClose( wxCommandEvent& event );
	virtual void OnStopTimer( wxCommandEvent& event );
	virtual void OnTimer( wxTimerEvent& event );
	virtual bool TransferDataToWindow();
	virtual void UpdateCloseButton();

public:
	wxMeshInfoDlg(wxWindow* parent, TMeshInfoDlgInput& dlgInput, TMeshInfoDlgOutput& dlgOutput);
	~wxMeshInfoDlg();
	int ShowModal();

private:
	TMeshInfoDlgInput*	m_dlgInput;
	TMeshInfoDlgOutput*	m_dlgOutput;
	wxTimer				m_timer;
	int                 m_restSeconds;
};


#endif //__MeshInfoDlg__
