#pragma once
#include <wx/wx.h>
#include <wx/valnum.h>

namespace TextEditor {
	enum FontSize {
		DECREMENT, INCREMENT, TEXT_CHANGE,
		APPLY, CANCEL, 
	};
}

class FontSizeDialog: public wxDialog
{
public:
	FontSizeDialog(wxWindow* parent, wxWindowID id);
	~FontSizeDialog();

private:
	int	m_value = 8;
	wxTextCtrl* textCtrl = nullptr;

private:
	void HandleInput(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

