#pragma once

#include "Observer.h"
#include "GameLog_Subject.h"
#include <string>

/*
This class extends the Observer class and when instantiated attach the subject
from class GameLog_Subject
*/

class GameLog_Observer : public Observer {
public:
	GameLog_Observer() {};
	//Attach the GameLog_Subject to this observer
	GameLog_Observer(GameLog_Subject*);
	//Detach subject from observer
	~GameLog_Observer();
	//Called from Subject class from Notify() method and redirect to displayLog();
	void Update();
	//Get the current status of the Log and displays it to the console.
	virtual void displayLog() {};
	virtual void displayLog(std::string) {};
	virtual void displayLog(int) {};
	virtual void displayLog(int, std::string) {};

protected:
	GameLog_Subject *_subject;
};
