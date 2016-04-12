#include "GameLog_AllPhase_OnePlayer.h"
#include <iostream>

using namespace std;

/*
Decorator class to display the log from all the phases, but for only one player in the console
*/


//Display the complete log for one player. Takes as argument the color of the player to display the log
void GameLog_AllPhase_OnePlayer::displayLog(string color) {
	string str;
	str += _subject->getGameLog(1, color);
	str += _subject->getGameLog(2, color);
	str += _subject->getGameLog(3, color);
	str += _subject->getGameLog(4, color);
	str += _subject->getGameLog(5, color);

	cout << str << endl;
}
