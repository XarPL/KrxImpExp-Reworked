///////////////////////////////////////////////////////////////////////////////
// Name:        ImpExpUIApp.cpp
// Purpose:     KrxImpExpUI main source file.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "3DSImporterDlgInput.meta"
#include "3DSImporterDlgOutput.meta"
#include "3DSExporterDlgInput.meta"
#include "3DSExporterDlgOutput.meta"
#include "MeshImporterDlgInput.meta"
#include "MeshImporterDlgOutput.meta"
#include "MeshInfoDlgInput.meta"
#include "MeshInfoDlgOutput.meta"
#include "ASCImporterDlgInput.meta"
#include "ASCImporterDlgOutput.meta"
#include "ASCExporterDlgInput.meta"
#include "ASCExporterDlgOutput.meta"

// wxImpExpUI headers
#include "ImpExpUIApp.h"
#include "ImpExpUITools.h"
#include "3DSImporterDlg.h"
#include "3DSExporterDlg.h"
#include "MeshImporterDlg.h"
#include "MeshInfoDlg.h"
#include "ASCImporterDlg.h"
#include "ASCExporterDlg.h"
#include "AboutDlg.h"




////////////////////////////////////////////////////////////////////////////////
// the application class
////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_APP(wxImpExpUIApp)

// 'Main program' equivalent: the program execution "starts" here
int wxImpExpUIApp::OnRun()
{
	// started without arguments; show help
	if(argc == 1)
	{
		ShowHelp(_T("index"));
		return -1;
	}

	// needs four arguments
	if(argc != 4)
	{
		MessageBox(NULL, _T("This program is not for starting alone."), _T("Error"), MB_OK);
		return -1;
	}

	// calculate full file names
	std::tstring exeFileName = argv[0];
	size_t nSlashPos1 = exeFileName.rfind(_T('\\'));
	size_t nSlashPos2 = exeFileName.rfind(_T('/'));
	size_t nSlashPos = (nSlashPos1 != -1) ? nSlashPos1 : nSlashPos2;
	std::tstring exeFileDir = (nSlashPos != -1) ? exeFileName.substr(0, nSlashPos + 1) : _T("");
	std::tstring inputFileName = argv[1];
	std::tstring outputFileName = argv[2];
	std::tstring configFileName = argv[3];
	
	// use plain text file for storing and retrieving configuration information
	wxFileConfig* pConfig = new wxFileConfig(_T("wxImpExpUI"), _T("Kerrax"), configFileName, _T(""), wxCONFIG_USE_LOCAL_FILE);
	wxConfigBase::Set(pConfig);

	// setup user interface language
	wxLocale locale;
	InitLocale(&locale, ReadUILangFromConfig());

	// load file with input dialog data, show dialog, and save file with output dialog data
	LOCAL_VAR(TFile, inputFile, CALLF0(NewFile))
	LOCAL_VAR(TFile, outputFile, CALLF0(NewFile))
	TRY
		CALLP2(inputFile.Open, inputFileName, _T("rb"))
		CALLP2(outputFile.Open, outputFileName, _T("wb"))
		LOCAL_VAR(TSTRING, structName, CALLF0(inputFile.ReadString))
		
		IF(structName == _T("3DSImporterDlgInput"))

			// load input data
			LOCAL_VAR(T3DSImporterDlgInput, dlgInput, CALLF0(New3DSImporterDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(T3DSImporterDlgOutput, dlgOutput, CALLF1(New3DSImporterDlgOutput, dlgInput))
			wx3DSImporterDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("3DSImporterDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)
		
		ELSE_IF(structName == _T("3DSExporterDlgInput"))

			// load input data
			LOCAL_VAR(T3DSExporterDlgInput, dlgInput, CALLF0(New3DSExporterDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(T3DSExporterDlgOutput, dlgOutput, CALLF1(New3DSExporterDlgOutput, dlgInput))
			wx3DSExporterDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("3DSExporterDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)

		ELSE_IF(structName == _T("MeshImporterDlgInput"))

			// load input data
			LOCAL_VAR(TMeshImporterDlgInput, dlgInput, CALLF0(NewMeshImporterDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(TMeshImporterDlgOutput, dlgOutput, CALLF1(NewMeshImporterDlgOutput, dlgInput))
			wxMeshImporterDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("MeshImporterDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)

		ELSE_IF(structName == _T("MeshInfoDlgInput"))
		
			// load input data
			LOCAL_VAR(TMeshInfoDlgInput, dlgInput, CALLF0(NewMeshInfoDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(TMeshInfoDlgOutput, dlgOutput, CALLF1(NewMeshInfoDlgOutput, dlgInput))
			wxMeshInfoDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("MeshInfoDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)

		ELSE_IF(structName == _T("ASCImporterDlgInput"))

			// load input data
			LOCAL_VAR(TASCImporterDlgInput, dlgInput, CALLF0(NewASCImporterDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(TASCImporterDlgOutput, dlgOutput, CALLF1(NewASCImporterDlgOutput, dlgInput))
			wxASCImporterDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("ASCImporterDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)

		ELSE_IF(structName == _T("ASCExporterDlgInput"))

			// load input data
			LOCAL_VAR(TASCExporterDlgInput, dlgInput, CALLF0(NewASCExporterDlgInput))
			CALLP1(dlgInput.Read, inputFile)

			// show dialog
			LOCAL_VAR(TASCExporterDlgOutput, dlgOutput, CALLF1(NewASCExporterDlgOutput, dlgInput))
			wxASCExporterDlg dlg(NULL, dlgInput, dlgOutput);
			dlg.ShowModal();

			// save output data
			CALLP1(outputFile.WriteString, _T("ASCExporterDlgOutput"))
			CALLP1(dlgOutput.Write, outputFile)

		END_IF
	END_TRY
	CATCH
		SHOW_ERROR_BOX(T("KrxImpExpUI"), CURRENT_EXCEPTION)
	END_CATCH
	CALLP0(inputFile.Close)
	CALLP0(outputFile.Close)
	
	delete wxConfigBase::Set((wxConfigBase*) NULL);
	return 0;
}

