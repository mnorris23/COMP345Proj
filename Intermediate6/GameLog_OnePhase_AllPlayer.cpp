#include "GameLog_OnePhase_AllPlayer.h"
#include <iostream>

using namespace std;


/*
Decorator class to display the log from all the players, but for only one phase of the game in the console
*/

//Display the log of one phase including all the players
void GameLog_OnePhase_AllPlayer::displayLog(int phase) {
	
	string str;
	str += _subject->getGameLog(phase, "all");
	
	cout << str << endl;
}

