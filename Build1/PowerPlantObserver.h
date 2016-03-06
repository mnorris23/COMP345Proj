#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/FL_Text_Display.H>
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