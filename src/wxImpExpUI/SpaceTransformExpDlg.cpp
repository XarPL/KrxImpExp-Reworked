///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformExpDlg.cpp
// Purpose:     Implementation of class wxSpaceTransformExpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "SpaceTransform.meta"

// wxImpExpUI headers
#include "SpaceTransformExpDlg.h"
#include "SpaceTransformTools.h"



////////////////////////////////////////////////////////////////////////////////
// wxSpaceTransformExpDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxSpaceTransformExpDlg::wxSpaceTransformExpDlg(wxWindow* parent, TSpaceTransform& spaceTransform)
: wxFB_SpaceTransformExpDlg(parent) 
{
	m_spaceTransform = &spaceTransform;

	// setup layout
	SetMinSize(GetSize());
	Center();
}

// Dtor
wxSpaceTransformExpDlg::~wxSpaceTransformExpDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wxSpaceTransformExpDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	float scaleCoef = m_spaceTransform->GetFileUnitsPerSystemUnit();
	m_textScaleCoef->SetValue(FLOAT_TO_STRING(scaleCoef));
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxSpaceTransformExpDlg::TransferDataFromWindow()
{
	wxConfigBase *pConfig = wxConfigBase::Get();

	float scaleCoef = STRING_TO_FLOAT(std::tstring(m_textScaleCoef->GetValue().c_str()));
	if(scaleCoef == INVALID_FLOAT || scaleCoef <= 0)
	{
		m_textScaleCoef->SetFocus();
		wxMessageDialog msgdlg(this, _("A positive floating-point number expected."), _("Error"), wxOK|wxICON_EXCLAMATION);
		msgdlg.ShowModal();
		return false;
	}
	m_spaceTransform->SetFileUnitsPerSystemUnit(scaleCoef);

	WriteSpaceTransformConfig(*m_spaceTransform);
	return true;
}

// Command buttons
void wxSpaceTransformExpDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxSpaceTransformExpDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

