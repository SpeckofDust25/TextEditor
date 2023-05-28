#pragma once
#include <wx/wx.h>
#include <wx/valnum.h>

namespace SizeDialog {
	enum FontSize {
		DECREMENT, INCREMENT, TEXT_CHANGE,
		APPLY, CANCEL, 
	};
}

class FontSizeDialog: public wxDialog
{
public:
	FontSizeDialog(wxWindow* parent, wxWindowID id, int _fontSize);
	~FontSizeDialog();
	int GetFontSize();

private:
	int	fontSize = 8;
	int originalFontSize = 8;
	wxTextCtrl* textCtrl = nullptr;

private:
	void HandleInput(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

