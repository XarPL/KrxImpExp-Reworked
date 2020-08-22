///////////////////////////////////////////////////////////////////////////////
// Name:        CheckNotebook.h
// Purpose:     Declaration of class wxCheckTreeCtrl.
//              wxCheckTreeCtrl is a class derived from the wxTreeCtrl class.
//              wxCheckTreeCtrl providing tree with items which allowed 
//              to check or uncheck.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_CHECKNOTEBOOK_H_
#define _WX_CHECKNOTEBOOK_H_

#include "wx/notebook.h"

// Control class
class wxCheckNotebook: public wxNotebook
{
DECLARE_CLASS(wxColorTabNotebook)
public:
	// Ctor / dtor
	wxCheckNotebook(wxWindow* parent, wxWindowID ctrlId = wxID_ANY, const wxPoint& pt = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize, long style = 0);
	~wxCheckNotebook();
	
protected:
	// Load icons from graphical files; used by contructor only
	void LoadIcons();
	
	// Events
	void OnPaint(wxPaintEvent& event);

private:
	DECLARE_EVENT_TABLE()
};

#endif // _WX_CHECKNOTEBOOK_H_