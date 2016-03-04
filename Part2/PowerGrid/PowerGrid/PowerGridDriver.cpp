#include "StartGui.h"

using namespace std;


int main(int argc, char ** argv)
{
	StartGUI *window = new StartGUI();
	return Fl::run();
	delete window;
}





