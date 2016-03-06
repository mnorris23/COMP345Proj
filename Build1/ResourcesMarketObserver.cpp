#include "ResourcesMarketObserver.h"

ResourcesMarketObserver::ResourcesMarketObserver() {
	resources = new Fl_Group(0, 540, 885, 70, "Resources");
	resources->begin();
	resources->box(FL_GTK_UP_FRAME);
	resources->color(FL_GRAY0);
	resources->end(); // Fl_Group* resources
}

ResourcesMarketObserver::~ResourcesMarketObserver() {

}

void ResourcesMarketObserver::hide() {
	resources->hide();
}

void ResourcesMarketObserver::show() {
	resources->show();
}