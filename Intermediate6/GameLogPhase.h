#pragma once

#include <string>

/*
Class holding a different log for each players and a log for all the players
*/
class GameLogPhase {
public:
	GameLogPhase() {};
	~GameLogPhase() {};
	//Add log for a specific player
	void addLog(std::string str, std::string color = "all");
	//Get log for a specific player
	std::string getLog(std::string color = "all");

private:
	std::string player1;
	std::string player2;
	std::string player3;
	std::string player4;
	std::string player5;
	std::string player6;
	std::string allPlayers;
};
