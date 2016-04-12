#include "GameLog_Observer.h"
#include <iostream>

using namespace std;

//Attach the GameLog_Subject to this observer
GameLog_Observer::GameLog_Observer(GameLog_Subject* subject) {
	_subject = subject;
	_subject->Attach(this);
}

//Detach subject from this observer before destroying observer
GameLog_Observer::~GameLog_Observer() {
	// the parent destructor is called
}
//Redirect to the appropritate display method
void GameLog_Observer::Update() {
	displayLog();
}

