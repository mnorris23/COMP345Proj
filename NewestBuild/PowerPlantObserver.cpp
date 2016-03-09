#include "PowerPlantObserver.h"

PowerPlantObserver::PowerPlantObserver() {
	powerplant = new Fl_Group(885, 0, 460, 245, "PowerPlantMarket");
	powerplant->begin();
	powerplant->box(FL_ROUNDED_FRAME);
	powerplant->color(FL_GRAY0);
	powerplant->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
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