#include "PowerPlantObserver.h"

PowerPlantObserver::PowerPlantObserver() {
	powerplant = new Fl_Group(885, 0, 785, 255, "PowerPlant Market");
		powerplant->begin();
		powerplant->box(FL_UP_BOX);
		powerplant->color((Fl_Color)161);
		powerplant->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));

		Fl_Group* pp1 = new Fl_Group(920, 130, 115, 100, "PP1");
			pp1->box(FL_DOWN_BOX);
			pp1->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl1 = new Fl_Text_Display(920, 130, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b1 = new Fl_Button(946, 208, 64, 20, "BID");
			// Fl_Button* o
		pp1->end();

		Fl_Group* pp2 = new Fl_Group(1040, 130, 115, 100, "PP2");
			pp2->box(FL_DOWN_BOX);
			pp2->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl2 = new Fl_Text_Display(1040, 130, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b2 = new Fl_Button(1066, 208, 64, 20, "BID");
			// Fl_Button* o
		pp2->end();

		Fl_Group* pp3 = new Fl_Group(1160, 130, 115, 100, "PP3");
			pp3 ->box(FL_DOWN_BOX);
			pp3 ->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl3 = new Fl_Text_Display(1160, 130, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b3 = new Fl_Button(1186, 208, 64, 20, "BID");
			// Fl_Button* o
		pp3 ->end();

		Fl_Group* pp4 = new Fl_Group(1280, 130, 115, 100, "PP4");
			pp4->box(FL_DOWN_BOX);
			pp4->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl4 = new Fl_Text_Display(1280, 130, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b4 = new Fl_Button(1306, 208, 64, 20, "BID");
			// Fl_Button* o
		pp4->end();

		Fl_Group* pp5 = new Fl_Group(1280, 20, 115, 100, "PP5");
			pp5->box(FL_DOWN_BOX);
			pp5->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl5 = new Fl_Text_Display(1280, 20, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b5 = new Fl_Button(1306, 98, 64, 20, "BID");
			// Fl_Button* o
		pp5->end();

		Fl_Group* pp6 = new Fl_Group(1160, 20, 115, 100, "PP6");
			pp6->box(FL_DOWN_BOX);
			pp6->labeltype(FL_NO_LABEL);
			Fl_Text_Display* fl6 = new Fl_Text_Display(1160, 20, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b6 = new Fl_Button(1186, 98, 64, 20, "BID");
			// Fl_Button* o
		pp6->end();

		Fl_Group* pp7 = new Fl_Group(1040, 20, 115, 100, "PP7");
			pp7->box(FL_DOWN_BOX);
			pp7->labeltype(FL_NO_LABEL);
			Fl_Text_Display* f7 = new Fl_Text_Display(1040, 20, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b7 = new Fl_Button(1066, 98, 64, 20, "BID");
			// Fl_Button* o
		pp7->end();

		Fl_Group* pp8 = new Fl_Group(920, 20, 115, 100, "PP8");
			pp8->box(FL_DOWN_BOX);
			pp8->labeltype(FL_NO_LABEL);
			Fl_Text_Display* f8 = new Fl_Text_Display(920, 20, 115, 75);
			// Fl_Text_Display* o
			Fl_Button* b8 = new Fl_Button(946, 98, 64, 20, "BID");
			// Fl_Button* o
		pp8->end();

		Fl_Group* auction = new Fl_Group(1425, 30, 200, 200, "Auction");
			auction->box(FL_BORDER_BOX);
			auction->color((Fl_Color)51);
			Fl_Text_Display* log = new Fl_Text_Display(1430, 35, 190, 145);
			log->box(FL_BORDER_FRAME);
			log->color((Fl_Color)41);
			log->selection_color(FL_GRAY0);
			// Fl_Text_Display* o
			Fl_Button* bid = new Fl_Button(1590, 196, 29, 24, "BID");
			Fl_Input* input = new Fl_Input(1495, 196, 90, 24, "Write Bid");
			// Fl_Button* o
		auction->end();

	powerplant->end(); // Fl_Group* market

}

PowerPlantObserver::~PowerPlantObserver() {

}

void PowerPlantObserver::hide() {
	powerplant->hide();
}

void PowerPlantObserver::show() {
	powerplant->show();
}