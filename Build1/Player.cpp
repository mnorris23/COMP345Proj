#include "Player.h"

using namespace std;


Player::Player(string aname, int acolor) {
	name = aname;
	money = 50;
	numberOfPowerPlant = 0;
	numberOfCities = 0;
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

Player::Player(string aname) : name(aname), color("orange"), money(50), numberOfPowerPlant(0), numberOfCities(0) {

}

Player::Player() {
	name = "unknown";
	color = "blue";
	money = 50;
	numberOfPowerPlant = 0;
	numberOfCities = 0;
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

bool Player::RemoveHouse(int index) {
	if (index > _houses.size() || index < 0)
		return false;//verifies that the index is within the acceptable range for the vector
	_houses.erase(_houses.begin() + index); //removes the house at the specified index
	return true;
}

bool Player::SwapResource(int index1, int index2, int amount){
	std::vector<Resource> resources;
	for (int i = 0; i < amount; i++)
		resources.push_back(_powerplants[index2].RemoveResource(i));
	if (_powerplants[index1].StoreResource(resources))
		return true;
	else
		_powerplants[index2].StoreResource(resources);

	return false;
}

bool Player::AddResources(int index, std::vector<Resource> res) {
	int cost = 0;
	for (int i = 0; i < res.size(); i++)
		cost += res[i].cost;

	if (cost > _elektro || index > _powerplants.size() || index < 0)
		return false;//verifies that the index is within the acceptable range for the vector and that the player has enough elektro to pay for the resources
	return _powerplants[index].StoreResource(res); //tries to stores the resources in the powerplant

}

bool Player::AddHouse(House house, int cost){
	if (cost > money || numberOfHouses >= 24)
		return false;
	else{
		_houses[numberOfHouses] = house;
		setNumberOfHouses();
		return true;
	}

}

bool Player::AddPowerplant(Powerplant powerplant, int cost){
	if (cost > money )
		return false;
	else{
		if (numberOfPowerPlants == 3){
			_powerplants[numberOfPowerPlants - 1] = powerplant;
		}
		else{
			_powerplants[numberOfPowerPlants] = powerplant;
			setNumberOfPowerPlants();
		}
		
		return true;
	}

}

void Player::DisplayPlayer() {
	////Displays the specific information about the player
	cout << "Player " << _color <<
		"\nElektros: " << _elektro <<
		"\n\nCurrent number of houses: " << numberOfHouses <<
		"\nCurrent number of powerplants: " << numberOfPowerPlants << endl;
	//displays the specific information about the player's houses
	cout << "Locations in which player has houses:" << endl;

	for (int i = 0; i < _houses.size(); i++) {//uses a loop to iterate through all the houses
		cout << _houses[i].location << endl;
	}
	//displays the specific information about the player's powerplants
	cout << "Summary of Powerplants:" << endl;

	for (int i = 0; i < _powerplants.size(); i++) {//uses a loop to iterate through all the powerplants
		_powerplants[i].DisplayPowerplant();//calls the display method of the powerplant
	}
}

string Player::getPlayerInformation() {
	
	ostringstream info;
	info << "Player Name: " << name <<  "\nNumber Of Cities: " << numberOfCities << "\nNumber Of PowerPlant: " << numberOfCities << "\nElectro: " << money << endl;
	string str = info.str();
	return str;
}

string Player::getPayment() {
	string payment = summaryCard->payment(this->getName(), this->getNumberOfCities());
	return payment;
}

