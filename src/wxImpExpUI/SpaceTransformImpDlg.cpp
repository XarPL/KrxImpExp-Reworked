///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformImpDlg.cpp
// Purpose:     Implementation of class wxSpaceTransformImpDlg.
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "SpaceTransform.meta"

// wxImpExpUI headers
#include "SpaceTransformImpDlg.h"
#include "SpaceTransformTools.h"



////////////////////////////////////////////////////////////////////////////////
// wxSpaceTransformImpDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxSpaceTransformImpDlg::wxSpaceTransformImpDlg(wxWindow* parent, TSpaceTransform& spaceTransform)
: wxFB_SpaceTransformImpDlg(parent) 
{
	m_spaceTransform = &spaceTransform;

	// setup layout
	SetMinSize(GetSize());
	Center();
}

// Dtor
wxSpaceTransformImpDlg::~wxSpaceTransformImpDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wxSpaceTransformImpDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	size_t i;
	for(i = 0; i < GetNumUnitInfos(); ++i)
		m_choiceSystemUnit->Append(wxGetTranslation(GetUnitInfo(i).engUnitName));

	int setupUnit = m_spaceTransform->GetSetupUnit();
	if(setupUnit == SETUPUNIT_NONE)
	{
		m_radioKeepCurSettings->SetValue(true);
		m_choiceSystemUnit->SetSelection(-1);
		m_choiceSystemUnit->Enable(false);
	}	
	else
	{
		m_radioSetupSystemUnit->SetValue(true);
		for(i = 0; i < GetNumUnitInfos(); ++i)
		{
			if(GetUnitInfo(i).setupUnit == setupUnit)
			{
				m_choiceSystemUnit->SetSelection(i);
				break;
			}
		}
	}

	float scaleCoef = m_spaceTransform->GetSystemUnitsPerFileUnit();
	m_textScaleCoef->SetValue(FLOAT_TO_STRING(scaleCoef));
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxSpaceTransformImpDlg::TransferDataFromWindow()
{
	wxConfigBase *pConfig = wxConfigBase::Get();

	
	float scaleCoef = STRING_TO_FLOAT(std::tstring(m_textScaleCoef->GetValue()));
	if(scaleCoef == INVALID_FLOAT || scaleCoef <= 0)
	{
		m_textScaleCoef->SetFocus();
		wxMessageDialog msgdlg(this, _("A positive floating-point number expected."), _("Error"), wxOK|wxICON_EXCLAMATION);
		msgdlg.ShowModal();
		return false;
	}
	m_spaceTransform->SetSystemUnitsPerFileUnit(scaleCoef);

	int setupUnit = SETUPUNIT_NONE;
	if(m_radioSetupSystemUnit->GetValue())
	{
		if(m_choiceSystemUnit->GetSelection() != -1)
			setupUnit = GetUnitInfo(m_choiceSystemUnit->GetSelection()).setupUnit;
	}
	m_spaceTransform->SetSetupUnit(setupUnit);
	
	WriteSpaceTransformConfig(*m_spaceTransform);
	return true;
}

// Command buttons
void wxSpaceTransformImpDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxSpaceTransformImpDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

// Enable controls depending on other controls
void wxSpaceTransformImpDlg::OnRadioChanged( wxCommandEvent& event )
{
	if(m_radioKeepCurSettings->GetValue())
	{
		m_choiceSystemUnit->Enable(false);
	}
	else
	{
		m_choiceSystemUnit->Enable(true);
		if(m_choiceSystemUnit->GetSelection() == -1)
			m_choiceSystemUnit->SetSelection(0);
	}
}

void wxSpaceTransformImpDlg::OnSystemUnitChanged( wxCommandEvent& event )
{
	int sel = m_choiceSystemUnit->GetSelection();
	if(sel != -1)
	{
		float cmsInUnit = GetUnitInfo(sel).cmsInUnit;
		m_textScaleCoef->SetValue(FLOAT_TO_STRING(1 / cmsInUnit));
	}
}
