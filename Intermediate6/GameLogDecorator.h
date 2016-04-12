#pragma once

#include "GameLog_Observer.h"

/*
Decorator/Observer class. Determine the display method to use.
*/

class GameLogDecorator : public GameLog_Observer {

protected:
	//Observer/Decorator
	GameLog_Observer* decoratedLog;
	//Observable attached to
	GameLog_Subject* _subject;
public:
	GameLogDecorator();
	//Instantiate a decorator
	GameLogDecorator(GameLog_Observer * , GameLog_Subject*);
	//Display method used by decorator GameLog_AllPhase_AllPlayers
	virtual void displayLog();
};
