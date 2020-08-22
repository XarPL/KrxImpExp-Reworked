///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_StdDirs.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Get main folder with plugins. 
// For example, "C:\\Program Files\\Blender Foundation\\Blender\\2.59\\scripts\\addons\\" 
#define ROOT_DIR		get_root_dir()

// Get folder for plug-in configuration files. 
// For example, "C:\\Documents and Settings\\User\\Application Data\\Blender Foundation\Blender\\2.59\\config" 
#define PLUGCFG_DIR		get_plugcfg_dir()

