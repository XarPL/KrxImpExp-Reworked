///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Importer.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Access to global variables
HINSTANCE GetInstance();
Interface* GetInterface();

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
\
static HINSTANCE s_hInstance = NULL; \
HINSTANCE GetInstance() \
{ \
	return s_hInstance; \
} \
\
static Interface* s_pInterface = NULL; \
\
Interface* GetInterface() \
{ \
	return s_pInterface; \
} \
\
BOOL WINAPI DllMain(HINSTANCE hinstDLL, ULONG fdwReason, LPVOID lpvReserved) \
{ \
	if(fdwReason == DLL_PROCESS_ATTACH) \
	{ \
		DebugPrint(_T("Initializing plugin...")); \
		s_hInstance = hinstDLL; \
	} \
	\
	return TRUE; \
} \
\
class impname##Plugin : public SceneImport \
{ \
public: \
	impname##Plugin() {mExt = ext; mDesc = desc; mAuthor = author; mCopyright = _T("Copyright ") + mAuthor + _T(" ") _T(#year);} \
	~impname##Plugin() {FreeStoredSelection();} \
	int		ExtCount() {return 1;} \
	const TCHAR * Ext(int n) {return mExt.c_str();} \
	const TCHAR * LongDesc() {return mDesc.c_str();} \
	const TCHAR * ShortDesc() {return mDesc.c_str();} \
	const TCHAR * AuthorName() {return mAuthor.c_str();} \
	const TCHAR * CopyrightMessage() {return mCopyright.c_str();} \
	const TCHAR * OtherMessage1() {return _T("");} \
	const TCHAR * OtherMessage2() {return _T("");} \
	unsigned int Version() {return (unsigned int) (version * 100);} \
	void	ShowAbout(HWND hWnd) {} \
	int     ZoomExtents() {return ZOOMEXT_YES;} \
	int		DoImport(const TCHAR *name, ImpInterface *ei, Interface *i, BOOL suppressPrompts); \
	int		__DoImport(const TCHAR *name, ImpInterface *ei, Interface *i, BOOL suppressPrompts); \
	void    StoreSelection(); \
	void    RestoreSelection(); \
	void    FreeStoredSelection(); \
private: \
	Tab<TCHAR*> mTabStoredSelection; \
	std::tstring mExt; \
	std::tstring mDesc; \
	std::tstring mAuthor; \
	std::tstring mCopyright; \
}; \
\
class impname##ClassDesc: public ClassDesc \
{ \
public: \
	int             IsPublic() {return 1;} \
	void *          Create(BOOL loading = FALSE) {return new impname##Plugin;} \
	const TCHAR *   ClassName() {return _T(#impname) _T("Plugin");} \
	SClass_ID       SuperClassID() {return SCENE_IMPORT_CLASS_ID;}  \
	Class_ID        ClassID() {return Class_ID(maxida, maxidb);} \
	const TCHAR*    Category() {return _T("Scene Import");} \
}; \
\
extern "C"  __declspec( dllexport ) const TCHAR* LibDescription() \
{ \
	static const std::tstring s_libdesc = ext + _T(" file importer (") + author + _T(")"); \
	return s_libdesc.c_str(); \
} \
\
extern "C" __declspec( dllexport ) int LibNumberClasses() \
{ \
	return 1; \
} \
\
extern "C" __declspec( dllexport ) ClassDesc* LibClassDesc(int i) \
{ \
	static impname##ClassDesc theClassDesc; \
	return &theClassDesc; \
} \
\
extern "C" __declspec( dllexport ) ULONG LibVersion() \
{ \
	return VERSION_3DSMAX; \
} \
\
int	impname##Plugin::DoImport(const TCHAR *filename, ImpInterface *ei, Interface *i, BOOL suppressPrompts) \
{ \
	s_pInterface = i; \
	int tskmod = GetInterface()->GetCommandPanelTaskMode(); \
	GetInterface()->SetCommandPanelTaskMode(TASK_MODE_CREATE); \
	StoreSelection(); \
	int r = __DoImport(filename, ei, i, suppressPrompts); \
	GetInterface()->SetCommandPanelTaskMode(tskmod); \
	RestoreSelection(); \
	return r; \
} \
\
void impname##Plugin::FreeStoredSelection() \
{ \
	for(int i = 0; i < mTabStoredSelection.Count(); ++i) \
		free(mTabStoredSelection[i]); \
	mTabStoredSelection.SetCount(0); \
} \
\
void impname##Plugin::StoreSelection() \
{ \
	FreeStoredSelection(); \
	for(int i = 0; i < GetInterface()->GetSelNodeCount(); ++i) \
	{ \
		TCHAR* psz = _tcsdup(GetInterface()->GetSelNode(i)->GetName()); \
		mTabStoredSelection.Append(1, &psz); \
	} \
} \
\
void impname##Plugin::RestoreSelection() \
{ \
	GetInterface()->ClearNodeSelection(); \
	for(int i = 0; i < mTabStoredSelection.Count(); ++i) \
	{ \
		INode* node = GetInterface()->GetINodeByName(mTabStoredSelection[i]); \
		if(node) \
			GetInterface()->SelectNode(node); \
	} \
} \
\
int	impname##Plugin::__DoImport(const TCHAR *filename, ImpInterface *ei, Interface *i, BOOL suppressPrompts) \
{ \
	std::tstring IMPORT_FILE_NAME = filename; \
	int IMPORT_FILE_SIZE = FILE_SIZE(filename); \
	bool QUIET = (suppressPrompts != 0);
	
// Put it after import function's body
#define END_IMPORT_FUNC }

// Call importer
#define CALL_IMPORTER(filename, quiet, impname, maxida, maxidb, c4did) \
	(GetInterface()->ImportFromFile((filename).c_str(), (quiet), &Class_ID((maxida), (maxidb))));

