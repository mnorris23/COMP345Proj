#pragma once

#include "Observer.h"
#include "PowerPlantMarket.h"

/*
This class extends the Observer class and when instantiated attach the subject
from class PowerPlantMarket
*/

class PowerPlantMarket_Observer : public Observer {
public:
	PowerPlantMarket_Observer();
	//Attach the powerplant market to this observer
	PowerPlantMarket_Observer(PowerPlantMarket*);
	//Detach subject from observer
	~PowerPlantMarket_Observer();
	//Called from Subject class from Notify() method and redirect to displayMarket();
	void Update();
	//Get the current status of the powerplant market and displays it to the console.
	void displayMarket();
	//Displays the powerplant card.
	static void DisplayPowerplant(PowerPlantMarket::PowerPlant);
	
private:
	PowerPlantMarket *_subject;
};