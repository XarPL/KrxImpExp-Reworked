///////////////////////////////////////////////////////////////////////////////
// Name:        CheckTreeCtrl.cpp
// Purpose:     Implementation of class wxCheckTreeCtrl.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"
#include <wx/imaglist.h>

#include <checked_enabled.xpm>
#include <checked_disabled.xpm>
#include <unchecked_enabled.xpm>
#include <unchecked_disabled.xpm>

#include "CheckTreeCtrl.h"

IMPLEMENT_CLASS(wxCheckTreeCtrl, wxTreeCtrl)

BEGIN_EVENT_TABLE(wxCheckTreeCtrl, wxTreeCtrl)
EVT_MOUSE_EVENTS(wxCheckTreeCtrl::OnMouseEvent)
EVT_CHAR(wxCheckTreeCtrl::OnKeyDown)
END_EVENT_TABLE()

DEFINE_EVENT_TYPE(wxEVT_COMMAND_CHECKTREECTRL_TOGGLED)
IMPLEMENT_DYNAMIC_CLASS(wxCheckTreeEvent, wxNotifyEvent)

// Ctor
wxCheckTreeCtrl::wxCheckTreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pt, const wxSize& sz, long style):
wxTreeCtrl(parent, id, pt, sz, style)
{
	LoadIcons();
	m_checkingMode = wxCHECKTREE_MODE_ITEM;
	m_itemCount = 0;
	m_checkedItemCount = 0;
}

// Dtor
wxCheckTreeCtrl::~wxCheckTreeCtrl()
{
}

// Load icons from graphical files; used by contructor only
void wxCheckTreeCtrl::LoadIcons()
{
	m_imageList = new wxImageList(16, 16, true);
	AssignImageList(m_imageList);
	m_imageList->Add(wxIcon(checked_enabled_xpm));
	m_imageList->Add(wxIcon(checked_disabled_xpm));
	m_imageList->Add(wxIcon(unchecked_enabled_xpm));
	m_imageList->Add(wxIcon(unchecked_disabled_xpm));
}

// Set item's icon according to its state (checked/unchecked, enabled/disabled)
void wxCheckTreeCtrl::SetItemIconByState(wxTreeItemId& item)
{
	wxCheckTreeItemData* data = (wxCheckTreeItemData*) GetItemData(item);
	if (data)
	{
		int imageIndex = 0;
		if (data->IsChecked())
		{
			if(data->IsEnabled())
				imageIndex = wxCHECKTREE_IMAGE_CHECKED_ENABLED;
			else
				imageIndex = wxCHECKTREE_IMAGE_CHECKED_DISABLED;
		}
		else
		{
			if(data->IsEnabled())
				imageIndex = wxCHECKTREE_IMAGE_UNCHECKED_ENABLED;
			else
				imageIndex = wxCHECKTREE_IMAGE_UNCHECKED_DISABLED;
		}
		SetItemImage(item, imageIndex);
	}
}

// Getting item identifier and item data
wxTreeItemId wxCheckTreeCtrl::FindItemByLabel(
	const wxString& label, 
	wxTreeItemId& startId /* = wxTreeItemId() */) const
{
	wxTreeItemId itemId = startId;
	if(!itemId.IsOk()) itemId = GetRootItem();
	if(!itemId.IsOk()) return itemId;

	if(GetItemData(itemId)->GetLabel() == label)
		return itemId;

	wxTreeItemIdValue cookie;
	for(wxTreeItemId& childId = GetFirstChild(itemId, cookie); childId.IsOk(); childId = GetNextChild(childId, cookie))
	{
		wxTreeItemId foundId = FindItemByLabel(label, childId);
		if(foundId.IsOk())
			return foundId;
	}

	return wxTreeItemId();
}

wxCheckTreeItemData* wxCheckTreeCtrl::GetItemData(wxTreeItemId& itemId) const
{
	wxCheckTreeItemData* itemData = (wxCheckTreeItemData*) (wxTreeCtrl::GetItemData(itemId));
	return itemData;
}

wxCheckTreeItemData* wxCheckTreeCtrl::GetItemData(const wxString& label) const
{
	wxTreeItemId itemId = FindItemByLabel(label);
	wxCheckTreeItemData* itemData = GetItemData(itemId);
	return itemData;
}

// Adding items to tree
wxTreeItemId wxCheckTreeCtrl::AddCheckedRoot(
	const wxString& label, bool checked /* = false */, bool enabled /* = true */)
{
	wxCheckTreeItemData* itemData = new wxCheckTreeItemData;
	itemData->SetIsEnabled(enabled);
	itemData->SetIsChecked(checked);
	itemData->SetLabel(label);
	wxTreeItemId itemId = AddRoot(label, -1, -1, itemData);
	++m_itemCount;
	if(checked) ++m_checkedItemCount;
	SetItemIconByState(itemId);
	return itemId;
}

wxTreeItemId wxCheckTreeCtrl::AddCheckedItem(
	wxTreeItemId& parentId, const wxString& label, 
	bool checked /* = false */, bool enabled /* = true */)
{
	wxCheckTreeItemData* itemData = new wxCheckTreeItemData;
	itemData->SetIsEnabled(enabled);
	itemData->SetIsChecked(checked);
	itemData->SetLabel(label);
	wxTreeItemId itemId = AppendItem(parentId, label, -1, -1, itemData);
	++m_itemCount;
	if(checked) ++m_checkedItemCount;
	SetItemIconByState(itemId);
	return itemId;
}

