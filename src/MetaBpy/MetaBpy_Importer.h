///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Importer.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 15, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Return values for import/export functions
#define IMPEXP_FAIL		0
#define IMPEXP_SUCCESS	1
#define IMPEXP_CANCEL	2

// Main import function
// Example of arguments:
// impname: Imp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
#define IMPORT_FUNC(impname, ext, desc, author, year, version, maxida, maxidb, c4did) \
def register(): LINEBREAK \
___ register_importer(#impname, ext, desc) LINEBREAK \
LINEBREAK \
def unregister(): LINEBREAK \
___ unregister_importer(#impname) LINEBREAK \
LINEBREAK \
if __name__ == "main": LINEBREAK \
___ register() LINEBREAK \
LINEBREAK \
def impname(filename_param, quiet_param = False): LINEBREAK \
___ QUIET = quiet_param LINEBREAK \
___ IMPORT_FILE_NAME = filename_param LINEBREAK \
___ IMPORT_FILE_SIZE = get_file_size(IMPORT_FILE_NAME) INDENT

// Put it after import function's body
#define END_IMPORT_FUNC \
END_INDENT LINEBREAK \

// Call importer
#define CALL_IMPORTER(filename_param, quiet_param, impname, maxida, maxidb, c4did) \
	call_importer(#impname, filepath = filename_param, quiet = quiet_param)
