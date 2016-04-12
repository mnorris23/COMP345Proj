#include "ResourceMarket_Observer.h"
#include "ResourceMarket.h"
#include <iostream>

using namespace std;

ResourceMarket_Observer::ResourceMarket_Observer() {

}
//Attach the resource market to this observer
ResourceMarket_Observer::ResourceMarket_Observer(ResourceMarket* subject) {
	_subject = subject;
	_subject->Attach(this);
}
//Detach subject from this observer before destroying observer
ResourceMarket_Observer::~ResourceMarket_Observer() {
	_subject->Detach(this);
}

void ResourceMarket_Observer::Update() {
	DisplayMarket();
}

//Get the current status of the resource market and displays it to the console.
void ResourceMarket_Observer::DisplayMarket() {

	_subject->DisplayMarket();

}


