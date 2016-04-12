#include "PowerPlantMarket_Observer.h"
#include "PowerPlantMarket.h"
#include <iostream>

using namespace std;

PowerPlantMarket_Observer::PowerPlantMarket_Observer() {

}
//Attach the powerplant market to this observer
PowerPlantMarket_Observer::PowerPlantMarket_Observer(PowerPlantMarket* subject) {
	_subject = subject;
	_subject->Attach(this);
}
//Detach subject from this observer before destroying observer
PowerPlantMarket_Observer::~PowerPlantMarket_Observer() {
	_subject->Detach(this);
}

void PowerPlantMarket_Observer::Update() {
	displayMarket();
}

//Get the current status of the powerplant market and displays it to the console.
void PowerPlantMarket_Observer::displayMarket() {

	cout << "\n-------------------------------------";
	cout << "\nDisplaying Future Market:" << endl;

	for (int i = 0; i < 4; i++){
		DisplayPowerplant(_subject->getPowerPlant(1, i));
	}
	cout << "\n-------------------------------------" << endl;
	cout << "\nDisplaying Current Market:" << endl;

	for (int i = 0; i < 4; i++){
		cout << "\n\tPowerplant " << i + 1 << endl;
		DisplayPowerplant(_subject->getPowerPlant(0, i));
	}
	cout << "-------------------------------------";
}

/*
Displays a powerplant.
*/
void PowerPlantMarket_Observer::DisplayPowerplant(PowerPlantMarket::PowerPlant powerplant) {
	//a string with the name of the resource being stored
	std::string type;
	//Setting the name according to type
	switch (powerplant.GetResType()) {
	case 0: type = "Coal"; break;
	case 1: type = "Oil"; break;
	case 2: type = "Garbage"; break;
	case 3: type = "Uranium"; break;
	case 4: type = "Coal and Oil"; break;
	default: type = "None";
	}
	//displaying powerplant name, cities powered, max cities powered, resource needed, resource cost and resources stored
	cout << "\nValue: " << powerplant.GetValue()
		<< "\n\tMax Cities Powered: " << powerplant.GetMaxCitiesPowered()
		<< "\n\tResources needed: " << type
		<< "\n\tResource cost: " << powerplant.GetResCost()
		<< "\n\Number of Resources Stored: " << powerplant.GetAmountStored() << endl;
}

