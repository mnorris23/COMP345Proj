#include "Player.h"
#include <iostream>

using namespace std;


//Strategy constructors

Player::Player(Strategy *initStrat){

	this->strategy = initStrat;

	name = "unknown";
	color = "blue";
	money = 50;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;

	Notify();
};

Player::Player(std::string aname, std::string acolor, int money, Strategy *initStrat){

	this->strategy = initStrat;

	money = 50;
	name = aname;
	color = acolor;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();

	Notify();

};


//Strategy methods

void Player::setStrategy(Strategy *newStrat){				//how to access player ****
	this->strategy = newStrat;

};

void Player::executeStrategy(){								//how to access player ****

	//execute the turn for the player with the aligned strategy
	this->strategy->execute(this);

};



Player::Player(string aname, int acolor, int maxNumberOfPplants) : maxNumberOfPowerplants(maxNumberOfPplants) {
	name = aname;
	money = 50;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();
	switch (acolor) {
	case 0: color = "red"; break;
	case 1: color = "green"; break;
	case 2: color = "yellow"; break;
	case 3: color = "blue"; break;
	case 4: color = "pink"; break;
	case 5: color = "orange"; break;

		Notify();
	}
}

Player::Player(string aname, int maxNumberOfPplants) : name(aname), color("orange"), money(50), numberOfPowerPlant(0), numberOfHouses(0), maxNumberOfPowerplants(maxNumberOfPplants) {

}
Player::Player(std::string aname, std::string acolor, int maxNumberOfPplants) : maxNumberOfPowerplants(maxNumberOfPplants) {
	money = 50;
	name = aname;
	color = acolor;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();

	Notify();
}

Player::Player(std::string aname, std::string acolor, int amoney, int maxNumberOfPplants) : maxNumberOfPowerplants(maxNumberOfPplants) {
	name = aname;
	money = amoney;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();
	color = acolor;

	Notify();
}

Player::Player(std::string aname, int acolor, int amoney, int maxNumberOfPplants) : maxNumberOfPowerplants(maxNumberOfPplants) {
	name = aname;
	money = amoney;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();
	switch (acolor) {
	case 0: color = "red"; break;
	case 1: color = "green"; break;
	case 2: color = "yellow"; break;
	case 3: color = "blue"; break;
	case 4: color = "pink"; break;
	case 5: color = "orange"; break;
	}

	Notify();
}

Player::Player() : maxNumberOfPowerplants(3) {
	name = "unknown";
	color = "blue";
	money = 50;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
}

Player::Player(string aname) : name(aname) {}




Player::~Player() {

}

string Player::getColor() {
	return color;
}

void Player::setColor(string c) {
	color = c;

	Notify();
}

void Player::setName(string aname) {
	name = aname;

	Notify();
}

string Player::getName() {
	return name;
}


int Player::getMoney() {
	return money;
}

void Player::setMoney(int a) {
	money = money + a;

	Notify();
}

int Player::getNumberOfHouses() {
	return numberOfHouses;
}

void Player::setNumberOfHouses() {
	numberOfHouses++;

	Notify();
}

int Player::getNumberOfPowerPlants() {
	return numberOfPowerPlant;
}

void Player::setNumberOfPowerPlants() {
	numberOfPowerPlant++;

	Notify();
}


bool Player::SwapResource(int index1, int index2, int type, int amount) {
	
	if (_powerplants[index2].RemoveResource(type, amount)) {
		_powerplants[index1].StoreResource(type, amount);
		return true;
	}
	else {
		return false;
	}
}

bool Player::AddResources(int index, int type, int amount, int totalCost) {
	
	if (totalCost < 0 || index > 2 || index < 0) { //verifies that the index is within the acceptable range for the vector and that the player has enough money to pay for the resources
		return false;
	}
	else {
		if (_powerplants[index].StoreResource(type, amount)) { //tries to stores the resources in the powerplant
			money -= totalCost;
			return true;
		}
	}

	Notify();
	return true;
}

bool Player::AddHouse(House house, int cost) {
	//If the player can't afford it, or has a full array of houses
	if (cost > money || numberOfHouses >= 24)
		return false;
	else {
		money = money - cost;
		_houses[numberOfHouses] = house;//adds a new house
		setNumberOfHouses();//increments the number of houses
		return true;
	}

	Notify();

}

void Player::AddHouse(House house) { // used only for loading from file and adding a house to a player
	_houses[numberOfHouses] = house;
	setNumberOfHouses();

	Notify();
}

