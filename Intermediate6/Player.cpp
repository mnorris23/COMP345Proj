#include "Player.h"
#include <iostream>

using namespace std;


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
}

Player::Player(std::string aname, std::string acolor, int amoney, int maxNumberOfPplants) : maxNumberOfPowerplants(maxNumberOfPplants) {
	name = aname;
	money = amoney;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
	summaryCard = new SummaryCard();
	color = acolor;
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
}

Player::Player() : maxNumberOfPowerplants(3) {
	name = "unknown";
	color = "blue";
	money = 50;
	numberOfPowerPlant = 0;
	numberOfHouses = 0;
}




Player::~Player() {

}

string Player::getColor() {
	return color;
}

void Player::setColor(string c) {
	color = c;
}

void Player::setName(string aname) {
	name = aname;
}

string Player::getName() {
	return name;
}


int Player::getMoney() {
	return money;
}

void Player::setMoney(int a) {
	money = money + a;
}

int Player::getNumberOfHouses() {
	return numberOfHouses;
}

void Player::setNumberOfHouses() {
	numberOfHouses++;
}

int Player::getNumberOfPowerPlants() {
	return numberOfPowerPlant;
}

void Player::setNumberOfPowerPlants() {
	numberOfPowerPlant++;
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

}

void Player::AddHouse(House house) { // used only for loading from file and adding a house to a player
	_houses[numberOfHouses] = house;
	setNumberOfHouses();
}

bool Player::AddPowerplant(PowerPlantMarket::PowerPlant powerplant, int cost) {
	//If the player can't afford it
	if (cost > money)
		return false;
	else {//If the player already has maxNumberOfPowerplants powerplants, replaces the last one 
		if (numberOfPowerPlant == maxNumberOfPowerplants) {
			_powerplants[numberOfPowerPlant - 1] = powerplant;
			money = money - cost;
		}
		else {//adds it to the array
			_powerplants[numberOfPowerPlant] = powerplant;
			setNumberOfPowerPlants();
			money = money - cost;
		}
		return true;
	}

}

House* Player::GetHouse(int index) {
	return &(_houses[index]);
}

PowerPlantMarket::PowerPlant* Player::GetPowerplant(int index) {
	return &(_powerplants[index]);
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
