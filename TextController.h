#pragma once
#include <wx/wx.h>


class TextController: public wxTextCtrl
{
private:
	int fontSize;

public:
	TextController(wxWindow* _parent, wxWindowID _id);
	virtual bool HasMultiplePages() const override;
	void CreateNewText();
	int GetFontSize();
	void SetFontSize(int size);
};

