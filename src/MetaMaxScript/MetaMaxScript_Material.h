///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Material.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Get filename of material's diffuse bitmap
function GetDiffuseMapFilename mtl =
(
	local mapname = ""
	if (classOf (mtl) == StandardMaterial) and (classOf (mtl).maps[2] == BitmapTexture) then
	(		
		mapname = (mtl).maps[2].filename
	)
	local i = mapname.count
	while i >= 1 do
	(
		if mapname[i] == "\\" or mapname[i] == "/" then
		(
			mapname = substring mapname (i + 1) (mapname.count - i)
			exit
		)
		i = i - 1
	)
	return mapname
)

// Set filename of material's diffuse bitmap
function SetDiffuseMapFilename mtl mapname =
(
	mtl.maps[2] = (BitmapTexture filename:(mapname))
	ShowTextureMap mtl mtl.maps[2] on
)

// Material
#define TMATERIAL						StandardMaterial
#define INVALID_MATERIAL				undefined

// Create material
#define NEW_MATERIAL(nam)				(standardMaterial name:(nam))

// Set material name (all the materials have unique names)
#define SET_MATERIAL_NAME(mtl, nam)		mtl.name = (nam)

// Get material name
#define GET_MATERIAL_NAME(mtl)			((mtl).name)

// Set diffuse color of material
#define SET_DIFFUSE_COLOR(mtl, clr)		mtl.diffuse = (clr)

// Get diffuse color of material
#define GET_DIFFUSE_COLOR(mtl)			((mtl).diffuse)

// Set bitmap's filename  of material's diffuse map
#define SET_DIFFUSE_MAP_FILENAME(mtl, mapname)	SetDiffuseMapFilename (mtl) (mapname)

// Get bitmap's filename of material's diffuse map
#define GET_DIFFUSE_MAP_FILENAME(mtl)			(GetDiffuseMapFilename(mtl))

