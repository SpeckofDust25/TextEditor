#include "Window.h"


Window::Window(const wxString _title, const wxPoint _point, const wxSize _size) :
	wxFrame(nullptr, wxID_ANY, _title, _point, _size) {

	wxMenu* menuFile = new wxMenu();
	wxMenu* menuEdit = new wxMenu();
	wxMenu* menuHelp = new wxMenu();
	menuBar = new wxMenuBar();

	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuEdit, "&Edit");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);
	CreateStatusBar(1);
	SetStatusText("Hello");


	//wxTextCtrl* textCtrl = new TextCtrl();
	//textCtrl->HasMultiplePages()

	textController = new TextController(this, TEXTBOX);
	//textCtrl->pages

	wxBoxSizer* textSizer = new wxBoxSizer(wxVERTICAL);
	textSizer->Add(textController, wxSizerFlags(1).Expand());

	SetSizer(textSizer);
}
	