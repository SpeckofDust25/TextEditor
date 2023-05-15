#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App);	//Creates An Instance and Starts the Program

bool App::OnInit() {
	mainWindow = new Window("Text Editor", wxPoint(50, 50), wxSize(450, 340));
	mainWindow->Show(true);
	return true;
}