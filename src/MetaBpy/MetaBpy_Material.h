///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Material.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 12, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Material
#define TMATERIAL
#define INVALID_MATERIAL				None

// Create material
#define NEW_MATERIAL(name)				new_material(name)

// Get material name
#define GET_MATERIAL_NAME(mtl)			get_material_name(mtl)

// Set material name (all the materials have unique names)
#define SET_MATERIAL_NAME(mtl, name)	set_material_name(mtl, name)

// Get diffuse color of material
#define GET_DIFFUSE_COLOR(mtl)			get_diffuse_color(mtl)

// Set diffuse color of material
#define SET_DIFFUSE_COLOR(mtl, clr)		set_diffuse_color(mtl, clr)

// Get bitmap's filename of material's diffuse map
#define GET_DIFFUSE_MAP_FILENAME(mtl)	get_diffuse_map_filename(mtl)

// Set bitmap's filename  of material's diffuse map
#define SET_DIFFUSE_MAP_FILENAME(mtl, mapname)	set_diffuse_map_filename(mtl, mapname)
