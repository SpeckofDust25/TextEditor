#pragma once
#include <wx/wx.h>
#include <wx/clrpicker.h>

namespace ColorDialog {
	enum FontColor {
		APPLY, CANCEL
	};
}

class FontColorDialog: public wxDialog
{
public:
	FontColorDialog(wxWindow* _window, wxWindowID _id, wxColor _color);
	~FontColorDialog();
	wxColor GetColor();

private:
	wxColor color;
	wxColourPickerCtrl* colorPicker;
	void HandleInput(wxCommandEvent& event);


	wxDECLARE_EVENT_TABLE();
};

