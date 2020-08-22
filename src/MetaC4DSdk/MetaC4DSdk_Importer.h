///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Importer.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 13, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// Mechanism to lock all Cinema4D's windows when an user is working with 
// file open dialog or file save dialog.

// Handles of windows which should to be locked.
// These are all Cinema4D' windows and their children,
// excluding file open/save dialog and its controls.
static std::vector<HWND> s_listOfLockedWindows;

// Calculate list of locked windows.
static void CalcLockedWindows(HWND hwndStart = NULL)
{
	if(hwndStart == NULL)
		s_listOfLockedWindows.clear();

	HWND hwnd = NULL;
	while(hwnd = FindWindowEx(hwndStart, hwnd, NULL, NULL))
	{
		DWORD dwProcessId;
		DWORD dwThreadId = GetWindowThreadProcessId(hwnd, &dwProcessId);
		if(dwProcessId == GetCurrentProcessId())
		{
			s_listOfLockedWindows.push_back(hwnd);
			CalcLockedWindows(hwnd);
		}
	}
}

// Check if a window is in list of locked windows.
static BOOL IsWindowLocked(HWND hwnd)
{
	for(size_t i = 0; i < s_listOfLockedWindows.size(); ++i)
	{
		if(s_listOfLockedWindows[i] == hwnd)
			return TRUE;
	}
	return FALSE;
}

// Mouse hook procedure. This procedure hook some mouse messages (WM_LBUTTONDOWN and so on) 
// for locked windows to prevent them from processing.
static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(nCode >= 0) 
	{
		MOUSEHOOKSTRUCT* pMHS = (MOUSEHOOKSTRUCT*)lParam;
		HWND hwnd = pMHS->hwnd;
		WPARAM message = wParam;
		if(IsWindowLocked(hwnd))
		{
			if(message == WM_LBUTTONDOWN || message == WM_LBUTTONDBLCLK
			|| message == WM_RBUTTONDOWN || message == WM_RBUTTONDBLCLK
			|| message == WM_MBUTTONDOWN || message == WM_MBUTTONDBLCLK
			|| message == WM_NCLBUTTONDOWN || message == WM_NCLBUTTONDBLCLK
			|| message == WM_NCRBUTTONDOWN || message == WM_NCRBUTTONDBLCLK
			|| message == WM_NCMBUTTONDOWN || message == WM_NCMBUTTONDBLCLK)
			{
				MessageBeep(-1);
				return TRUE;
			}
		}
 	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Show file open/save dialog
static BOOL ShowOpenFileDialog(LPOPENFILENAME pofn, BOOL bOpenDialog = TRUE)
{
	// Calculate windows to lock
	CalcLockedWindows();

	// Install hooks
	HHOOK hhookCallWnd = SetWindowsHookEx(WH_MOUSE, MouseProc, NULL, GetCurrentThreadId()); 
	if(!hhookCallWnd)
	{
		return FALSE;
	}

	// Creating file open/save dialog and working with it
	BOOL bResult;
	if(bOpenDialog) 
		bResult = GetOpenFileName(pofn);
	else
		bResult = GetSaveFileName(pofn);

	// Uninstall hooks
	UnhookWindowsHookEx(hhookCallWnd);

	// the function returns TRUE if success
	return bResult;
}



///////////////////////////////////////////////////////////////////////////////
// Information for importing/exporting: file name and quiet flag

class ImpExpInfo
{
private:
	std::tstring __filename;
	bool         __quiet;
public:
	ImpExpInfo(const std::tstring& filename = "", bool quiet = false) 
	{
		__filename = filename; 
		__quiet    = quiet;
	}
	ImpExpInfo(const ImpExpInfo& info)
	{
		__filename = info.__filename;
		__quiet    = info.__quiet;
	}
	const ImpExpInfo& operator =(const ImpExpInfo& info)
	{
		__filename = info.__filename;
		__quiet    = info.__quiet;
		return *this;
	}	
	std::tstring GetFileName() const
	{
		return __filename;
	}
	void SetFileName(const std::tstring& filename)
	{
		__filename = filename;
	}
	bool GetQuiet() const
	{
		return __quiet;
	}
	void SetQuiet(bool quiet)
	{
		__quiet = quiet;
	}
	void Reset()
	{
		__filename = "";
		__quiet = false;
	}	
};



///////////////////////////////////////////////////////////////////////////////////////
// Main import function

// Return values for import/export functions
#define IMPEXP_FAIL		0
#define IMPEXP_SUCCESS	1
#define IMPEXP_CANCEL	2

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
// c4did: 1000010
#define IMPORT_FUNC(impname, ext, desc, author, year, version, maxida, maxidb, c4did) \
class impname : public CommandData \
{ \
	static ImpExpInfo __info; \
	int __DoImport(); \
public: \
	static void SetInfo(const ImpExpInfo& info) {__info = info;} \
	virtual Bool Execute(BaseDocument *doc); \
}; \
\
Bool Register##impname(void) \
{ \
	static const std::tstring s_sImportExt = _T("Import *.") + ext; \
	return RegisterCommandPlugin(c4did, s_sImportExt.c_str(), 0, NULL, String(), gNew impname); \
} \
\
Bool PluginStart() \
{ \
	if (!Register##impname()) return FALSE; \
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
		impname::SetInfo(info); \
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
ImpExpInfo impname::__info; \
\
Bool impname::Execute(BaseDocument *doc) \
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
		TCHAR customFileName[MAX_PATH] = _T(""); \
		OPENFILENAME ofn; \
		ZeroMemory(&ofn, sizeof(OPENFILENAME)); \
		ofn.lStructSize = sizeof(OPENFILENAME); \
		ofn.hwndOwner = hwndCinema4D; \
		TCHAR bufFilter[MAX_PATH+1]; \
		_stprintf(bufFilter, "%s (*.%s)\0*.%s\0\0", desc.c_str(), ext.c_str(), ext.c_str()); \
		ofn.lpstrFilter = bufFilter; \
		ofn.nFilterIndex = 1; \
		ofn.lpstrFile = customFileName; \
		ofn.nMaxFile = MAX_PATH; \
		ofn.lpstrInitialDir = NULL; \
		ofn.lpstrTitle = "Select file to import"; \
		ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY; \
		if(!ShowOpenFileDialog(&ofn, TRUE)) \
			return IMPEXP_CANCEL; \
		__info.SetFileName(customFileName); \
	} \
	if(doc != GetActiveDocument()) \
	{ \
		SetActiveDocument(doc); \
	} \
	DrawViews(DRAWFLAGS_NO_THREAD); \
	int r = __DoImport(); \
	DrawViews(DRAWFLAGS_NO_THREAD); \
	__info.Reset(); \
	return r == IMPEXP_SUCCESS; \
} \
\
int impname::__DoImport() \
{ \
	std::tstring IMPORT_FILE_NAME = __info.GetFileName(); \
	int IMPORT_FILE_SIZE = FILE_SIZE(IMPORT_FILE_NAME); \
	bool QUIET = __info.GetQuiet();
	
// Put it after import function's body
#define END_IMPORT_FUNC }
	
// Call importer
#define CALL_IMPORTER(filename, quiet, impname, maxida, maxidb, c4did) \
	{ImpExpInfo iei(filename, quiet); GePluginMessage(c4did, &iei);}
