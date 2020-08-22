///////////////////////////////////////////////////////////////////////////////
// Name:        TimeTransformImpDlg.cpp
// Purpose:     Implementation of class wxTimeTransformImpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "TimeTransform.meta"

// wxImpExpUI headers
#include "TimeTransformImpDlg.h"



////////////////////////////////////////////////////////////////////////////////
// wxTimeTransformImpDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxTimeTransformImpDlg::wxTimeTransformImpDlg(wxWindow* parent, TTimeTransform& timeTransform)
: wxFB_TimeTransformImpDlg(parent) 
{
	m_timeTransform = &timeTransform;

	// setup layout
	SetMinSize(GetSize());
	Center();
}

// Dtor
wxTimeTransformImpDlg::~wxTimeTransformImpDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wxTimeTransformImpDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	m_spinFirstInFile->SetMin(m_timeTransform->GetMinFrameInFile());
	m_spinFirstInFile->SetMax(m_timeTransform->GetMaxFrameInFile());
	m_spinLastInFile->SetMin(m_timeTransform->GetMinFrameInFile());
	m_spinLastInFile->SetMax(m_timeTransform->GetMaxFrameInFile());
	m_spinFirstInScene->SetMin(m_timeTransform->GetMinFrameInScene());
	m_spinFirstInScene->SetMax(m_timeTransform->GetMaxFrameInScene());

	m_spinFirstInFile->SetValue(m_timeTransform->GetStartFrameInFile());
	m_spinLastInFile->SetValue(m_timeTransform->GetEndFrameInFile());
	m_spinFirstInScene->SetValue(m_timeTransform->GetStartFrameInScene());
	UpdateRestValues();
	return true;
}

void wxTimeTransformImpDlg::UpdateRestValues()
{
	wxPoint pt = wxGetMousePosition();
	wxWindow* wnd = wxFindWindowAtPointer(pt);
	if(wnd != NULL)
		pt = wnd->ScreenToClient(pt);

	int frameLen = m_spinLastInFile->GetValue() - m_spinFirstInFile->GetValue() + 1;
	int value = m_spinFirstInScene->GetValue() + frameLen - 1;
	m_spinLastInScene->SetRange(value, value);
	m_spinLastInScene->SetValue(value);
	bool b;

	b = (frameLen >= 3);
	m_staticSecondFrame->Show(b);
	m_spinSecondInFile->Show(b);
	m_staticSecondArrow->Show(b);
	m_spinSecondInScene->Show(b);
	value = m_spinFirstInFile->GetValue() + 1;
	m_spinSecondInFile->SetRange(value, value);
	m_spinSecondInFile->SetValue(value);
	value = m_spinFirstInScene->GetValue() + 1;
	m_spinSecondInScene->SetRange(value, value);
	m_spinSecondInScene->SetValue(value);

	b = (frameLen >= 4);
	m_staticThirdFrame->Show(b);
	m_spinThirdInFile->Show(b);
	m_staticThirdArrow->Show(b);
	m_spinThirdInScene->Show(b);
	value = m_spinFirstInFile->GetValue() + 2;
	m_spinThirdInFile->SetRange(value, value);
	m_spinThirdInFile->SetValue(value);
	value = m_spinFirstInScene->GetValue() + 2;
	m_spinThirdInScene->SetRange(value, value);
	m_spinThirdInScene->SetValue(value);

	b = (frameLen >= 5);
	m_staticVDots->Show(b);

	Layout();
	Fit();
	SetMinSize(GetSize());

	if(wnd != NULL && wnd->IsShown())
		wnd->WarpPointer(pt.x, pt.y);
}

// Dialog data transfer (dialog controls -> output data file)
bool wxTimeTransformImpDlg::TransferDataFromWindow()
{
	m_timeTransform->SetStartFrameInFile(m_spinFirstInFile->GetValue());
	m_timeTransform->SetEndFrameInFile(m_spinLastInFile->GetValue());
	m_timeTransform->SetStartFrameInScene(m_spinFirstInScene->GetValue());
	m_timeTransform->SetEndFrameInScene(m_spinLastInScene->GetValue());
	return true;
}

// Command buttons
void wxTimeTransformImpDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxTimeTransformImpDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

// Events
void wxTimeTransformImpDlg::OnFirstInFileChanged( wxSpinEvent& event )
{
	if(m_spinLastInFile->GetValue() < m_spinFirstInFile->GetValue())
		m_spinLastInFile->SetValue(m_spinFirstInFile->GetValue());
	UpdateRestValues();
}

void wxTimeTransformImpDlg::OnLastInFileChanged( wxSpinEvent& event )
{
	if(m_spinFirstInFile->GetValue() > m_spinLastInFile->GetValue())
		m_spinFirstInFile->SetValue(m_spinLastInFile->GetValue());
	UpdateRestValues();
}

void wxTimeTransformImpDlg::OnFirstInSceneChanged( wxSpinEvent& event )
{
	UpdateRestValues();
}

