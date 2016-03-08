#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/FL_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <string>

class PowerPlantObserver {
public:
	PowerPlantObserver();
	~PowerPlantObserver();
	void hide();
	void show();
private:
	Fl_Group* powerplant;
};