#pragma once
#include <wx/wx.h>

//Anonymous Input Enumerator
enum {
	NONE = -1
};

class Window: public wxFrame
{
public: 
	Window(const wxString _title, const wxPoint _point, const wxSize _size);

private:
	wxMenuBar menuBar;
	wxMenu menu;
	wxTextCtrl textCtrl;

private:	//Events

	//wxDECLARE_EVENT_TABLE();
};

/*
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_MENU(ID_HELLO, WINDOW::OnHello)
wxEND_EVENT_TABLE()
*/