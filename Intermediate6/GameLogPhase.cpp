#pragma once

#include "GameLogPhase.h"

using namespace std;

/*
Class holding a different log for each players and a log for all the players
*/

//Add log for a specific player
void GameLogPhase::addLog(string str, string color) {

	if (color.compare("red") == 0) {
		player1 += str;
		allPlayers += str;
	}
	else if (color.compare("blue") == 0) {
		player2 += str;
		allPlayers += str;
	}
	else if (color.compare("green") == 0) {
		player3 += str;
		allPlayers += str;
	}
	else if (color.compare("yellow") == 0) {
		player4 += str;
		allPlayers += str;
	}
	else if (color.compare("pink") == 0) {
		player5 += str;
		allPlayers += str;
	}
	else if (color.compare("orange") == 0) {
		player6 += str;
		allPlayers += str;
	}
	else {
		player1 += str;
		player2 += str;
		player3 += str;
		player4 += str;
		player5 += str;
		player6 += str;
		allPlayers += str;
	}

}

//Get log for a specific player
string GameLogPhase::getLog(string color) {

	if (color.compare("red") == 0) {
		return player1;
	}
	else if (color.compare("blue") == 0) {
		return player2;
	}
	else if (color.compare("green") == 0) {
		return player3;
	}
	else if (color.compare("yellow") == 0) {
		return player4;
	}
	else if (color.compare("pink") == 0) {
		return player5;
	}
	else if (color.compare("orange") == 0) {
		return player6;
	}
	else {
		return allPlayers;
	}

}


