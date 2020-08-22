///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Material.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static Mtl* NewMtl(const std::tstring& name)
{
	StdMat* pMtl = NewDefaultStdMat();
	pMtl->SetName(name.c_str());
	return pMtl;
}

inline std::tstring GetMaterialName(const Mtl* pMtl)
{
	return (std::tstring) ((Mtl*)pMtl)->GetName().data();
}

inline void SetMaterialName(Mtl* pMtl, const std::tstring& name)
{
	pMtl->SetName( (TCHAR*)(name.c_str()) );
}

static std::tstring GetDiffuseMapFilename(const Mtl* pMtl)
{
	std::tstring mapname;
	if(((Mtl*)pMtl)->ClassID() == Class_ID(DMTL_CLASS_ID, 0) 
		|| ((Mtl*)pMtl)->ClassID() == Class_ID(DMTL2_CLASS_ID, 0))
	{
		Texmap* pTexmap = ((Mtl*)pMtl)->GetSubTexmap(ID_DI);
		if (pTexmap != NULL && pTexmap->ClassID() == Class_ID(BMTEX_CLASS_ID, 0))
		{
			BitmapTex *pBmt = (BitmapTex*) pTexmap;
			mapname = pBmt->GetMapName();
			size_t slashpos1 = mapname.rfind(_T('\\'));
			size_t slashpos2 = mapname.rfind(_T('/'));
			size_t slashpos = ((slashpos1 != -1) ? slashpos1 : slashpos2);
			if(slashpos != -1)
				mapname = mapname.substr(slashpos + 1);
		}
	}
	return mapname;
}

static void SetDiffuseMapFilename(Mtl* pMtl, const std::tstring& mapname)
{
	BitmapTex *pBmt = NewDefaultBitmapTex();
	pBmt->SetMapName((LPTSTR) (mapname.c_str()));
	pMtl->SetSubTexmap(ID_DI, pBmt);
	GetInterface()->ActivateTexture(pBmt, pMtl);
}	

// Material
#define TMATERIAL						Mtl*
#define INVALID_MATERIAL				NULL

// Create material
#define NEW_MATERIAL(name)				NewMtl(name)

// Set material name (all the materials have unique names)
#define SET_MATERIAL_NAME(mtl, name)	SetMaterialName(mtl, name);

// Get material name
#define GET_MATERIAL_NAME(mtl)			(GetMaterialName(mtl))

// Set diffuse color of material
#define SET_DIFFUSE_COLOR(mtl, clr)		mtl->SetDiffuse(clr, GetInterface()->GetTime());

// Get diffuse color of material
#define GET_DIFFUSE_COLOR(mtl)			((mtl)->GetDiffuse(GetInterface()->GetTime()))

// Set bitmap's filename  of material's diffuse map
#define SET_DIFFUSE_MAP_FILENAME(mtl, mapname)	SetDiffuseMapFilename(mtl, mapname);

// Get bitmap's filename of material's diffuse map
#define GET_DIFFUSE_MAP_FILENAME(mtl)			GetDiffuseMapFilename(mtl)
