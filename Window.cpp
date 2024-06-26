#include "Window.h"


Window::Window(const wxString _title, const wxPoint _point, const wxSize _size) :
	wxFrame(nullptr, wxID_ANY, _title, _point, _size) {

	directory = "";
	Centre();	//Window Gets Created At the Center of the Screen

	wxMenu* menuFile = new wxMenu();
	wxMenu* menuEdit = new wxMenu();
	wxMenu* menuHelp = new wxMenu();
	menuBar = new wxMenuBar();

	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuEdit, "&Edit");
	menuBar->Append(menuHelp, "&Help");

	//File
	menuFile->Append(TextEditor::New, "&New", wxEmptyString, false);
	menuFile->Append(TextEditor::Save, "&Save", wxEmptyString, false);
	menuFile->Append(TextEditor::SaveAs, "&Save As", wxEmptyString, false);
	menuFile->Append(TextEditor::Open, "&Open", wxEmptyString, false);
	menuFile->Append(TextEditor::Exit, "&Exit", wxEmptyString, false);

	menuEdit->Append(TextEditor::Font_Size, "&Font Size", wxEmptyString, false);
	//menuEdit->Append(TextEditor::Font_Type, "&Font Type", wxEmptyString, false);
	menuEdit->Append(TextEditor::Font_Color, "&Font Color", wxEmptyString, false);

	SetMenuBar(menuBar);
	CreateStatusBar(3);
	//Position, Characters, Font Size

	textController = new TextController(this, TextEditor::TextBox);

	wxBoxSizer* textSizer = new wxBoxSizer(wxVERTICAL);
	textSizer->Add(textController, wxSizerFlags(1).Expand());

	SetSizer(textSizer);
}

void Window::Update() {

}

void Window::MenuEvents(wxCommandEvent& _event) {
	switch (_event.GetId()) {

	case TextEditor::New:
		if (wxYES == wxMessageBox("Are you sure", "Text Editor", wxYES_NO | wxCANCEL)) {
			textController->CreateNewText();
		}
		break;

	case TextEditor::Save:
		if (directory.size() <= 0) {
			SaveAs();
		} else {
			Save();
		}
		break;

	case TextEditor::SaveAs:
		SaveAs();
		break;
	
	case TextEditor::Open:
		Open();
		break;

	case TextEditor::Exit: 
		Close(true);
		break;

	case TextEditor::Font_Size:
		SetFontSize();
		break;

	case TextEditor::Font_Color:
		SetFontColor();
		break;
	}
}

//File
void Window::Save() {
	if (directory != "") {
		textController->SaveFile(directory);
	}
}

void Window::SaveAs() {
	wxFileDialog saveMenu(this, "Save As", wxEmptyString, wxEmptyString, ".txt", wxFD_SAVE);

	if (saveMenu.ShowModal() == wxID_OK) {
		directory = saveMenu.GetDirectory() + "\\" + saveMenu.GetFilename();
		textController->SaveFile(directory);
	}
}

void Window::Open() {
	wxFileDialog openMenu(this, "Open", wxEmptyString, wxEmptyString, "(*.txt) | *.txt", wxFD_OPEN);

	if (openMenu.ShowModal() == wxID_OK) {
		textController->LoadFile(openMenu.GetDirectory() + openMenu.GetFilename());
	}
}

//Edit
void Window::SetFontSize() {
	FontSizeDialog dialog(this, wxID_ANY, textController->GetFontSize());

	if (dialog.GetFontSize() != textController->GetFontSize()) {
		textController->SetFontSize(dialog.GetFontSize());
	}
}

void Window::SetFontColor() {
	FontColorDialog dialog(this, wxID_ANY, textController->GetForegroundColour());

	if (dialog.GetColor() != textController->GetForegroundColour()) {
		textController->SetForegroundColour(dialog.GetColor());
	}
}

void Window::LoadFile(wxString _directory) {
	directory = _directory;
	textController->LoadFile(directory, wxTEXT_TYPE_ANY);
}


//Static Button Input Events
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_MENU(TextEditor::New, MenuEvents)
EVT_MENU(TextEditor::Save, MenuEvents)
EVT_MENU(TextEditor::SaveAs, MenuEvents)
EVT_MENU(TextEditor::Open, MenuEvents)
EVT_MENU(TextEditor::Exit, MenuEvents)
EVT_MENU(TextEditor::Font_Size, MenuEvents)
EVT_MENU(TextEditor::Font_Type, MenuEvents)
EVT_MENU(TextEditor::Font_Color, MenuEvents)
wxEND_EVENT_TABLE()

	