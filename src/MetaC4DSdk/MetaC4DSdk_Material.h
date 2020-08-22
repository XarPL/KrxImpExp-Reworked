///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Material.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static BaseMaterial* NewMtl(const std::tstring& name)
{
	BaseDocument* doc = GetActiveDocument();

	BaseMaterial* mat = doc->GetFirstMaterial();
	std::tstring tstr;
	while(mat)
	{
		const String& str = mat->GetName();
		int len = str.GetCStringLen();
		tstr.reserve(len);
		str.GetCString(&tstr[0], len + 1);
		if(_tcsicmp(tstr.c_str(), name.c_str()) == 0)
			break;
		mat = mat->GetNext();
	}

	Material* mmat = NULL;
	if(mat != NULL && mat->GetType() == Mmaterial)
	{
		mmat = (Material*) mat;
	}
	else
	{
		mmat = Material::Alloc();
		doc->InsertMaterial(mmat, NULL, FALSE);
		mmat->SetName(name.c_str());
	}
	mmat->SetChannelState(CHANNEL_COLOR, TRUE);
	mmat->SetChannelState(CHANNEL_LUMINANCE, FALSE);
	mmat->SetChannelState(CHANNEL_TRANSPARENCY, FALSE);
	mmat->SetChannelState(CHANNEL_REFLECTION, FALSE);
	mmat->SetChannelState(CHANNEL_ENVIRONMENT, FALSE);
	mmat->SetChannelState(CHANNEL_FOG, FALSE);
	mmat->SetChannelState(CHANNEL_BUMP, FALSE);
	mmat->SetChannelState(CHANNEL_ALPHA, FALSE);
	mmat->SetChannelState(CHANNEL_SPECULAR, FALSE);
	mmat->SetChannelState(CHANNEL_SPECULARCOLOR, FALSE);
	mmat->SetChannelState(CHANNEL_GLOW, FALSE);
	mmat->SetChannelState(CHANNEL_DISPLACEMENT, FALSE);
	mmat->SetChannelState(CHANNEL_DIFFUSION, FALSE);
	return mmat;
}

inline std::tstring GetMaterialName(BaseMaterial* mat)
{
	String str = mat->GetName();
	int len = str.GetCStringLen();
	std::tstring tstr(len, ' ');
	str.GetCString(&tstr[0], len + 1);
	return tstr;
}

inline void SetMaterialName(BaseMaterial* mat, const std::tstring& name)
{
	mat->SetName(name.c_str());
}

static Vector GetDiffuseColor(BaseMaterial* mat)
{
	Vector clr(0.8f, 0.8f, 0.8f);
	if(mat->GetType() == Mmaterial)
	{
		Material* mmat = (Material*) mat;
		if(mmat->GetChannelState(CHANNEL_COLOR))
		{
			BaseChannel* channel = mmat->GetChannel(CHANNEL_COLOR);
			BaseContainer bc = channel->GetData();
			clr = bc.GetVector(BASECHANNEL_COLOR_EX);
		}
	}
	return clr;
}

static void SetDiffuseColor(BaseMaterial* mat, const Vector& clr)
{
	if(mat->GetType() == Mmaterial)
	{
		Material* mmat = (Material*) mat;
		mmat->SetChannelState(CHANNEL_COLOR, TRUE);
		BaseChannel* channel = mmat->GetChannel(CHANNEL_COLOR);
		BaseContainer bc = channel->GetData();
		bc.SetVector(BASECHANNEL_COLOR_EX, clr);
		channel->SetData(bc);
		mmat->Update(TRUE, TRUE);
	}	
}

static std::tstring GetDiffuseMapFilename(BaseMaterial* mat)
{
	std::tstring mapname;
	if(mat->GetType() == Mmaterial)
	{
		Material* mmat = (Material*) mat;
		if(mmat->GetChannelState(CHANNEL_COLOR))
		{
			BaseChannel* channel = mat->GetChannel(CHANNEL_COLOR);
			BaseContainer bc = channel->GetData();
			String name_str = bc.GetString(BASECHANNEL_TEXTURE);
			CHAR name_sz[MAX_PATH];
			name_str.GetCString(name_sz, MAX_PATH);
			mapname = name_sz;
		}
	}
	return mapname;
}

static void SetDiffuseMapFilename(BaseMaterial* mat, const std::string& mapname)
{
	if(mat->GetType() == Mmaterial)
	{
		Material* mmat = (Material*) mat;
		mmat->SetChannelState(CHANNEL_COLOR, TRUE);
		BaseChannel* channel = mmat->GetChannel(CHANNEL_COLOR);
		BaseContainer bc = channel->GetData();
		bc.SetString(BASECHANNEL_TEXTURE, mapname.c_str());
		channel->SetData(bc);
		mmat->Update(TRUE, TRUE);
	}
}	

// Material
#define TMATERIAL						BaseMaterial*
#define INVALID_MATERIAL				NULL

// Create material
#define NEW_MATERIAL(name)				NewMtl(name)

// Set material name (all the materials have unique names)
#define SET_MATERIAL_NAME(mtl, name)	SetMaterialName(mtl, name);

// Get material name
#define GET_MATERIAL_NAME(mtl)			(GetMaterialName(mtl))

// Set diffuse color of material
#define SET_DIFFUSE_COLOR(mtl, clr)		SetDiffuseColor(mtl, clr);

// Get diffuse color of material
#define GET_DIFFUSE_COLOR(mtl)			(GetDiffuseColor(mtl))

// Set bitmap's filename  of material's diffuse map
#define SET_DIFFUSE_MAP_FILENAME(mtl, mapname)	SetDiffuseMapFilename(mtl, mapname);

// Get bitmap's filename of material's diffuse map
#define GET_DIFFUSE_MAP_FILENAME(mtl)			GetDiffuseMapFilename(mtl)
