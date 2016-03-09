#include "PlayerObserver.h"

using namespace std;

PlayerObserver::PlayerObserver() {
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
}

PlayerObserver::~PlayerObserver() {

}

void PlayerObserver::hide() {
	playerinfo->hide();
}

void PlayerObserver::show() {
	playerinfo->show();
}

void PlayerObserver::displayPlayerInformation(PlayerVector list) {
	Player player1 = list.getPlayer(0);
	Player player2 = list.getPlayer(1);
	string p1 = player1.getPlayerInformation() + player1.getPayment();
	string p2 = player2.getPlayerInformation() + player2.getPayment();

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

}