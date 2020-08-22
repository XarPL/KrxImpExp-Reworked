///////////////////////////////////////////////////////////////////////////////
// Name:        CheckTreeCtrl.h
// Purpose:     Declaration of class wxCheckTreeCtrl.
//              wxCheckTreeCtrl is a class derived from the wxTreeCtrl class.
//              wxCheckTreeCtrl providing tree with items which allowed 
//              to check or uncheck.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_CHECKTREECTRL_H_
#define _WX_CHECKTREECTRL_H_

#include "wx/treectrl.h"

// Identifier of the icon
#define wxCHECKTREE_IMAGE_CHECKED_ENABLED     0
#define wxCHECKTREE_IMAGE_CHECKED_DISABLED    1
#define wxCHECKTREE_IMAGE_UNCHECKED_ENABLED   2
#define wxCHECKTREE_IMAGE_UNCHECKED_DISABLED  3

// Type of checking:
// check each item independenly from other items
#define wxCHECKTREE_MODE_ITEM	0 

// check branch of items; item's checking will cause
// checking all branch with the checked item as root;
// item's unchecking will cause unchecking all branch too
#define wxCHECKTREE_MODE_BRANCH	1 

// Item data
class wxCheckTreeItemData: public wxTreeItemData
{
public:
	// Ctor / dtor
	wxCheckTreeItemData() { m_checked = false; m_enabled = true;}
	~wxCheckTreeItemData()  {}

	// Checked or unchecked
	bool IsChecked() const { return m_checked; }
	void SetIsChecked(bool checked) { m_checked = checked; }

	// Enabled or disabled
	bool IsEnabled() const { return m_enabled; }
	void SetIsEnabled(bool enable) { m_enabled = enable; }

	// Text label associated with item
	void SetLabel(const wxString& label) { m_label = label; }
	const wxString& GetLabel() const { return m_label; }

private:
	bool		m_checked;
	bool        m_enabled;
	wxString    m_label;
};

// Control class
class wxCheckTreeCtrl: public wxTreeCtrl
{
DECLARE_CLASS(wxCheckTreeCtrl)
public:
	// Ctor / dtor
	wxCheckTreeCtrl(wxWindow* parent, wxWindowID ctrlId = wxID_ANY, const wxPoint& pt = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize, long style = wxTR_HAS_BUTTONS);
	~wxCheckTreeCtrl();

	// Getting item identifier and item data
	wxTreeItemId FindItemByLabel(const wxString& label, wxTreeItemId& startId = wxTreeItemId()) const;
	wxCheckTreeItemData* GetItemData(wxTreeItemId& itemId) const;
	wxCheckTreeItemData* GetItemData(const wxString& label) const;

	// Set/get checking mode (one of "wxCHECKTREE_MODE_..." constants)
	void SetCheckingMode(int checkingMode) { m_checkingMode = checkingMode; }
	int GetCheckingMode() const { return m_checkingMode; }

	// Adding items to tree
	wxTreeItemId AddCheckedRoot(const wxString& label, bool checked = false, bool enabled = true);
	wxTreeItemId AddCheckedItem(wxTreeItemId& parentId, const wxString& label, bool checked = false, bool enabled = true);
	wxTreeItemId AddCheckedItem(const wxString& parentLabel, const wxString& label, bool checked = false, bool enabled = true);
	
	// Delete all the items in the tree
	void DeleteAllItems();

	// Checking/unchecking an item;
	// these functions don't generate the wxCheckTreeEvent notification event 
	void CheckItem(wxTreeItemId& itemId, bool check = true);
	void CheckItem(const wxString& label, bool check = true);
	void UncheckItem(wxTreeItemId& itemId) {CheckItem(itemId, false);}
	void UncheckItem(const wxString& label) {CheckItem(label, false);}
	bool IsItemChecked(wxTreeItemId& itemId);
	bool IsItemChecked(const wxString& label);

	// Enabling/disabling an item
	void EnableItem(wxTreeItemId& itemId, bool enable = true);
	void EnableItem(const wxString& label, bool check = true);
	void DisableItem(wxTreeItemId& itemId) {EnableItem(itemId, false);}
	void DisableItem(const wxString& label) {EnableItem(label, false);}
	bool IsItemEnabled(wxTreeItemId& itemId);
	bool IsItemEnabled(const wxString& label);

	// Get item's label
	const wxString& GetItemLabel(wxTreeItemId& itemId) const;

	// Check all items
	void CheckAllItems(bool check = true, bool skipDisabledItems = true) { CheckBranch(GetRootItem(), check, skipDisabledItems);}

	// Uncheck all items
	void UncheckAllItems(bool skipDisabledItems = true) {CheckAllItems(false, skipDisabledItems);}

	// Check all items in branch
	void CheckBranch(wxTreeItemId& itemId, bool check = true, bool skipDisabledItems = true);

	// Uncheck all items in branch
	void UncheckBranch(wxTreeItemId& itemId, bool skipDisabledItems = true) { CheckBranch(itemId, false, skipDisabledItems); }

	// Get number of checked items
	int GetCheckedItemCount() const {return m_checkedItemCount;}

	// Get number of all items
	int GetItemCount() const {return m_itemCount;}

protected:
	// Load icons from graphical files; used by contructor only
	void LoadIcons();

	// Set item's icon according to its state (checked/unchecked, enabled/disabled)
	void SetItemIconByState(wxTreeItemId& item);

	// Change item's state when the item will be checked or unchecked;
	// this function generates the wxCheckTreeEvent notification message
	// and used internally while the OnMouseEvent and OnKeyDown events are handling
	void ToggleItem(wxTreeItemId& itemId);

	// Events
	void OnMouseEvent(wxMouseEvent& event);
	void OnKeyDown(wxKeyEvent& event);

protected:
	wxImageList*        m_imageList;
	int                 m_checkingMode;
	int                 m_itemCount;
	int                 m_checkedItemCount;
	DECLARE_EVENT_TABLE()
};

// Special control event which will be used when item will be checked or unchecked by user
class wxCheckTreeEvent: public wxNotifyEvent
{
public:
	wxCheckTreeEvent(wxEventType commandType = wxEVT_NULL, int ctrlId = 0):
		wxNotifyEvent(commandType, ctrlId), m_checked(false), m_itemData(NULL) {}

	void SetIsChecked(bool checked) { m_checked = checked; }
	bool IsChecked() const { return m_checked; }

	wxTreeItemId GetItemId() const { return m_itemId; }
	void SetItemId(wxTreeItemId itemId) { m_itemId = itemId; }
	
	wxCheckTreeItemData* GetItemData() const { return m_itemData; }
	void SetItemData(wxCheckTreeItemData* itemData) { m_itemData = itemData; }

private:
	bool                    m_checked;
	wxCheckTreeItemData*    m_itemData;
	wxTreeItemId            m_itemId;
	DECLARE_DYNAMIC_CLASS(wxCheckTreeEvent);
};

typedef void (wxEvtHandler::*wxCheckTreeEventFunction)(wxCheckTreeEvent&);

BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_COMMAND_CHECKTREECTRL_TOGGLED, 900)
END_DECLARE_EVENT_TYPES()

#define EVT_CHECKTREECTRL_TOGGLED(id, fn) DECLARE_EVENT_TABLE_ENTRY( wxEVT_COMMAND_CHECKTREECTRL_TOGGLED, id, -1, (wxObjectEventFunction) (wxEventFunction) (wxCheckTreeEventFunction) & fn, (wxObject *) NULL ),

#endif // _WX_CHECKTREECTRL_H_