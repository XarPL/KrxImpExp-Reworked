///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Exporter.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     April 10, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Return values for import/export functions
#define IMPEXP_FAIL		0
#define IMPEXP_SUCCESS	1
#define IMPEXP_CANCEL	2

// Main export function
// Example of arguments:
// impname: Imp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
#define EXPORT_FUNC(expname, ext, desc, author, year, version, maxida, maxidb, c4did) \
def register(): LINEBREAK \
___ register_exporter(#expname, ext, desc) LINEBREAK \
LINEBREAK \
def unregister(): LINEBREAK \
___ unregister_exporter(#expname) LINEBREAK \
LINEBREAK \
if __name__ == "main": LINEBREAK \
___ register() LINEBREAK \
LINEBREAK \
def expname(filename_param, quiet_param = False): LINEBREAK \
___ QUIET = quiet_param LINEBREAK \
___ EXPORT_FILE_NAME = filename_param INDENT
	
// Put it after import function's body
#define END_EXPORT_FUNC \
END_INDENT LINEBREAK \

// Call importer
#define CALL_EXPORTER(filename_param, quiet_param, expname, maxida, maxidb, c4did) \
	call_exporter(#expname, filepath = filename_param, quiet = quiet_param)
