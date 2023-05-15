#pragma once
#include <wx/wx.h>


class TextController: public wxTextCtrl
{
public:
	TextController(wxWindow* _parent, wxWindowID _id);
	virtual bool HasMultiplePages() const override;

};

