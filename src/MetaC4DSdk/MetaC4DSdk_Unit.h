///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Unit.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static void SetSystemUnit(int unitType)
{	
	BaseContainer bc = GetWorldContainer();
	bc.SetBool(WPREF_UNITS_USEUNITS, TRUE);
	bc.SetLong(WPREF_UNITS_BASIC, unitType);
	SetWorldContainer(bc);
}

// Valid values for unit types:
#define UNITTYPE_INCH		UNIT_INCH
#define UNITTYPE_FOOT		UNIT_FEET
#define UNITTYPE_MILE		UNIT_MILE
#define UNITTYPE_MILLIMETER	UNIT_MM
#define UNITTYPE_CENTIMETER	UNIT_CM
#define UNITTYPE_METER		UNIT_M
#define UNITTYPE_KILOMETER	UNIT_KM

// Set system units
#define SET_SYSTEM_UNIT(systemUnitType)		SetSystemUnit(systemUnitType);

// Default number of system units per 1 file unit
#define DEFAULT_SYSTEM_UNITS_PER_FILE_UNIT	1

// Default number of file units per 1 system unit
#define DEFAULT_FILE_UNITS_PER_SYSTEM_UNIT	1

