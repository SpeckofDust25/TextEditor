#include "TextController.h"


TextController::TextController(wxWindow* _parent, wxWindowID _id) : wxTextCtrl(_parent, _id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE) {
	fontSize = 8;
}

bool TextController::HasMultiplePages() const {
	return true;
}

void TextController::CreateNewText() {
	Clear();
}

int TextController::GetFontSize() {
	return fontSize;
}

void TextController::SetFontSize(int size) {
	wxFont font = GetFont();
	font.SetPointSize(size);
	SetFont(font);
	fontSize = size;
}