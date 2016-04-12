#include "GameLog_OnePhase_OnePlayer.h"
#include <iostream>

using namespace std;
/*
Decorator class to display the log from only one player and from only one phase of the game in the console
*/

//Display the log of one phase for one player
void GameLog_OnePhase_OnePlayer::displayLog(int phase, string color) {
	string str;
	str += _subject->getGameLog(phase, color);

	cout << str << endl;
}

