#pragma once
#include "wx/wxprec.h"
#include "Window.h"

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class App: public wxApp
{
public:
	Window* mainWindow = nullptr;
	virtual bool OnInit();
};