wxTreeItemId wxCheckTreeCtrl::AddCheckedItem(
	const wxString& parentLabel, const wxString& label, 
	bool checked /* = false */, bool enabled /* = true */)
{
	wxTreeItemId parentId = FindItemByLabel(parentLabel);
	wxTreeItemId itemId;
	if(parentId.IsOk())
	{
		itemId = AddCheckedItem(parentId, label, checked, enabled);
	}
	return itemId;
}

// Delete all the items in the tree
void wxCheckTreeCtrl::DeleteAllItems()
{
	wxTreeCtrl::DeleteAllItems();
	m_itemCount = 0;
	m_checkedItemCount = 0;
}

// Checking/unchecking an item;
// these functions don't generate the wxCheckTreeEvent notification event 
void wxCheckTreeCtrl::CheckItem(wxTreeItemId& itemId, bool check /* = true */)
{
	if(itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if(itemData && itemData->IsChecked() != check)
		{
			if(itemData->IsChecked())
			{
				--m_checkedItemCount;
			}
			itemData->SetIsChecked(check);
			if(check)
			{
				++m_checkedItemCount;
			}
			SetItemIconByState(itemId);
		}
	}
}

void wxCheckTreeCtrl::CheckItem(const wxString& label, bool check /* = true */)
{
	wxTreeItemId itemId = FindItemByLabel(label);
	CheckItem(itemId, check);
}

bool wxCheckTreeCtrl::IsItemChecked(wxTreeItemId& itemId)
{
	if(itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if(itemData)
			return itemData->IsChecked();
	}
	return false;
}
	
bool wxCheckTreeCtrl::IsItemChecked(const wxString& label)
{
	wxTreeItemId itemId = FindItemByLabel(label);
	return IsItemChecked(itemId);
}


// Enabling/disabling an item
void wxCheckTreeCtrl::EnableItem(wxTreeItemId& itemId, bool enable /* = true */)
{
	if(itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if(itemData && itemData->IsEnabled() != enable)
		{
			itemData->SetIsEnabled(enable);
			SetItemIconByState(itemId);
		}
	}
}

void wxCheckTreeCtrl::EnableItem(const wxString& label, bool check /* = true */)
{
	wxTreeItemId itemId = FindItemByLabel(label);
	EnableItem(itemId, check);
}

bool wxCheckTreeCtrl::IsItemEnabled(wxTreeItemId& itemId)
{
	if(itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if(itemData)
			return itemData->IsEnabled();
	}
	return false;
}

bool wxCheckTreeCtrl::IsItemEnabled(const wxString& label)
{
	wxTreeItemId itemId = FindItemByLabel(label);
	return IsItemEnabled(itemId);
}

// Get item's label
const wxString& wxCheckTreeCtrl::GetItemLabel(wxTreeItemId& itemId) const
{
	if(itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if(itemData)
			return itemData->GetLabel();
	}
	static wxString s_emptyString = _T("");
	return s_emptyString;
}

// Check all items in branch
void wxCheckTreeCtrl::CheckBranch(wxTreeItemId& itemId, bool check /* = true */, bool skipDisabledItems /* = true */)
{
	if(itemId.IsOk())
	{
		if(!skipDisabledItems || IsItemEnabled(itemId))
			CheckItem(itemId, check);

		wxTreeItemIdValue cookie;
		for(wxTreeItemId& childId = GetFirstChild(itemId, cookie); childId.IsOk(); childId = GetNextChild(childId, cookie))
			CheckBranch(childId, check, skipDisabledItems);
	}
}

// Change item's state when the item will be checked or unchecked;
// this function generates the wxCheckTreeEvent notification message
// and used internally while the OnMouseEvent and OnKeyDown events are handling
void wxCheckTreeCtrl::ToggleItem(wxTreeItemId& itemId)
{
	if (itemId.IsOk())
	{
		wxCheckTreeItemData* itemData = GetItemData(itemId);
		if (itemData && itemData->IsEnabled() )
		{
			bool check = !itemData->IsChecked();
			if(m_checkingMode == wxCHECKTREE_MODE_ITEM)
			{
				CheckItem(itemId, check);
			}
			else if(m_checkingMode == wxCHECKTREE_MODE_BRANCH)
			{
				if(check)
				{
					wxTreeItemId parentId = GetItemParent(itemId);
					if(parentId.IsOk() && !IsItemChecked(parentId))
						UncheckAllItems();
					CheckBranch(itemId, check);
				}
				else
				{
					UncheckBranch(itemId);
				}
			}

			wxCheckTreeEvent commandEvent(wxEVT_COMMAND_CHECKTREECTRL_TOGGLED, GetId());
			commandEvent.SetEventObject(this);
			commandEvent.SetItemId(itemId);
			commandEvent.SetItemData(itemData);
			commandEvent.SetIsChecked(itemData->IsChecked());
			GetEventHandler()->ProcessEvent(commandEvent);
		}
	}
}

// Events
void wxCheckTreeCtrl::OnMouseEvent(wxMouseEvent& event)
{
	int flags = 0;
	wxTreeItemId item = HitTest(wxPoint(event.GetX(), event.GetY()), flags);

	if (event.LeftDown() || event.LeftDClick())
	{
		if (flags & wxTREE_HITTEST_ONITEMICON)
		{
			ToggleItem(item);
			return;
		}
	}
	event.Skip();
}

void wxCheckTreeCtrl::OnKeyDown(wxKeyEvent& event)
{
	wxTreeItemId item = GetSelection();
	if (event.GetKeyCode() == WXK_SPACE)
	{
		ToggleItem(item);
		return;
	}
	event.Skip();
}

