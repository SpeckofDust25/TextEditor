#include "TextController.h"


TextController::TextController(wxWindow* _parent, wxWindowID _id) : wxTextCtrl(_parent, _id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE) {
	//SetDefaultStyle(wxTextAttr(*wxRED));
}

bool TextController::HasMultiplePages() const {
	return true;
}