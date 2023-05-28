#pragma once
#include <wx/wx.h>
#include "TextController.h"
#include "FontSizeDialog.h"
#include "FontColorDialog.h"

namespace TextEditor {	//Anonymous Input Enumerator
	enum {
		NONE = -1, TextBox = 1,
		New, Save, SaveAs, Open, Exit, //File
		Font_Size, Font_Type, Font_Color //Edit
	};
}

class Window: public wxFrame
{
public: 
	Window(const wxString _title, const wxPoint _point, const wxSize _size);

private:
	std::string fileName;
	std::string fileDirectory;
	wxMenuBar* menuBar;
	TextController* textController;
	void Save();
	void SaveAs();
	void Open();
	void SetFontSize();
	void SetFontColor();

private:	//Events
	void MenuEvents(wxCommandEvent& _event);
	wxDECLARE_EVENT_TABLE();
};

