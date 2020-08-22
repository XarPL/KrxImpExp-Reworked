///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Scene.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::tstring GetSceneFileName()
{
	String str = GetActiveDocument()->GetDocumentName().GetString();
	UWORD ubuf[MAX_PATH];
	str.GetUcBlockNull(ubuf, MAX_PATH);
	char filename[MAX_PATH];
	WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) ubuf, -1, filename, MAX_PATH, NULL, NULL);
	return (std::tstring) filename;
}

static void ResetScene()
{
	//GetActiveDocument()->Flush(); 
	BaseDocument* nw = BaseDocument::Alloc();
	InsertBaseDocument(nw);
	SetActiveDocument(nw);
}

// Returns the name of the current C4D file (but not the path). 
// For example, if the currently loaded file is "D:\MyDocs\SCENES\Expgears.c4d" 
// this method returns "Expgears.c4d". 
#define GET_SCENE_FILENAME					(GetSceneFileName())

// Resets the 3D Editor
#define RESET_SCENE							ResetScene();

