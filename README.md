# KRXIMPEXP REWORKED

KrxImpExp is open source import and export plugins for games "Gothic" and "Gothic II". These plugins are intended for modders and make possible to import and export 3DS files to/from 3D Editor, and import and export ASC files too. These 3DS and ASC files are used for creating or editing 3D models (armors, weapons, characters, monsters, levels, etc.) The plugins also make possible to import from three internal "Gothic" file formats for meshes: MSH (compiled mesh), MRM (multi-resolution mesh), ZEN (zengin world).
  
Originally created by Vitaly "Kerrax" Baranov who abandoned plugin development in 2012. 

Old project website: [LINK](http://krximpexp.sourceforge.net/)

This project is focused to make plugin compatible with newer version of software and optimize building workflow.


# Dependencies

 - Microsoft Visual Studio 2019
 - [Wave C++ preprocessor](http://www.codeproject.com/KB/recipes/wave_preprocessor.aspx) - a special tool to make precompiled version of C++ code.
 - [Sed](http://gnuwin32.sourceforge.net/packages/sed.htm) - a stream editor.
 - [wxWidgets](http://www.wxwidgets.org/downloads/) - open source cross-platform GUI and tools library.
 - The SDK of the program you want to build the plugin for.


# How to build

Go to the "build\" folder, copy **"config.reg.copyme"** file and rename it to **"config.reg"**. Correct paths to installed software in file "config.reg". If you don't have software just comment the line with ";" (Some build targets will most likely not work) . Merge file with your registry.

Go to the "build\vc\" folder and compile "wxImpExpUI.sln" with Microsoft Visual Studio 2019.
Ensure that you have installed and compiled wxWidgets with "UNICODE Debug" configuration before it.

## 3ds Max

 1. Go to the "build\vc\" folder and compile "Max_allprj.sln".
 A configuration's name specifies 3ds max version, for example:
"Debug5" is a debug configuration for 3ds max 5,
"Release6" is a release configuration for 3ds max 6,
"Release7" is a release configuration for 3ds max 7-8,
"Debug9" is a debug configuration for 3ds max 9-2008, 32-bit,
"Release11" is a release configuration for 3ds max 2009, 32-bit,
"Release11_x64" is a release configuration for 3ds max 2009, 64-bit,
and so on.
 2. Go to the "build\batch\" folder and run file "Max_BuildAll"
## GMax

 1. Go to the "build\vc\" folder and compile "GMaxExtender.sln".
 2. Go to the "build\batch\" folder and run file "GMax_BuildAll"

## Blender
1. Go to the "build\batch\" folder and run file "Blender_BuildAll"

## Cinema4D
 1. Go to the "build\vc\" folder and compile C4D_allprj.sln.  
 A configuration's name specifies cinema 4d's SDK version, for example:
	    "Debug11" is a debug configuration for Cinema 4D Release 11,     
	    "Release96" is a release configuration for Cinema 4D Release 9.6,*
	    
 2. Go to the "build\batch\" folder and run file "C4D_BuildAll"
 
Builds are located in "install" folder.
If you want to make installer, go to "release\\" folder and run adequate generator. 

# Contents of src folder

- **IPhysique** - a plugin for 3ds max (all versions) to enable operation with Physique modifier from MAXScript; this plugin written by Adam Felt and updated by Neil Hazzard   
- **MaxImpExpUtil** - single MAXScript file providing panel in the "Utility" tab which can be used for running import/export scripts in other files 
-  **Meta** - common source files for importers and exporters for any 3D Editors; these files is written in a special language, named "Meta"; folders "MetaCpp", MetaMaxSdk", "MetaMaxScript", "MetaGMaxScript" implement this "Meta" language by defining macroses MetaCpp            - implementation of macroses used by the "Meta" language for 3D Editor's SDK based on C++ (for example, 3ds max sdk) MetaMaxSdk         - implementation of macroses used by the "Meta" language for 3ds max SDK (File "MetaMaxSdk.h" includes file "MetaMaxCpp.h")
- **MetaMaxScript** - implementation of macroses used by the "Meta" language for 3ds max MAXScript
-  **MetaGMaxScript** - implementation of macroses used by the "Meta" language for gmax MAXScript
- **MetaBpy** - implementation of macroses used by the "Meta" language for Blender Python
-   **tstl** - small library (written by PJ Arends) to use UNICODE strings with STL (this library used by wxImpExpUI application)
- **wxImpExpUI** - graphical frontend providing user interface for showing information about the current import/export process, getting additional parameters from user, and so on.


