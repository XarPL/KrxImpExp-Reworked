///////////////////////////////////////////////////////////////////////////////
// Name:        TimeTransformExpDlg.cpp
// Purpose:     Implementation of class wxTimeTransformExpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "TimeTransform.meta"

// wxImpExpUI headers
#include "TimeTransformExpDlg.h"



////////////////////////////////////////////////////////////////////////////////
// wxTimeTransformExpDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxTimeTransformExpDlg::wxTimeTransformExpDlg(wxWindow* parent, TTimeTransform& timeTransform)
: wxFB_TimeTransformExpDlg(parent) 
{
	m_timeTransform = &timeTransform;

	// setup layout
	SetMinSize(GetSize());
	Center();
}

// Dtor
wxTimeTransformExpDlg::~wxTimeTransformExpDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wxTimeTransformExpDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	m_spinFirstInScene->SetMin(m_timeTransform->GetMinFrameInScene());
	m_spinFirstInScene->SetMax(m_timeTransform->GetMaxFrameInScene());
	m_spinLastInScene->SetMin(m_timeTransform->GetMinFrameInScene());
	m_spinLastInScene->SetMax(m_timeTransform->GetMaxFrameInScene());
	m_spinFirstInFile->SetMin(m_timeTransform->GetMinFrameInFile());
	m_spinFirstInFile->SetMax(m_timeTransform->GetMaxFrameInFile());

	m_spinFirstInScene->SetValue(m_timeTransform->GetStartFrameInScene());
	m_spinLastInScene->SetValue(m_timeTransform->GetEndFrameInScene());
	m_spinFirstInFile->SetValue(m_timeTransform->GetStartFrameInFile());
	UpdateRestValues();
	return true;
}

void wxTimeTransformExpDlg::UpdateRestValues()
{
	wxPoint pt = wxGetMousePosition();
	wxWindow* wnd = wxFindWindowAtPointer(pt);
	if(wnd != NULL)
		pt = wnd->ScreenToClient(pt);

	int frameLen = m_spinLastInScene->GetValue() - m_spinFirstInScene->GetValue() + 1;
	int value = m_spinFirstInFile->GetValue() + frameLen - 1;
	m_spinLastInFile->SetRange(value, value);
	m_spinLastInFile->SetValue(value);
	bool b;

	b = (frameLen >= 3);
	m_staticSecondFrame->Show(b);
	m_spinSecondInScene->Show(b);
	m_staticSecondArrow->Show(b);
	m_spinSecondInFile->Show(b);
	value = m_spinFirstInScene->GetValue() + 1;
	m_spinSecondInScene->SetRange(value, value);
	m_spinSecondInScene->SetValue(value);
	value = m_spinFirstInFile->GetValue() + 1;
	m_spinSecondInFile->SetRange(value, value);
	m_spinSecondInFile->SetValue(value);

	b = (frameLen >= 4);
	m_staticThirdFrame->Show(b);
	m_spinThirdInScene->Show(b);
	m_staticThirdArrow->Show(b);
	m_spinThirdInFile->Show(b);
	value = m_spinFirstInScene->GetValue() + 2;
	m_spinThirdInScene->SetRange(value, value);
	m_spinThirdInScene->SetValue(value);
	value = m_spinFirstInFile->GetValue() + 2;
	m_spinThirdInFile->SetRange(value, value);
	m_spinThirdInFile->SetValue(value);

	b = (frameLen >= 5);
	m_staticVDots->Show(b);

	Layout();
	Fit();
	SetMinSize(GetSize());

	if(wnd != NULL && wnd->IsShown())
		wnd->WarpPointer(pt.x, pt.y);
}

// Dialog data transfer (dialog controls -> output data file)
bool wxTimeTransformExpDlg::TransferDataFromWindow()
{
	m_timeTransform->SetStartFrameInScene(m_spinFirstInScene->GetValue());
	m_timeTransform->SetEndFrameInScene(m_spinLastInScene->GetValue());
	m_timeTransform->SetStartFrameInFile(m_spinFirstInFile->GetValue());
	m_timeTransform->SetEndFrameInFile(m_spinLastInFile->GetValue());
	return true;
}

// Command buttons
void wxTimeTransformExpDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxTimeTransformExpDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

// Events
void wxTimeTransformExpDlg::OnFirstInSceneChanged( wxSpinEvent& event )
{
	if(m_spinLastInScene->GetValue() < m_spinFirstInScene->GetValue())
		m_spinLastInScene->SetValue(m_spinFirstInScene->GetValue());
	UpdateRestValues();
}

void wxTimeTransformExpDlg::OnLastInSceneChanged( wxSpinEvent& event )
{
	if(m_spinFirstInScene->GetValue() > m_spinLastInScene->GetValue())
		m_spinFirstInScene->SetValue(m_spinLastInScene->GetValue());
	UpdateRestValues();
}

void wxTimeTransformExpDlg::OnFirstInFileChanged( wxSpinEvent& event )
{
	UpdateRestValues();
}