bool Player::AddPowerplant(PowerPlantMarket::PowerPlant powerplant, int cost) {
	//If the player can't afford it
	if (cost > money)
		return false;
	else {//If the player already has maxNumberOfPowerplants powerplants, let the player choose which one he wants to replace
		if (numberOfPowerPlant == maxNumberOfPowerplants) {
			int ppToReplace;
			for (int j = 0; j < 3; j++) {
				DisplayPowerplant(_powerplants[j]);
			}
			do {
				cout << "You already have the maximum number of powerplant. Which power plant do you wish to remove? \nEnter the index of the powerplant to remove(1-3): ";
				cin >> ppToReplace;
			} while (ppToReplace > 3 || ppToReplace < 1);
			for (int i = 0; i < 4; i++) {
				int totalToTransfer = _powerplants[ppToReplace - 1].GetAmountStored(i);
				if (_powerplants[ppToReplace - 1].GetAmountStored(i) > 0) {
					string res = "";
					switch (i) {
					case 0: res = " coal "; break;
					case 1: res = " oil "; break;
					case 2: res = " garbage "; break;
					case 3: res = " uranium "; break;
					}
					cout << "\n\nSummary of PowerPlants:\n\n";
					for (int j = 0; j < 3; j++) {
						DisplayPowerplant(_powerplants[j]);
					}
					int ppToTransferRes;
					int amountToTransfer;
					do {
						cout << "PowerPlant #" + to_string(_powerplants[ppToReplace - 1].GetValue()) + " has " + to_string(_powerplants[ppToReplace - 1].GetAmountStored(i)) + res;
						cout << "Choose the powerplant where to transfer you resources or 0 if you don't want to transfer(resources will be lost): ";
						cin >> ppToTransferRes;
						do {
							cout << "How much " + res + " do you want to transfer to powerplant #" + to_string(_powerplants[ppToTransferRes - 1].GetValue()) + ": ";
							cin >> amountToTransfer;
						} while (amountToTransfer > totalToTransfer || amountToTransfer < 0);
						bool result = SwapResource(ppToTransferRes - 1, ppToReplace - 1, i, amountToTransfer);
						if (!result)
							cout << "Transer didnt't work. Try again. Maybe";
						totalToTransfer -= amountToTransfer;
					} while (totalToTransfer > 0 || amountToTransfer < 1);
				}
			}
			_powerplants[ppToReplace - 1] = powerplant;
			money = money - cost;
		}
		else {//adds it to the array
			_powerplants[numberOfPowerPlant] = powerplant;
			setNumberOfPowerPlants();
			money = money - cost;
		}
		return true;
	}

	Notify();

}

House* Player::GetHouse(int index) {
	return &(_houses[index]);
}

PowerPlantMarket::PowerPlant* Player::GetPowerplant(int index) {
	return &(_powerplants[index]);
}


void Player::displayPlayerInformation() {
	cout << "\n-------------------------------------";
	cout << "\nPlayer Name: " << name
		<< "\n\tColor: " << color
		<< "\n\tNumber Of Cities: " << numberOfHouses
		<< "\n\tNumber Of PowerPlant: " << numberOfPowerPlant
		<< "\n\tElectro: " << money << endl;

	cout << "\nOwns houses in the following cities:" << endl;
	for (int i = 0; i < numberOfHouses; i++) {//uses a loop to iterate through all the houses
		cout << _houses[i].location << endl;
	}
	//displays the specific information about the player's powerplants
	cout << "Summary of Powerplants:" << endl;

	for (int i = 0; i < numberOfPowerPlant; i++) {//uses a loop to iterate through all the powerplants
		DisplayPowerplant(_powerplants[i]);//calls the display method of the powerplant
	}
	cout << "-------------------------------------";
}


void Player::displayPlayerInformation(PowerPlantMarket_Observer* market_ob) {
	cout << "\n-------------------------------------";
	cout << "\nPlayer Name: " << name
		<< "\n\tColor: " << color
		<< "\n\tNumber Of Cities: " << numberOfHouses
		<< "\n\tNumber Of PowerPlant: " << numberOfPowerPlant
		<< "\n\tElectro: " << money << endl;

	cout << "\nOwns houses in the following cities:" << endl;
	for (int i = 0; i < numberOfHouses; i++) {//uses a loop to iterate through all the houses
		cout << _houses[i].location << endl;
	}
	//displays the specific information about the player's powerplants
	cout << "Summary of Powerplants:" << endl;

	for (int i = 0; i < numberOfPowerPlant; i++) {//uses a loop to iterate through all the powerplants
		market_ob->DisplayPowerplant(_powerplants[i]);//calls the display method of the powerplant
	}
	cout << "-------------------------------------";
}

string Player::getPayment() {
	string payment = summaryCard->payment(this->getName(), this->getNumberOfHouses());
	return payment;
}

int Player::getMaxValuePowerplant() {
	int maxValue = _powerplants[0].GetValue();
	for (int i = 1; i < 3; i++) {//If the value of a powerplant exceeds the previous maximum, set it to maximum
		if (maxValue < _powerplants[i].GetValue())
			maxValue = _powerplants[i].GetValue();
	}
	return maxValue;
}

void Player::DisplayPowerplant(PowerPlantMarket::PowerPlant powerplant) {
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
		<< "\n\t Max Cities Powered: " << powerplant.GetMaxCitiesPowered()
		<< "\n\t Resources needed: " << type
		<< "\n\t Resource cost: " << powerplant.GetResCost()
		<< "\n\t Number of Resources Stored: " << powerplant.GetAmountStored() << endl;
}


