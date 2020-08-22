///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformTools.h
// Purpose:     Space transform utilities
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "SpaceTransform.meta"

// wxImpExpUI headers
#include "SpaceTransformTools.h"



static UnitInfo s_unitInfos[] = 
{
	UnitInfo(SETUPUNIT_INCH, _T("inch"), _("inch"), 2.54f),
	UnitInfo(SETUPUNIT_FOOT, _T("foot"), _("foot"), 30.48f),
	UnitInfo(SETUPUNIT_MILE, _T("mile"), _("mile"), 160934.4f),
	UnitInfo(SETUPUNIT_MILLIMETER, _T("millimeter"), _("millimeter"), 0.1f),
	UnitInfo(SETUPUNIT_CENTIMETER, _T("centimeter"), _("centimeter"), 1.f),
	UnitInfo(SETUPUNIT_METER, _T("meter"), _("meter"), 100.f),
	UnitInfo(SETUPUNIT_KILOMETER, _T("kilometer"), _("kilometer"), 100000.f)
};

size_t GetNumUnitInfos()
{
	return sizeof(s_unitInfos) / sizeof(s_unitInfos[0]);
}

const UnitInfo& GetUnitInfo(size_t index)
{
	return s_unitInfos[index];
}

void WriteSpaceTransformConfig(TSpaceTransform& spaceTransform)
{
	wxConfigBase* pConfig = wxConfigBase::Get();	
	int setupUnit = spaceTransform.GetSetupUnit();
	wxString strSetupUnit;
	if(setupUnit == SETUPUNIT_NONE)
	{
		strSetupUnit = _T("none");
	}
	else
	{
		for(size_t i = 0; i < GetNumUnitInfos(); ++i)
			if(GetUnitInfo(i).setupUnit == setupUnit)
			{
				strSetupUnit = GetUnitInfo(i).engUnitName;
				break;
			}
	}
	pConfig->Write(_T("SpaceTransform/SetupUnit"), strSetupUnit);
	pConfig->Write(_T("SpaceTransform/SystemUnitsPerFileUnit"), spaceTransform.GetSystemUnitsPerFileUnit());
	pConfig->Write(_T("SpaceTransform/FileUnitsPerSystemUnit"), spaceTransform.GetFileUnitsPerSystemUnit());
}

void ReadSpaceTransformConfig(TSpaceTransform& spaceTransform)
{
	wxConfigBase* pConfig = wxConfigBase::Get();	

	double scaleCoef = spaceTransform.GetSystemUnitsPerFileUnit();
	pConfig->Read(_T("SpaceTransform/SystemUnitsPerFileUnit"), &scaleCoef, scaleCoef);
	spaceTransform.SetSystemUnitsPerFileUnit( (float)scaleCoef );

	int setupUnit = spaceTransform.GetSetupUnit();
	wxString strSetupUnit;
	if(pConfig->Read(_T("SpaceTransform/SetupUnit"), &strSetupUnit))
	{
		if(strSetupUnit == _T("none"))
		{
			setupUnit = SETUPUNIT_NONE;
		}
		else
		{
			for(size_t i = 0; i < GetNumUnitInfos(); ++i)
				if(GetUnitInfo(i).engUnitName == strSetupUnit)
				{
					setupUnit = GetUnitInfo(i).setupUnit;
					break;
				}
		}
	}
	else
	{
		for(size_t i = 0; i < GetNumUnitInfos(); ++i)
			if(fabsf(GetUnitInfo(i).cmsInUnit * scaleCoef - 1) < 0.0001f)
			{
				setupUnit = GetUnitInfo(i).setupUnit;
				break;
			}
	}
	spaceTransform.SetSetupUnit(setupUnit);
}

