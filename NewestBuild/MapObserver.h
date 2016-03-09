#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/FL_Text_Display.H>
#include <string>
#include <vector>
#include "Map.H"

class MapObserver {
public:
	MapObserver();
	MapObserver(Map);
	~MapObserver();
	void hide();
	void show();
	static void city_cb(Fl_Widget*, void*);
	void city_cb_i(Fl_Widget*, void*);
	void displayCityInfo(const char * label);
private:
	Fl_Group* map;
	Fl_Text_Buffer* buff;
	Fl_Text_Display* sometext;

	Fl_Button* boavista1;
};
