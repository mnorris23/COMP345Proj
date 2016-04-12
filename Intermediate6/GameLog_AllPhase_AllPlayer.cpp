#include "GameLog_AllPhase_AllPlayer.h"
#include <iostream>

using namespace std;

/*
Decorator class to display all the log from all the phases and all the players in the console
*/

//Update method only to display the last log in the console. Argument is the last log.
void GameLog_AllPhase_AllPlayer::Update(string str) {
	GameLog_AllPhase_AllPlayer::displayLog(str);
}
//Display all the logs 
void GameLog_AllPhase_AllPlayer::displayLog() {
	cout << _subject->getGameLog() << endl;
}
//Display the last log only
void  GameLog_AllPhase_AllPlayer::displayLog(string str) {
	cout << str << endl;
}
