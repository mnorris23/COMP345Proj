#include "MapObserver.h"

using namespace std;

MapObserver::MapObserver() {
	map = new Fl_Group(0, 0, 885, 540, "MAP");
	map->begin();
	map->box(FL_GTK_UP_FRAME);
	map->color(FL_BLACK);
	map->labelsize(46);
	map->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	map->end(); // Fl_Group* map
}

MapObserver::~MapObserver() {

}

void MapObserver::hide() {
	map->hide();
}

void MapObserver::show() {
	map->show();
}