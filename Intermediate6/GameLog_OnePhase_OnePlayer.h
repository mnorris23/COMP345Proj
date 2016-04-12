#pragma once

#include "GameLogDecorator.h"
#include "GameLog_Observer.h"
/*
Decorator class to display the log from only one player and from only one phase of the game in the console
*/
class GameLog_OnePhase_OnePlayer : public GameLogDecorator {
public:
	GameLog_OnePhase_OnePlayer(GameLog_Observer* decoratedLog, GameLog_Subject* subject) : GameLogDecorator(decoratedLog, subject){};
	~GameLog_OnePhase_OnePlayer() {};
	//Display the log of one phase for one player
	void displayLog(int phase, std::string color);
};
