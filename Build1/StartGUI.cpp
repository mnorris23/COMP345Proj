#include "StartGui.h"

using namespace std;


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

	playerinfo = new PlayerObserver();

	map = new MapObserver();

	resources = new ResourcesMarketObserver();

	powerplant = new PowerPlantObserver();

	summary = new SummaryCardObserver();

	
	
	playerinfo->hide();
	map->hide();
	resources->hide();
	powerplant->hide();
	summary->hide();

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

	playerinfo->displayPlayerInformation(playerlist);

	playerinfo->show();
	map->show();
	resources->show();
	powerplant->show();
	summary->show();
}
