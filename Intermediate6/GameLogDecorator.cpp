#pragma once

#include "GameLogDecorator.h"

using namespace std;

/*
Decorator/Observer class. Determine the display method to use.
*/
GameLogDecorator::GameLogDecorator() {
}
//Instantiate a decorator
GameLogDecorator::GameLogDecorator(GameLog_Observer * gameLog, GameLog_Subject* subject) {
	this->decoratedLog = gameLog;
	this->_subject = subject;
}

//Display method used by decorator GameLog_AllPhase_AllPlayers
void GameLogDecorator::displayLog() {
	decoratedLog->displayLog();
}


