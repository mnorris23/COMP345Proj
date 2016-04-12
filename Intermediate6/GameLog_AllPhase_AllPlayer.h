#pragma once

#include "GameLogDecorator.h"

/*
Decorator class to display all the log from all the phases and all the players in the console
*/
class GameLog_AllPhase_AllPlayer : public GameLogDecorator {
public:
	GameLog_AllPhase_AllPlayer(GameLog_Observer* decoratedLog, GameLog_Subject* subject) : GameLogDecorator(decoratedLog, subject) {};
	~GameLog_AllPhase_AllPlayer() {};
	//Update method only to display the last log in the console. Argument is the last log.
	void Update(std::string str);
	//Display all the logs 
	void displayLog();
	//Display the last log only
	void displayLog(std::string);
};
