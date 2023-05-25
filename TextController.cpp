#include "TextController.h"


TextController::TextController(wxWindow* _parent, wxWindowID _id) : wxTextCtrl(_parent, _id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE) {
	font_size = 8;
}

bool TextController::HasMultiplePages() const {
	return true;
}

void TextController::CreateNewText() {
	Clear();
}

int TextController::GetFontSize() {
	return font_size;
}