#pragma once


#include "PlayerVector.h"
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_window.H>
#include <FL/Fl_Button.H>
#include <FL/FL_Toggle_Button.H>
#include <FL/FL_Text_Display.H>
#include <FL/FL_Choice.H>
#include <FL/FL_Menu_Item.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Table.H>
#include <cstdlib> 

/**
Class to define the main Window for the game.
*/
class StartGUI {
public:
	/**
	Default constructor
	*/
	StartGUI();
	/**
	Default destructor
	*/
	~StartGUI();
	/**
	CallBack method when pressing the two players button.
	@see twoplayers_cb_i
	*/
	static void twoplayers_cb(Fl_Widget*, void*);
	/**
	Method with only purpose is to hide and show some widget
	*/
	void twoplayers_cb_i(Fl_Widget*, void*);
	/**
	CallBack method when pressing the start button.
	@see start_cb_i
	*/
	static void start_cb(Fl_Widget*, void*);
	/**
	Method with only purpose is redirect to waitToStart() method
	@see waitToStart()
	*/
	void start_cb_i(Fl_Widget*, void*);
	/**
	Method to determine if the start button has been pressed
	@return value of button
	*/
	int getStartButtonValue();
	/**
	Method get the name for the first player from the input field
	@return name of button
	*/
	std::string getFirstPlayerName();
	/**
	Method get the name for the second player from the input field
	@return name of player
	*/
	std::string getSecondPlayerName();
	/**
	Method get the color for the first player from the dropdown box menu
	@return color of player
	*/
	int getFirstPlayerColor();
	/**
	Method get the color for the second player from the dropdown box menu
	@return color of player
	*/
	int getSecondPlayerColor();
	/**
	Method to obtain the information from the input field, create the players and add them to the vector of players.
	Also hide and show some widgets.
	*/
	void waitToStart();
	/**
	Method to diplay the information of the players to the corresponding widget
	@param list The vector of players
	*/
	void displayPlayerInformation(PlayerVector list);

private:
	Fl_Window* mainWindow;

	Fl_Text_Buffer *buff;
	Fl_Text_Display *welcome;
	Fl_Button* twoplayers;

	Fl_Toggle_Button* start;
	Fl_Input* first_player_name;
	Fl_Input* second_player_name;
	Fl_Choice* first_player_color;
	Fl_Choice* second_player_color;

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
	Fl_Text_Buffer *buff_summary;
	Fl_Text_Display* info_summary;


	Fl_Group* playerinfo;
	Fl_Group* map;
	Fl_Group* market;
	Fl_Group* resources;
	Fl_Group* summary;

};
