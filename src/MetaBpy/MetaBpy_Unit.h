///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Unit.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Valid values for system unit type
#define UNITTYPE_INCH		0
#define UNITTYPE_FOOT		1
#define UNITTYPE_MILE		2
#define UNITTYPE_MILLIMETER	3
#define UNITTYPE_CENTIMETER	4
#define UNITTYPE_METER		5
#define UNITTYPE_KILOMETER	6

// Set system unit
#define SET_SYSTEM_UNIT(unitType)		pass

// Default number of system units per 1 file unit
#define DEFAULT_SYSTEM_UNITS_PER_FILE_UNIT	0.01

// Default number of file units per 1 system unit
#define DEFAULT_FILE_UNITS_PER_SYSTEM_UNIT	100

