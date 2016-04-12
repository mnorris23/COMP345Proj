#pragma once

#include <vector>
#include <string>
#include "Observable.h"
#include "GameLogPhase.h"

/*
Derived Observable class to manage the log of all the players in all the phases of the game
*/

class GameLog_Subject : public Observable {

private:
	//Each member hold the log of all the players for a specific phase
	GameLogPhase* phase1;
	GameLogPhase* phase2;
	GameLogPhase* phase3;
	GameLogPhase* phase4;
	GameLogPhase* phase5;
	//String containing all the log from all the phases and all the players
	std::string allLog;


public:
	GameLog_Subject();
	~GameLog_Subject();

	//Overloading Notify() to only print the last log, not the entire log
	void Notify(std::string);
	//Method that will notify the observer of a change in the logs.
	void updateLog(std::string str, int phase, bool printAll, std::string color);
	//Return Log for a specific phase and player
	std::string getGameLog(int phase = 0, std::string color = "all");

};
