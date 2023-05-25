#include "FontSizeDialog.h"


FontSizeDialog::FontSizeDialog(wxWindow* parent, wxWindowID id): wxDialog(parent, id, "Text Editor", wxDefaultPosition, wxSize(300, 200)) {

	wxIntegerValidator<int> intValidator(&m_value, 0, 99);

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
	
	wxButton* left = new wxButton(interactPanel, TextEditor::DECREMENT, "-");
	wxButton* right = new wxButton(interactPanel, TextEditor::INCREMENT, "+");

	textCtrl = new wxTextCtrl(interactPanel, TextEditor::TEXT_CHANGE, "8", wxDefaultPosition, wxDefaultSize, wxTE_CENTER, intValidator);
	
	wxButton* apply = new wxButton(applyPanel, TextEditor::APPLY, "Apply");
	wxButton* cancel = new wxButton(applyPanel, TextEditor::CANCEL, "Cancel");

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

	case TextEditor::FontSize::DECREMENT:
		if (m_value > 0) {
			m_value -= 1;
			textCtrl->SetLabelText(std::to_string(m_value));
		}
		break;

	case TextEditor::FontSize::INCREMENT:
		if (m_value < 99) {
			m_value += 1;
			textCtrl->SetLabelText(std::to_string(m_value));
		}
		break;

	case TextEditor::FontSize::CANCEL:
		Destroy();
		break;

	case TextEditor::FontSize::APPLY:
		Destroy();
		break;

	case TextEditor::FontSize::TEXT_CHANGE:
		if (text != "") {
			m_value = std::stoi(text);
			textCtrl->ChangeValue(text);
		}
		break;
	}
}


wxBEGIN_EVENT_TABLE(FontSizeDialog, wxDialog)
EVT_BUTTON(TextEditor::DECREMENT, HandleInput)
EVT_BUTTON(TextEditor::INCREMENT, HandleInput)
EVT_BUTTON(TextEditor::APPLY, HandleInput)
EVT_BUTTON(TextEditor::CANCEL, HandleInput)
EVT_TEXT(TextEditor::TEXT_CHANGE, HandleInput)
wxEND_EVENT_TABLE()