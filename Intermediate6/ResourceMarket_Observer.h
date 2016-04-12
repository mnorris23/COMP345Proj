#pragma once

#include "Observer.h"
#include "ResourceMarket.h"

/*
This class extends the Observer class and when instantiated attach the subject
from class ResourceMarket
*/

class ResourceMarket_Observer : public Observer {
public:
	ResourceMarket_Observer();
	//Attach the powerplant market to this observer
	ResourceMarket_Observer(ResourceMarket*);
	//Detach subject from observer
	~ResourceMarket_Observer();
	//Called from Subject class from Notify() method and redirect to displayMarket();
	void Update();
	//Get the current status of the resource market and displays it to the console.
	void DisplayMarket();

private:
	ResourceMarket *_subject;
};