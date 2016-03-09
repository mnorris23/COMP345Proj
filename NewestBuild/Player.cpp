#include "Player.h"

using namespace std;


Player::Player(string aname, int acolor) {
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

Player::Player(string aname) : name(aname), color("orange"), money(50), numberOfPowerPlant(0), numberOfHouses(0) {

}

Player::Player(std::string aname, int acolor, int amoney) {
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

Player::Player() {
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


bool Player::SwapResource(int index1, int index2, int amount){
	std::vector<Resource> resources;
	//removes the specified amount of resources from the first powerplant
	for (int i = 0; i < amount; i++)
		resources.push_back(_powerplants[index2].RemoveResource(i));
	//tries to store them in the second one
	if (_powerplants[index1].StoreResource(resources))
		return true;
	else
		_powerplants[index2].StoreResource(resources);
	//if it fails, pushes them back in the first one
	return false;
}

bool Player::AddResources(int index, std::vector<Resource> res) {
	int cost = 0;
	//calculates the total cost of the resources
	for (int i = 0; i < res.size(); i++)
		cost += res[i].cost;

	if (cost > money || index > 2 || index < 0)
		return false;//verifies that the index is within the acceptable range for the vector and that the player has enough money to pay for the resources
	return _powerplants[index].StoreResource(res); //tries to stores the resources in the powerplant

}

bool Player::AddHouse(House house, int cost){
	//If the player can't afford it, or has a full array of houses
	if (cost > money || numberOfHouses >= 24)
		return false;
	else{
		_houses[numberOfHouses] = house;//adds a new house
		setNumberOfHouses();//increments the number of houses
		return true;
	}

}

void Player::AddHouse(House house) { // used only for loading from file and adding a house to a player
	_houses[numberOfHouses] = house;
	setNumberOfHouses();
}

bool Player::AddPowerplant(PowerPlant powerplant, int cost){
	//If the player can't afford it
	if (cost > money)
		return false;
	else{//If the player already has 3 powerplants, replaces the last one 
		if (numberOfPowerPlant == 3){
			_powerplants[numberOfPowerPlant - 1] = powerplant;
		}
		else{//adds it to the array
			_powerplants[numberOfPowerPlant] = powerplant;
			setNumberOfPowerPlants();
		}

		return true;
	}

}

House* Player::GetHouse(int index){ 
	return &(_houses[index]); 
}

PowerPlant* Player::GetPowerplant(int index){ 
	return &(_powerplants[index]); 
}

string Player::getPlayerInformation() {
	ostringstream info;
	info << "Player Name: " << name << "\nNumber Of Cities: " << numberOfHouses << "\nNumber Of PowerPlant: " << numberOfPowerPlant << "\nElectro: " << money << endl;
	string str = info.str();
	return str;
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
