#include "GameLog_Subject.h"
#include "GameLog_AllPhase_AllPlayer.h"

using namespace std;


/*
Derived Observable class to manage the log of all the players in all the phases of the game
*/
GameLog_Subject::GameLog_Subject() {
	phase1 = new GameLogPhase();
	phase2 = new GameLogPhase();
	phase3 = new GameLogPhase();
	phase4 = new GameLogPhase();
	phase5 = new GameLogPhase();
}

GameLog_Subject::~GameLog_Subject() {
	delete phase1;
	delete phase2;
	delete phase3;
	delete phase4;
	delete phase5;
}

//Overloading Notify() to only print the last log, not the entire log
void GameLog_Subject::Notify(string str) {
	for (list<Observer*>::iterator it = observers->begin(); it != observers->end(); ++it) {
		dynamic_cast<GameLog_AllPhase_AllPlayer*>(*it)->Update(str); //Unsafe but needed
	}
}

//Method that will notify the observer of a change in the logs.
void GameLog_Subject::updateLog(string str, int phase, bool printAll, string color) {
	

	switch (phase) {
		case 1: 
			phase1->addLog(str, color); break;
		case 2: 
			phase2->addLog(str, color); break;
		case 3: 
			phase3->addLog(str, color); break;
		case 4: 
			phase4->addLog(str, color); break;
		case 5: 
			phase5->addLog(str, color); break;
	}

	allLog += str;

	if (printAll)
		Observable::Notify();
	else
		Notify(str);

}

//Return Log for a specific phase and player
string GameLog_Subject::getGameLog(int phase, string color) {

	string str; 

	switch (phase) {
		case 1: str = phase1->getLog(color); break;
		case 2: str = phase2->getLog(color); break;
		case 3: str = phase3->getLog(color); break;
		case 4: str = phase4->getLog(color); break;
		case 5: str = phase5->getLog(color); break;
		default: str = allLog;
	}

	return str;
}