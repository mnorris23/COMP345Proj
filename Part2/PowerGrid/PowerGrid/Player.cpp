#include "powergrid.h"
#include <vector>
#include <sstream>

using namespace std;


Player::Player(string aname, int acolor) {
	name = aname;
	money = 50;
	numberOfPowerPlant = 0;
	numberOfCities = 0;
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

City* Player::getCity() {
	return cities[0];
}

void Player::setCity(City* e) {
	cities[numberOfCities] = e;
}

int Player::getMoney() {
	return money;
}

void Player::setMoney(int a) {
	money = money + a;
}

PowerPlant* Player::getPowerPlants() {
	return power_plant[0];
}

void Player::setPowerPlant(PowerPlant* plant) {
	power_plant[numberOfPowerPlant] = plant;
}

int Player::getNumberOfCities() {
	return numberOfCities;
}

void Player::setNumberOfCities() {
	numberOfCities++;
}

int Player::getNumberOfPowerPlant() {
	return numberOfPowerPlant;
}

void Player::setNumberOfPowerPlant() {
	numberOfPowerPlant++;
}

string Player::getPlayerInformation() {
	
	ostringstream info;
	info << "Player Name: " << name <<  "\nNumber Of Cities: " << numberOfCities << "\nNumber Of PowerPlant: " << numberOfCities << "\nElectro: " << money << endl;
	string str = info.str();
	return str;
}

