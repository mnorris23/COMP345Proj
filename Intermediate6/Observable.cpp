#include "Observable.h"
#include "PowerPlantMarket_Observer.h"

#include <iostream>

using namespace std;

Observable::Observable() {
	observers = new list<Observer*>;
}

Observable::~Observable() {
	delete observers;
}

void Observable::Attach(Observer* o) {
	observers->push_back(o);
}

void Observable::Detach(Observer* o) {
	observers->remove(o);
}

void Observable::Notify() {
	for (list<Observer*>::iterator it = observers->begin(); it != observers->end(); ++it) {
		(*it)->Update();
	}
}

void Observable::Notify(bool step3) {
	for (list<Observer*>::iterator it = observers->begin(); it != observers->end(); ++it) {
		dynamic_cast<PowerPlantMarket_Observer*>(*it)->Update(step3);
	}
}