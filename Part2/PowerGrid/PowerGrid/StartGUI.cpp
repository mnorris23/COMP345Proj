#include "powergrid.h"
#include "PaymentTable.cpp"
#include <iostream>
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
#include <cstdlib>   //for exit(0)
#include <string.h>
#include <vector>

using namespace std;

PaymentTable* payment;
SummaryCard summaryCard;


StartGUI::StartGUI() {
	mainWindow = new Fl_Window(1347, 881, "PowerGrid Board Game");
	mainWindow->user_data((void*)(this));
	mainWindow->begin();
	buff = new Fl_Text_Buffer();
	welcome = new Fl_Text_Display(518, 385, 310, 50);
	welcome->buffer(buff);
	welcome->color(FL_DARK3);
	buff->text("PowerGrid Board Game\n Select # of players.");
	twoplayers = new Fl_Button(586, 460, 175, 65, "2 Players");

	twoplayers->callback((Fl_Callback*)twoplayers_cb);


	start = new Fl_Toggle_Button(590, 505, 175, 65, "Start");
	start->value(0);
	first_player_name = new Fl_Input(431, 422, 265, 43, "First Player Name");
	second_player_name = new Fl_Input(431, 462, 265, 43, "Second player Name");
	first_player_color = new Fl_Choice(716,422,190,43);
	second_player_color = new Fl_Choice(716, 462, 190, 43);
	first_player_color->add("red");
	first_player_color->add("green");
	first_player_color->add("yellow"); 
	first_player_color->add("blue");
	first_player_color->add("pink");
	first_player_color->add("orange");
	first_player_color->value(0);
	second_player_color->add("red");
	second_player_color->add("green");
	second_player_color->add("yellow");
	second_player_color->add("blue");
	second_player_color->add("pink");
	second_player_color->add("orange");
	second_player_color->value(0);

	start->hide();
	first_player_name->hide();
	second_player_name->hide();
	first_player_color->hide();
	second_player_color->hide();

	start->callback((Fl_Callback*)start_cb);

	playerinfo = new Fl_Group(0, 605, 1355, 280, "Player Info");
	playerinfo->begin();
	Fl_Group* player1 = new Fl_Group(0, 610, 225, 270, "Player1");
	player1->begin();
	player1->box(FL_UP_BOX);
	player1->color(FL_RED);
	player1->labelsize(18);
	player1->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp1 = new Fl_Text_Buffer();
	infop1 = new Fl_Text_Display(10, 640, 205, 230);
	infop1->buffer(buffp1);
	infop1->color(FL_RED);
	player1->end(); // Fl_Group* player1

	Fl_Group* player2 = new Fl_Group(225, 610, 225, 270, "Player2");
	player2->begin();
	player2->box(FL_UP_BOX);
	player2->color((Fl_Color)62);
	player2->selection_color((Fl_Color)57);
	player2->labelsize(18);
	player2->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp2 = new Fl_Text_Buffer();
	infop2 = new Fl_Text_Display(234, 640, 205, 230);
	infop2->buffer(buffp2);
	infop2->color((Fl_Color)62);
	player2->end(); // Fl_Group* player2

	Fl_Group* player3 = new Fl_Group(445, 610, 225, 270, "Player3");
	player3->begin();
	player3->box(FL_UP_BOX);
	player3->color((Fl_Color)179);
	player3->labelsize(18);
	player3->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp3 = new Fl_Text_Buffer();
	infop3 = new Fl_Text_Display(458, 640, 205, 230);
	infop3->buffer(buffp3);
	infop3->color((Fl_Color)179);
	player3->end(); // Fl_Group* player3

	Fl_Group* player4 = new Fl_Group(670, 610, 225, 270, "Player4");
	player4->begin();
	player4->box(FL_UP_BOX);
	player4->color((Fl_Color)3);
	player4->labelsize(18);
	player4->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp4 = new Fl_Text_Buffer();
	infop4 = new Fl_Text_Display(682, 640, 205, 230);
	infop4->buffer(buffp4);
	infop4->color((Fl_Color)3);
	player4->end(); // Fl_Group* player4

	Fl_Group* player5 = new Fl_Group(895, 610, 225, 270, "Player5");
	player5->begin();
	player5->box(FL_UP_BOX);
	player5->color((Fl_Color)211);
	player5->labelsize(18);
	player5->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp5 = new Fl_Text_Buffer();
	infop5 = new Fl_Text_Display(906, 640, 205, 230);
	infop5->buffer(buffp5);
	infop5->color((Fl_Color)211);
	player5->end(); // Fl_Group* player5

	Fl_Group* player6 = new Fl_Group(1120, 610, 225, 270, "Player6");
	player6->begin();
	player6->box(FL_UP_BOX);
	player6->color((Fl_Color)90);
	player6->labelsize(18);
	player6->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buffp6 = new Fl_Text_Buffer();
	infop6 = new Fl_Text_Display(1130, 640, 205, 230);
	infop6->buffer(buffp6);
	infop6->color((Fl_Color)90);
	player6->end(); // Fl_Group* player6
	playerinfo->end(); // Fl_Group* playerinfo

	map = new Fl_Group(0, 0, 885, 540, "MAP");
	map->begin();
	map->box(FL_GTK_UP_FRAME);
	map->color(FL_BLACK);
	map->labelsize(46);
	map->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	map->end(); // Fl_Group* map

	resources = new Fl_Group(0, 540, 885, 70, "Resources");
	resources->begin();
	resources->box(FL_GTK_UP_FRAME);
	resources->color(FL_GRAY0);
	resources->end(); // Fl_Group* resources

	market = new Fl_Group(885, 0, 460, 245, "PowerPlantMarket");
	market->begin();
	market->box(FL_ROUNDED_FRAME);
	market->color(FL_GRAY0);
	market->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	market->end(); // Fl_Group* market

	summary = new Fl_Group(885, 245, 460, 365, "Summary Card");
	summary->begin();
	summary->box(FL_ROUNDED_FRAME);
	summary->color(FL_BLACK);
	summary->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buff_summary = new Fl_Text_Buffer();
	info_summary = new Fl_Text_Display(900, 262, 430, 184);
	info_summary->buffer(buff_summary);
	info_summary->wrap_mode(3, 0);
	
	string sum = summaryCard.allPhases();
	const char * str = sum.data();
	buff_summary->text(str);
	info_summary->color(FL_DARK3);
	summary->end(); // Fl_Group* summary

	payment = new PaymentTable(890, 455, 455, 155);
	
	payment->end(); // Fl_Table* payment
	
	playerinfo->hide();
	map->hide();
	resources->hide();
	market->hide();
	summary->hide();
	payment->hide();

	mainWindow->end();
	mainWindow->show();
}

