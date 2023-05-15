#pragma once
#include <wx/wx.h>
#include "TextController.h"

//Anonymous Input Enumerator
enum {
	NONE = -1, TEXTBOX = 1
};

class Window: public wxFrame
{
public: 
	Window(const wxString _title, const wxPoint _point, const wxSize _size);

private:
	wxMenuBar* menuBar;
	TextController* textController;

private:	//Events

	//wxDECLARE_EVENT_TABLE();
};

/*
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_MENU(ID_HELLO, WINDOW::OnHello)
wxEND_EVENT_TABLE()
*/