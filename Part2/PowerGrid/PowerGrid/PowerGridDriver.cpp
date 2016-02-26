#include "powergrid.h"
#include <FL/Fl.H>
#include <FL/Fl_window.H>
#include <FL/Fl_Button.H>
using namespace std;


int main(int argc, char ** argv)
{
	StartGUI *window = new StartGUI();
	return Fl::run();
	delete window;
}





