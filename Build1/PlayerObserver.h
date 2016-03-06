#pragma once

#include "PlayerVector.h"
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/FL_Text_Display.H>
#include <string>


class PlayerObserver{
public:
	PlayerObserver();
	~PlayerObserver();
	void hide();
	void show();
	/**
	Method to diplay the information of the players to the corresponding widget
	@param list The vector of players
	*/
	void displayPlayerInformation(PlayerVector list);
private:
	Fl_Group* playerinfo;

	Fl_Text_Buffer *buffp1;
	Fl_Text_Display* infop1;
	Fl_Text_Buffer *buffp2;
	Fl_Text_Display* infop2;
	Fl_Text_Buffer *buffp3;
	Fl_Text_Display* infop3;
	Fl_Text_Buffer *buffp4;
	Fl_Text_Display* infop4;
	Fl_Text_Buffer *buffp5;
	Fl_Text_Display* infop5;
	Fl_Text_Buffer *buffp6;
	Fl_Text_Display* infop6;

};
