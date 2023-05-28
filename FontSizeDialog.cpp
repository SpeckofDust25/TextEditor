#include "FontSizeDialog.h"


FontSizeDialog::FontSizeDialog(wxWindow* parent, wxWindowID id, int _fontSize): wxDialog(parent, id, "Text Editor", wxDefaultPosition, wxSize(300, 200)) {
	fontSize = _fontSize;
	originalFontSize = _fontSize;

	wxIntegerValidator<int> intValidator(&fontSize, 0, 99);

	wxStaticText* title = new wxStaticText(this, id, " Font Size", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
	wxPanel* interactPanel = new wxPanel(this);
	wxPanel* applyPanel = new wxPanel(this);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* interactSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* applySizer = new wxBoxSizer(wxHORIZONTAL);

	mainSizer->AddSpacer(5);
	mainSizer->Add(title, 0, wxEXPAND, 5);
	mainSizer->Add(interactPanel, wxSizerFlags(1).Expand());
	mainSizer->Add(applyPanel, wxSizerFlags(1).Expand());
	mainSizer->AddSpacer(5);
	
	wxButton* left = new wxButton(interactPanel, SizeDialog::FontSize::DECREMENT, "-");
	wxButton* right = new wxButton(interactPanel, SizeDialog::FontSize::INCREMENT, "+");

	textCtrl = new wxTextCtrl(interactPanel, SizeDialog::FontSize::TEXT_CHANGE, "8", wxDefaultPosition, wxDefaultSize, wxTE_CENTER, intValidator);
	
	wxButton* apply = new wxButton(applyPanel, SizeDialog::FontSize::APPLY, "Apply");
	wxButton* cancel = new wxButton(applyPanel, SizeDialog::FontSize::CANCEL, "Cancel");

	interactSizer->Add(left, 0, wxALL, 5);
	interactSizer->Add(textCtrl, 0, wxALL, 5);
	interactSizer->Add(right, 0, wxALL, 5);

	applySizer->AddStretchSpacer(1);
	applySizer->Add(cancel, 0.75, wxALL, 0);
	applySizer->AddSpacer(10);
	applySizer->Add(apply, 0.75, wxALL, 0);
	applySizer->AddStretchSpacer(1);

	SetSizer(mainSizer);
	interactPanel->SetSizer(interactSizer);
	applyPanel->SetSizer(applySizer);
	
	mainSizer->SetSizeHints(this);

	ShowModal();
	Destroy();
}

FontSizeDialog::~FontSizeDialog() {

}

void FontSizeDialog::HandleInput(wxCommandEvent& event) {
	std::string text = textCtrl->GetValue().ToStdString();
	char character;

	switch (event.GetId()) {

	case SizeDialog::FontSize::DECREMENT:
		if (fontSize > 0) {
			fontSize -= 1;
			textCtrl->SetLabelText(std::to_string(fontSize));
		}
		break;

	case SizeDialog::FontSize::INCREMENT:
		if (fontSize < 99) {
			fontSize += 1;
			textCtrl->SetLabelText(std::to_string(fontSize));
		}
		break;

	case SizeDialog::FontSize::CANCEL:
		Destroy();
		break;

	case SizeDialog::FontSize::APPLY:
		originalFontSize = fontSize;
		Destroy();
		break;

	case SizeDialog::FontSize::TEXT_CHANGE:
		if (text != "") {
			fontSize = std::stoi(text);
			textCtrl->ChangeValue(text);
		}
		break;
	}
}

int FontSizeDialog::GetFontSize() {
	return originalFontSize;
}


wxBEGIN_EVENT_TABLE(FontSizeDialog, wxDialog)
EVT_BUTTON(SizeDialog::FontSize::DECREMENT, HandleInput)
EVT_BUTTON(SizeDialog::FontSize::INCREMENT, HandleInput)
EVT_BUTTON(SizeDialog::FontSize::APPLY, HandleInput)
EVT_BUTTON(SizeDialog::FontSize::CANCEL, HandleInput)
EVT_TEXT(SizeDialog::FontSize::TEXT_CHANGE, HandleInput)
wxEND_EVENT_TABLE()