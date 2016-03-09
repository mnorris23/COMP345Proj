#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/FL_Text_Display.H>
#include <string>
#include <vector>
#include "PowerPlant.H"

class PowerPlantObserver {
public:
	PowerPlantObserver();
	~PowerPlantObserver();
	void hide();
	void show();
	vector<PowerPlant> getPowerPlant() { return pPlant;  }
private:
	Fl_Group* powerplant;
	vector<PowerPlant> pPlant;
};