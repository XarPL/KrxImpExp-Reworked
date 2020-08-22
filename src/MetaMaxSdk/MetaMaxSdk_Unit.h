///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Unit.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static void SetSystemUnit(int unitType)
{	
	SetMasterUnitInfo(unitType, 1.0f);
	DispInfo info;
	GetUnitDisplayInfo(&info);
	if(info.dispType != UNITDISP_GENERIC)
	{
		switch(unitType)
		{
			case UNITS_MILLIMETERS: 
				info.dispType = UNITDISP_METRIC; 
				info.metricDisp = UNIT_METRIC_DISP_MM; 
				break;
			case UNITS_CENTIMETERS: 
				info.dispType = UNITDISP_METRIC; 
				info.metricDisp = UNIT_METRIC_DISP_CM; 
				break;
			case UNITS_METERS: 
				info.dispType = UNITDISP_METRIC; 
				info.metricDisp = UNIT_METRIC_DISP_M; 
				break;
			case UNITS_KILOMETERS: 
				info.dispType = UNITDISP_METRIC; 
				info.metricDisp = UNIT_METRIC_DISP_KM; 
				break;
			case UNITS_FEET: 
				info.dispType = UNITDISP_US; 
				info.usDisp = UNIT_US_DISP_DEC_FT; 
				break;
			case UNITS_INCHES: 
				info.dispType = UNITDISP_US; 
				info.usDisp = UNIT_US_DISP_DEC_IN; 
				break;
			case UNITS_MILES: 
				info.dispType = UNITDISP_CUSTOM; 
				info.customName = _T("ml"); 
				info.customValue = 1.609344f;
				info.customUnit = UNITS_KILOMETERS;
				break;
		}
		SetUnitDisplayInfo(&info);
	}
}

// Valid values for unit types:
#define UNITTYPE_INCH		UNITS_INCHES
#define UNITTYPE_FOOT		UNITS_FEET
#define UNITTYPE_MILE		UNITS_MILES
#define UNITTYPE_MILLIMETER	UNITS_MILLIMETERS
#define UNITTYPE_CENTIMETER	UNITS_CENTIMETERS
#define UNITTYPE_METER		UNITS_METERS
#define UNITTYPE_KILOMETER	UNITS_KILOMETERS

// Set system units
#define SET_SYSTEM_UNIT(systemUnitType)		SetSystemUnit(systemUnitType);

// Default number of system units per 1 file unit
#define DEFAULT_SYSTEM_UNITS_PER_FILE_UNIT	1

// Default number of file units per 1 system unit
#define DEFAULT_FILE_UNITS_PER_SYSTEM_UNIT	1

