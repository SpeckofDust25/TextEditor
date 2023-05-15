#include "Window.h"


Window::Window(const wxString _title, const wxPoint _point, const wxSize _size) :
	wxFrame(nullptr, wxID_ANY, _title, _point, _size) {

}