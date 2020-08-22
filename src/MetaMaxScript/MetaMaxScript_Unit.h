///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Unit.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal function
function SetSystemUnit unitType =
(
	units.SystemType = unitType
	units.SystemScale = 1.0
	if units.DisplayType != HASHGeneric then
	(
		case (unitType) of
		(
			HASHMillimeters:
			(
				units.DisplayType = HASHMetric 
				units.MetricType = HASHMillimeters
			)
			HASHCentimeters:
			(
				units.DisplayType = HASHMetric 
				units.MetricType = HASHCentimeters
			)
			HASHMeters:
			(
				units.DisplayType = HASHMetric 
				units.MetricType = HASHMeters
			)
			HASHKilometers:
			(
				units.DisplayType = HASHMetric 
				units.MetricType = HASHKilometers
			)
			HASHFeets:
			(
				units.DisplayType = HASHUS
				units.USType = HASHDec_Ft
			)
			HASHInches:
			(
				units.DisplayType = HASHUS
				units.USType = HASHDec_In
			)
			HASHMiles:
			(
				units.DisplayType = HASHcustom
				units.CustomName = "ml"
				units.CustomValue = 1.609344
				units.CustomUnit = HASHKilometers
			)
		)
	)
)

// Valid values for unit types
#define UNITTYPE_INCH		HASHInches
#define UNITTYPE_FOOT		HASHFeet
#define UNITTYPE_MILE		HASHMiles
#define UNITTYPE_MILLIMETER	HASHMillimeters
#define UNITTYPE_CENTIMETER	HASHCentimeters
#define UNITTYPE_METER		HASHMeters
#define UNITTYPE_KILOMETER	HASHKilometers

// Set system units
#define SET_SYSTEM_UNIT(systemUnitType)		SetSystemUnit (systemUnitType)

// Default number of system units per 1 file unit
#define DEFAULT_SYSTEM_UNITS_PER_FILE_UNIT	1

// Default number of file units per 1 system unit
#define DEFAULT_FILE_UNITS_PER_SYSTEM_UNIT	1

