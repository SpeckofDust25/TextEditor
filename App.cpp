#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App);	//Creates An Instance and Starts the Program

bool App::OnInit() {
	mainWindow = new Window("Text Editor", wxPoint(50, 50), wxSize(450, 340));
	mainWindow->Show(true);

	//Get Command Line Arguments
	wxCmdLineParser parser;
	parser.Parse(true);

	
	//Get the Filename from the command-line arguments
	wxString filename;
	if (argc > 1) {
		filename = argv[1];

		//Open the Text File
		if (!filename.IsEmpty()) {
			wxFileName file(filename);

			if (file.FileExists()) {
				mainWindow->LoadFile(file.GetFullPath());
			}
		}
	}
	
	return true;
}