StartGUI::~StartGUI() {

}

void StartGUI::twoplayers_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->twoplayers_cb_i(w, v);
}

void StartGUI::twoplayers_cb_i(Fl_Widget* , void* )
{
	welcome->hide();
	twoplayers->hide();
	start->show();
	first_player_name->show();
	second_player_name->show();
	first_player_color->show();
	second_player_color->show();	
}

void StartGUI::start_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->start_cb_i(w, v);
}

void StartGUI::start_cb_i(Fl_Widget*, void*) {
	waitToStart();
}

int StartGUI::getStartButtonValue() {
	return start->value();
}

string StartGUI::getFirstPlayerName() {
	return first_player_name->value();
}

string StartGUI::getSecondPlayerName() {
	return second_player_name->value();
}

int StartGUI::getFirstPlayerColor() {
	return first_player_color->value();
}

int StartGUI::getSecondPlayerColor() {
	return second_player_color->value();
}

void StartGUI::waitToStart() {
	Player player1;
	Player player2;
	PlayerVector playerlist(2);
	if (start->value() == 1) {
		player1 = Player(getFirstPlayerName(), getFirstPlayerColor());
		player2 = Player(getSecondPlayerName(), getSecondPlayerColor());
		playerlist.setPlayer(player1, 0);
		playerlist.setPlayer(player2, 1);
	}
		
	start->hide();
	first_player_name->hide();
	second_player_name->hide();
	first_player_color->hide();
	second_player_color->hide();
	displayPlayerInformation(playerlist);
}

void StartGUI::displayPlayerInformation(PlayerVector list) {
	Player player1 = list.getPlayer(0);
	Player player2 = list.getPlayer(1);
	string p1 = player1.getPlayerInformation() + summaryCard.payment(player1);
	string p2 = player2.getPlayerInformation() + summaryCard.payment(player2);

	const char * str1 = p1.data();
	const char * str2 = p2.data();

	string color1 = player1.getColor();
	string color2 = player2.getColor();

	if (color1 == "red") buffp1->text(str1);
	else if (color1 == "green") buffp2->text(str1);
	else if (color1 == "blue") buffp3->text(str1);
	else if (color1 == "yellow") buffp4->text(str1);
	else if (color1 == "pink") buffp5->text(str1); 
	else if (color1 == "orange") buffp6->text(str1);

	if (color2 == "red") buffp1->text(str2);
	else if (color2 == "green") buffp2->text(str2);
	else if (color2 == "blue") buffp3->text(str2);
	else if (color2 == "yellow") buffp4->text(str2);
	else if (color2 == "pink") buffp5->text(str2);
	else if (color2 == "orange") buffp6->text(str2);

	
	playerinfo->show();
	map->show();
	resources->show();
	market->show();
	summary->show();
	payment->show();
}
