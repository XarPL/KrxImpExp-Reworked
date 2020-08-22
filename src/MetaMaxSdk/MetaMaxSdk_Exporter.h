///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Exporter.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Access to global variables
HINSTANCE GetInstance();
Interface* GetInterface();

// Main export function
// Example of arguments:
// expname: Exp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
#define EXPORT_FUNC(expname, ext, desc, author, year, version, maxida, maxidb, c4did) \
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
class expname##Plugin : public SceneExport \
{ \
public: \
	expname##Plugin() {mExt = ext; mDesc = desc; mAuthor = author; mCopyright = _T("Copyright ") + mAuthor + _T(" ") _T(#year);} \
	~expname##Plugin() {FreeStoredSelection();} \
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
	int     ZoomExtents() {return ZOOMEXT_NO;} \
	BOOL	SupportsOptions(int, DWORD options) {return (options == SCENE_EXPORT_SELECTED) ? TRUE : FALSE;} \
	int		DoExport(const TCHAR *name, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options); \
	int		__DoExport(const TCHAR *name, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options); \
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
class expname##ClassDesc: public ClassDesc \
{ \
public: \
	int             IsPublic() {return 1;} \
	void *          Create(BOOL loading = FALSE) {return new expname##Plugin;} \
	const TCHAR *   ClassName() {return _T(#expname) _T("Plugin");} \
	SClass_ID       SuperClassID() {return SCENE_EXPORT_CLASS_ID;}  \
	Class_ID        ClassID() {return Class_ID(maxida, maxidb);} \
	const TCHAR*    Category() {return _T("Scene Export");} \
}; \
\
extern "C"  __declspec( dllexport ) const TCHAR* LibDescription() \
{ \
	static const std::tstring s_libdesc = ext + _T(" file exporter (") + author + _T(")"); \
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
	static expname##ClassDesc theClassDesc; \
	return &theClassDesc; \
} \
\
extern "C" __declspec( dllexport ) ULONG LibVersion() \
{ \
	return VERSION_3DSMAX; \
} \
\
int	expname##Plugin::DoExport(const TCHAR *filename, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options) \
{ \
	s_pInterface = i; \
	int tskmod = GetInterface()->GetCommandPanelTaskMode(); \
	GetInterface()->SetCommandPanelTaskMode(TASK_MODE_CREATE); \
	StoreSelection(); \
	int r = __DoExport(filename, ei, i, suppressPrompts, options); \
	GetInterface()->SetCommandPanelTaskMode(tskmod); \
	RestoreSelection(); \
	return r; \
} \
\
void expname##Plugin::FreeStoredSelection() \
{ \
	for(int i = 0; i < mTabStoredSelection.Count(); ++i) \
		free(mTabStoredSelection[i]); \
	mTabStoredSelection.SetCount(0); \
} \
\
void expname##Plugin::StoreSelection() \
{ \
	FreeStoredSelection(); \
	for(int i = 0; i < GetInterface()->GetSelNodeCount(); ++i) \
	{ \
		TCHAR* psz = _tcsdup(GetInterface()->GetSelNode(i)->GetName()); \
		mTabStoredSelection.Append(1, &psz); \
	} \
} \
\
void expname##Plugin::RestoreSelection() \
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
int expname##Plugin::__DoExport(const TCHAR *filename, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options) \
{ \
	std::tstring EXPORT_FILE_NAME = filename; \
	bool QUIET = (suppressPrompts != 0);


// Put it after export function's body
#define END_EXPORT_FUNC }

// Call exporter
#define CALL_EXPORTER(filename, quiet, expname, maxida, maxidb, c4did) \
	(GetInterface()->ExportToFile((filename).c_str(), (quiet), 0, &Class_ID((maxida), (maxidb))));

