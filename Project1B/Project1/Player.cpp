#include <iostream>;
#include "House.h";
#include "PowerPlant.h";
#include <vector>;
#include <string>;
#include "Player.h";

using namespace std;

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

bool Player::RemovePowerplant(int index) {
	if (index > _powerplants.size() || index < 0)
		return false;//verifies that the index is within the acceptable range for the vector
	_powerplants.erase(_powerplants.begin() + index);//removes the powerplant at the specified index
	return true;
}

bool Player::AddResources(int index, std::vector<Resource> res) {
	int cost = 0;
	for (int i = 0; i < res.size(); i++)
		cost += res[i].cost;

	if (cost > _elektro || index > _powerplants.size() || index < 0)
		return false;//verifies that the index is within the acceptable range for the vector and that the player has enough elektro to pay for the resources
	return _powerplants[index].StoreResource(res); //tries to stores the resources in the powerplant

}

void Player::DisplayPlayer() {
	////Displays the specific information about the player
	cout << "Player " << _color <<
		"\nElektros: " << _elektro <<
		"\n\nCurrent number of houses: " << _houses.size() <<
		"\nCurrent number of powerplants: " << _powerplants.size() << endl;
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