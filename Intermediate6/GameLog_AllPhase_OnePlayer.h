#pragma once

#include "GameLogDecorator.h"
#include "GameLog_Observer.h"

/*
Decorator class to display the log from all the phases, but for only one player in the console
*/
class GameLog_AllPhase_OnePlayer : public GameLogDecorator {
public:
	GameLog_AllPhase_OnePlayer(GameLog_Observer* decoratedLog, GameLog_Subject* subject) : GameLogDecorator(decoratedLog, subject){};
	~GameLog_AllPhase_OnePlayer() {};
	//Display the complete log for one player. Takes as argument the color of the player to display the log
	void displayLog(std::string color);
};