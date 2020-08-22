///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Exporter.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 15, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Main export function
// Example of arguments:
// expname: Imp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
// c4did: 1000010
#define EXPORT_FUNC(expname, ext, desc, author, year, version, maxida, maxidb, c4did) \
class expname : public CommandData \
{ \
	static ImpExpInfo __info; \
	int __DoExport(); \
public: \
	static void SetInfo(const ImpExpInfo& info) {__info = info;} \
	virtual Bool Execute(BaseDocument *doc); \
}; \
\
Bool Register##expname(void) \
{ \
	static const std::tstring s_sExportExt = _T("Export *.") + ext; \
	return RegisterCommandPlugin(c4did, s_sExportExt.c_str(), 0, NULL, String(), gNew expname); \
} \
\
Bool PluginStart() \
{ \
	if (!Register##expname()) return FALSE; \
	return TRUE; \
} \
\
void PluginEnd() \
{ \
} \
\
Bool PluginMessage(long id, void* data) \
{ \
	if(id == c4did) \
	{ \
		const ImpExpInfo& info = *(ImpExpInfo*) data; \
		expname::SetInfo(info); \
		CallCommand(c4did); \
		return TRUE; \
	} \
	else if(id == C4DMSG_PRIORITY) \
	{ \
		SetPluginPriority(data, C4DPL_INIT_PRIORITY_PLUGINS); \
		return TRUE; \
	} \
	return FALSE; \
} \
\
ImpExpInfo expname::__info; \
\
Bool expname::Execute(BaseDocument *doc) \
{ \
	if(__info.GetFileName() == "") \
	{ \
		HWND hwndCinema4D = NULL; \
		while(hwndCinema4D = FindWindowEx(NULL, hwndCinema4D, NULL, NULL)) \
		{ \
			DWORD dwProcessId; \
			DWORD dwThreadId = GetWindowThreadProcessId(hwndCinema4D, &dwProcessId); \
			if(dwProcessId == GetCurrentProcessId()) \
				break; \
		} \
		String str = doc->GetDocumentName().GetString(); \
		UWORD ubuf[MAX_PATH]; \
		str.GetUcBlockNull(ubuf, MAX_PATH); \
		char filename[MAX_PATH]; \
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) ubuf, -1, filename, MAX_PATH, NULL, NULL); \
		size_t len = _tcslen(filename); \
		if(_tcsicmp(filename + len - 4, _T(".c4d")) == 0) \
		{ \
			filename[len - 4] = 0; \
		} \
		OPENFILENAME ofn; \
		ZeroMemory(&ofn, sizeof(OPENFILENAME)); \
		ofn.lStructSize = sizeof(OPENFILENAME); \
		ofn.hwndOwner = hwndCinema4D; \
		TCHAR bufFilter[MAX_PATH+1]; \
		_stprintf(bufFilter, "%s (*.%s)\0*.%s\0\0", desc.c_str(), ext.c_str(), ext.c_str()); \
		ofn.lpstrFilter = bufFilter; \
		ofn.nFilterIndex = 1; \
		ofn.lpstrFile = filename; \
		ofn.nMaxFile = MAX_PATH; \
		ofn.lpstrInitialDir = NULL; \
		ofn.lpstrTitle = "Select file to export"; \
		static const std::tstring s_sExt = ext; \
		ofn.lpstrDefExt = s_sExt.c_str(); \
		ofn.Flags = OFN_OVERWRITEPROMPT; \
		if(!ShowOpenFileDialog(&ofn, FALSE)) \
		{ \
			return IMPEXP_CANCEL; \
		} \
		__info.SetFileName(filename); \
	} \
	if(doc != GetActiveDocument()) \
	{ \
		SetActiveDocument(doc); \
	} \
	DrawViews(DRAWFLAGS_NO_THREAD); \
	int r = __DoExport(); \
	__info.Reset(); \
	return r == IMPEXP_SUCCESS; \
} \
\
int expname::__DoExport() \
{ \
	std::tstring EXPORT_FILE_NAME = __info.GetFileName(); \
	bool QUIET = __info.GetQuiet();
	
// Put it after import function's body
#define END_EXPORT_FUNC }
	
// Call importer
#define CALL_EXPORTER(filename, quiet, expname, maxida, maxidb, c4did) \
	{ImpExpInfo iei(filename, quiet); GePluginMessage(c4did, &iei);}
