#include "FontColorDialog.h"

FontColorDialog::FontColorDialog(wxWindow* _window, wxWindowID _id, wxColor _color) : wxDialog(_window, _id, "Text Editor", wxDefaultPosition, wxSize(300, 200))
{
	color = _color;

	//Panels
	wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "Text Color", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
	wxPanel* colorPanel = new wxPanel(this);
	wxPanel* applyPanel = new wxPanel(this);

	//Sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* middleSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* bottomSizer = new wxBoxSizer(wxHORIZONTAL);

	//Assigned Sizers
	mainSizer->AddSpacer(5);
	mainSizer->Add(staticText, wxSizerFlags(0.75).Expand());
	mainSizer->Add(colorPanel, wxSizerFlags(1).Expand());
	mainSizer->Add(applyPanel, wxSizerFlags(1).Expand());
	mainSizer->AddSpacer(5);

	//Interaction Creation
	colorPicker = new wxColourPickerCtrl(colorPanel, wxID_ANY, color);
	wxButton* applyButton = new wxButton(applyPanel, ColorDialog::FontColor::APPLY, "Apply");
	wxButton* cancelButton = new wxButton(applyPanel, ColorDialog::FontColor::CANCEL, "Cancel");

	//Add to Sizers
	middleSizer->AddStretchSpacer(1);
	middleSizer->Add(colorPicker, 0, wxALL, 5);
	middleSizer->AddStretchSpacer(1);

	bottomSizer->AddStretchSpacer(1);
	bottomSizer->Add(applyButton, 0, wxALL, 5);
	bottomSizer->Add(cancelButton, 0, wxALL, 5);
	bottomSizer->AddStretchSpacer(1);

	//SetSizer
	SetSizer(mainSizer);
	colorPanel->SetSizer(middleSizer);
	applyPanel->SetSizer(bottomSizer);

	mainSizer->SetSizeHints(this);

	ShowModal();
	Destroy();
}


FontColorDialog::~FontColorDialog() {

}

void FontColorDialog::HandleInput(wxCommandEvent& event)
{
	switch (event.GetId()) {
	case ColorDialog::FontColor::APPLY:
		color = colorPicker->GetColour();
		Destroy();
		break;

	case ColorDialog::FontColor::CANCEL:
		Destroy();
		break;
	}
}



wxColor FontColorDialog::GetColor()
{
	return color;
}

wxBEGIN_EVENT_TABLE(FontColorDialog, wxDialog)
EVT_BUTTON(ColorDialog::FontColor::APPLY, HandleInput)
EVT_BUTTON(ColorDialog::FontColor::CANCEL, HandleInput)
wxEND_EVENT_TABLE()
