#pragma once

#include "GameLogDecorator.h"
#include "GameLog_Observer.h"


/*
Decorator class to display the log from all the players, but for only one phase of the game in the console
*/
class GameLog_OnePhase_AllPlayer : public GameLogDecorator {
public:
	GameLog_OnePhase_AllPlayer(GameLog_Observer* decoratedLog, GameLog_Subject* subject) : GameLogDecorator(decoratedLog, subject){};
	~GameLog_OnePhase_AllPlayer() {};
	//Display the log of one phase including all the players
	void displayLog(int phase);
};
