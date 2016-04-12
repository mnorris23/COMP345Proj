#include <iostream>
#include <string>
#include "ResourceMarket.h"

using namespace std;

ResourceMarket::ResourceMarket() {
	//establishes a market with no resources
	establishResourceReserves(0, 0, 0, 0);
}

ResourceMarket::ResourceMarket(int coal, int oil, int garbage, int uranium) {
	//establishes a market with specified amounts of each resources
	establishResourceReserves(coal, oil, garbage, uranium);
}

//A private method to initialize the market and the resources in reserve
void ResourceMarket::establishResourceReserves(int coalAmount, int oilAmount, int garbageAmount, int uraniumAmount) {
	//Initializes the arrays needed in this method
	initializeArrays();

	//For all resources, the loop runs until the specified amount of the resource is pushed into the market
	//A new resource struct is created, its type is initialized to the value for that resource and the cost is calculated according to its position in the market.

	//coal
	_resourcesInMarket[0] = coalAmount;
	
	//oil
	_resourcesInMarket[1] = oilAmount;
	//garbage
	_resourcesInMarket[2] = garbageAmount;
	//uranium
	_resourcesInMarket[3] = uraniumAmount;

	for (int i = 0; i < 4; i++) {//Iterates through the array
								 //The amount of resources of a type in reserve at the start of the game is all resources of that type except those in the market
		_resourcesInReserve[i] = _maxAmountOfResources[i] - _resourcesInMarket[i];

	}

}

void ResourceMarket::initializeArrays() {
	//The maximum amount of a type of resource
	_maxAmountOfResources[0] = 24;
	_maxAmountOfResources[1] = 24;
	_maxAmountOfResources[2] = 24;
	_maxAmountOfResources[3] = 12;

	//coal
	//first stage
	_addedResources[0][0][0] = 3;
	_addedResources[0][0][1] = 4;
	_addedResources[0][0][2] = 5;
	_addedResources[0][0][3] = 5;
	_addedResources[0][0][4] = 7;
	//second stage
	_addedResources[0][1][0] = 4;
	_addedResources[0][1][1] = 5;
	_addedResources[0][1][2] = 6;
	_addedResources[0][1][3] = 7;
	_addedResources[0][1][4] = 9;
	//third stage
	_addedResources[0][2][0] = 3;
	_addedResources[0][2][1] = 3;
	_addedResources[0][2][2] = 4;
	_addedResources[0][2][3] = 5;
	_addedResources[0][2][4] = 6;

	//oil
	//first stage
	_addedResources[1][0][0] = 2;
	_addedResources[1][0][1] = 2;
	_addedResources[1][0][2] = 3;
	_addedResources[1][0][3] = 4;
	_addedResources[1][0][4] = 5;
	//second stage
	_addedResources[1][1][0] = 2;
	_addedResources[1][1][1] = 3;
	_addedResources[1][1][2] = 4;
	_addedResources[1][1][3] = 5;
	_addedResources[1][1][4] = 6;
	//third stage
	_addedResources[1][2][0] = 4;
	_addedResources[1][2][1] = 4;
	_addedResources[1][2][2] = 5;
	_addedResources[1][2][3] = 6;
	_addedResources[1][2][4] = 7;

	//garbage
	//first stage
	_addedResources[2][0][0] = 1;
	_addedResources[2][0][1] = 1;
	_addedResources[2][0][2] = 2;
	_addedResources[2][0][3] = 3;
	_addedResources[2][0][4] = 3;
	//second stage
	_addedResources[2][1][0] = 2;
	_addedResources[2][1][1] = 2;
	_addedResources[2][1][2] = 3;
	_addedResources[2][1][3] = 3;
	_addedResources[2][1][4] = 5;
	//third stage
	_addedResources[2][2][0] = 3;
	_addedResources[2][2][1] = 3;
	_addedResources[2][2][2] = 4;
	_addedResources[2][2][3] = 5;
	_addedResources[2][2][4] = 6;

	//uranium
	//first stage
	_addedResources[3][0][0] = 1;
	_addedResources[3][0][1] = 1;
	_addedResources[3][0][2] = 1;
	_addedResources[3][0][3] = 2;
	_addedResources[3][0][4] = 2;
	//second stage
	_addedResources[3][1][0] = 1;
	_addedResources[3][1][1] = 1;
	_addedResources[3][1][2] = 2;
	_addedResources[3][1][3] = 3;
	_addedResources[3][1][4] = 3;
	//third stage
	_addedResources[3][2][0] = 1;
	_addedResources[3][2][1] = 1;
	_addedResources[3][2][2] = 2;
	_addedResources[3][2][3] = 2;
	_addedResources[3][2][4] = 3;

}

int ResourceMarket::GetResourceInMarket(int index) {
	//makes sure the index is within range
	if (index >= 0 || index <= 3)
		return _resourcesInMarket[index];
	else
		return -1;
}

