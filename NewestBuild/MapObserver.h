#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class MapObserver {
public:
	MapObserver();
	~MapObserver();
	void hide();
	void show();
private:
	Fl_Group* map;
};
