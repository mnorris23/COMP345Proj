#include "powergrid.h"

Player::Player() {
	color = 'b';
	money = 50;
	numberOfPowerPlant = 0;
	numberOfCities = 0;
}

Player::Player(char c) {
	color = 'c';
	money = 50;
	numberOfPowerPlant = 0;
	numberOfCities = 0;
}

char Player::getColor() {
	return color;
}

void Player::setColor(char c) {
	color = c;
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