int ResourceMarket::GetResourcesInReserve(int index) {
	//makes sure the index is within range
	if (index >= 0 || index <= 3)
		return _resourcesInReserve[index];
	else
		return -1;
}

int ResourceMarket::GetTotalResources(int index) {
	//makes sure the index is within range
	if (index >= 0 || index <= 3)
		return _maxAmountOfResources[index];
	else return -1;
}

void ResourceMarket::ReplenishMarket(int numPlayers, int step, GameLog_Subject* gameLog) {
	//an array for the added resources
	int addedResources[4];
	//The specific amount of resources replenished each turn are listed in a three dimensional array, but as the array starts with the index of 0,
	//the value of step (which starts at 1), and of the number of players (which starts at 2) are decremented by 1 and to respectively to get the right value.
	addedResources[0] = _addedResources[0][step - 1][numPlayers - 2];
	addedResources[1] = _addedResources[1][step - 1][numPlayers - 2];
	addedResources[2] = _addedResources[2][step - 1][numPlayers - 2];
	addedResources[3] = _addedResources[3][step - 1][numPlayers - 2];

	//If there is enough of a resource in the reserve to replenish the specified amount to the market, 
	//that amount is substracted from the reserve and added to the market
	//If not, the reserve goes to 0 and the amount in the reserve is added to the market
	for (int i = 0; i < 4; i++) {//iterates through all the resources
		int resourcesToAdd;
		string str = "";
		string res = "";
		switch (i) {
		case 0: res = " coal "; break;
		case 1: res = " oil "; break;
		case 2: res = " garbage "; break;
		case 3: res = " uranium "; break;
		}
		if (_resourcesInReserve[i] >= addedResources[i]) {
			resourcesToAdd = addedResources[i];
			str = "\n" + to_string(resourcesToAdd) + res + "was added to the Resource Market.\n";
			gameLog->updateLog(str, 5, false, "all");
		}
		else {
			resourcesToAdd = _resourcesInReserve[i];
			str = "\n" + to_string(resourcesToAdd) + res + "was added to the Resource Market.\n";
			gameLog->updateLog(str, 5, false, "all");
		}
		//The cost is recalculated for each resource
		_resourcesInMarket[i] += resourcesToAdd;
		_resourcesInReserve[i] -= resourcesToAdd;

	}
}

int ResourceMarket::BuyResource(int type, int amount, int currentFunds) {
	
	int total = amount;
	int totalCostToBuy = 0;
	//determine the total cost to buy the amount of resources 
	while (total > 0) {
		totalCostToBuy += GetResourceCost(type, _resourcesInMarket[type] - amount + 1);
		total--;
	}

	if (currentFunds < totalCostToBuy) {
		return -1;
	}
	else {
		_resourcesInMarket[type] -= amount;
		return totalCostToBuy;
	}
}

int ResourceMarket::GetResourceCost(int index, int amount) {
	//Returns the cost of 1 unit of the resource if the stack has a specified amount of that resource
	if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
		return -1;

	if (index != 3)//if the resource isn't uranium
		return (_maxAmountOfResources[index] - (amount) + 3) / 3;
	//uranium is a special case
	if (amount == 1)
		return 16;
	if (amount == 2)
		return 14;
	if (amount == 3)
		return 12;
	if (amount == 4)
		return 10;
	return _maxAmountOfResources[index] - amount + 1;
}

bool ResourceMarket::RestoreResources(int index, int resources) {
	if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
		return false;
	//verifies that the current resources in storage and in the market with the added amount does not exceed the total amount of the resource present in the game
	if (resources < 0 || resources + _resourcesInMarket[index] + _resourcesInReserve[index] >_maxAmountOfResources[index])
		return false;
	//Verifies that all resources are of the right type, and if so, returns them to the storage stack

	//adds the resources to the storage
	_resourcesInReserve[index] += resources;	
	return true;
}

void ResourceMarket::pushResources(int amount, int type) {

	_resourcesInMarket[type] += amount;

}
void ResourceMarket::DisplayMarket() {
	//A array of the name of each resource
	std::string resourceNames[4] = { "Coal", "Oil", "Garbage", "Uranium" };

	cout << "\n-------------------------------------";
	cout << "\n\tResource Market" << endl;

	for (int i = 0; i < 4; i++) {//iterates through all the resources in the market
		cout << "\nCurrent amount of " << resourceNames[i] << " in the market: " << _resourcesInMarket[i] //Prints the amount of each resource in market
			<< "\nCurrent " << resourceNames[i] << " cost: " << GetResourceCost(i, _resourcesInMarket[i]) //Prints the cost of each resource
			<< "\nCurrent " << resourceNames[i] << " reserves: " << _resourcesInReserve[i]//Prints the amount of each resource in reserve
			<< "\nTotal amount of " << resourceNames[i] << " in game: " << _maxAmountOfResources[i] << endl; //Prints the amount of each resource in game
	}
	cout << "-------------------------------------";
}