#include <iostream>
#include <string>
#include "ResourceMarket.h"

using namespace std;

ResourceMarket::ResourceMarket(){
	//establishes a market with no resources
	establishResourceReserves(0, 0, 0, 0);
}

ResourceMarket::ResourceMarket(int coal, int oil, int garbage, int uranium){
	//establishes a market with specified amounts of each resources
	establishResourceReserves(coal, oil, garbage, uranium);
}

//A private method to initialize the market and the resources in reserve
void ResourceMarket::establishResourceReserves(int coalAmount, int oilAmount, int garbageAmount, int uraniumAmount){
	//Initializes the arrays needed in this method
	initializeArrays();
	
	//For all resources, the loop runs until the specified amount of the resource is pushed into the market
	//A new resource struct is created, its type is initialized to the value for that resource and the cost is calculated according to its position in the market.
	
	//coal
	for (int i = 0; i < coalAmount; i++){
		Resource coal;
		coal.type = 0;
		coal.cost = (_maxAmountOfResources[0] - _resourcesInMarket[0].size()) / 3 + 1;
		_resourcesInMarket[0].push(coal);
	}
	//oil
	for (int i = 0; i < oilAmount; i++){
		Resource oil;
		oil.type = 1;
		oil.cost = (_maxAmountOfResources[1] - _resourcesInMarket[1].size()) / 3 + 1;
		_resourcesInMarket[1].push(oil);
	}
	//garbage
	for (int i = 0; i < garbageAmount; i++){
		Resource garbage;
		garbage.type = 2;
		garbage.cost = (_maxAmountOfResources[2] - _resourcesInMarket[2].size()) / 3 + 1;
		_resourcesInMarket[2].push(garbage);
	}
	//uranium
	for (int i = 0; i < uraniumAmount; i++){
		Resource uranium;
		uranium.type = 3;
		//uranium is a special case, as it's price doesn't fit the same pattern as the other resources. So a special switch statement is used to determine the cost.
		switch (_resourcesInMarket[3].size()) {
		case 1: uranium.cost = 16; break;
		case 2: uranium.cost = 14; break;
		case 3: uranium.cost = 12; break;
		case 4: uranium.cost = 10; break;
		default: uranium.cost = _maxAmountOfResources[3] - _resourcesInMarket[3].size() + 1;
		}
		_resourcesInMarket[3].push(uranium);
	}



	for (int i = 0; i < 4; i++){//Iterates through the array of stacks
		//The amount of resources of a type in reserve at the start of the game is all resources of that type except those in the market
		for (int j = 0; j < _maxAmountOfResources[i] - _resourcesInMarket[i].size(); j++){
			//The new resource struct of that type is initialized and it's cost is 0 as it is not needed for now
			Resource res;
			res.cost = 0;
			res.type = i;
			_resourcesInReserve[i].push(res);
		}

	}
	
}

void ResourceMarket::initializeArrays(){
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
		return _resourcesInMarket[index].size();
	else 
		return -1; 
}

int ResourceMarket::GetResourcesInReserve(int index) {
	//makes sure the index is within range
	if (index >= 0 || index <= 3)
		return _resourcesInReserve[index].size();
	else 
		return -1;
}

int ResourceMarket::GetTotalResources(int index) {
	//makes sure the index is within range
	if (index >= 0 || index <= 3)
		return _maxAmountOfResources[index]; 
	else return -1; 
}

void ResourceMarket::ReplenishMarket(int numPlayers, int step) {
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
		int iterations;

		if (_resourcesInReserve[i].size() >= addedResources[i]) {
			iterations = addedResources[i];
		}
		else {
			iterations = _resourcesInReserve[i].size();
		}
		//The cost is recalculated for each resource
		for (int j = 0; j < iterations; j++){
			Resource res = _resourcesInReserve[i].top();
			_resourcesInReserve[i].pop();
			if (i < 3)
				res.cost = (_maxAmountOfResources[i] - _resourcesInMarket[i].size()) / 3 + 1;
			else{
				switch (_resourcesInMarket[i].size()) {
				case 1: res.cost = 16; break;
				case 2: res.cost = 14; break;
				case 3: res.cost = 12; break;
				case 4: res.cost = 10; break;
				default: res.cost = _maxAmountOfResources[i] - _resourcesInMarket[i].size() + 1;
				}

			}
			//The reource is added to the market
			_resourcesInMarket[i].push(res);

		}

	}
}

std::vector<Resource> ResourceMarket::BuyResource(int index, int amount, int currentFunds) {
	//The two resources vectors
	std::vector<Resource> resources, res1;
	//A boolean determining if the player has enough money to buy the resources
	bool canBuy = true;
	//puts the specified amount of resources in a temp vector 
	while (amount > 0){
		resources.push_back(_resourcesInMarket[index].top());
		_resourcesInMarket[index].pop();
		amount--;
	}
	//Calculates the cost of buying all the resources and substracts it from the player's funds.
	for (int i = 0; i < resources.size(); i++){
		currentFunds -= resources[i].cost;
		//If the player doesn't have enough funds
		if (currentFunds < 0){
			canBuy = false;//he cannot buy the resources
			break;
		}
	}
	//If he can buy the resources, sends the array of resources
	if (canBuy == true)
		return resources;
	else{//else pushes the resources back into the stack
		for (int i = 0; i < resources.size(); i++){
			_resourcesInMarket[index].push(resources[i]);
		}//returns an empty vector
		return res1;
	}

}

int ResourceMarket::GetResourceCost(int index, int amount) {
	//Returns the cost of 1 unit of the resource if the stack has a specified amount of that resource
	if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
		return -1;

	if (index != 3)//if the resource isn't uranium
		return (_maxAmountOfResources[index] - amount) / 3 + 1;
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

bool ResourceMarket::RestoreResources(int index, std::vector<Resource> resources) {
	if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
		return false;
	//verifies that the current resources in storage and in the market with the added amount does not exceed the total amount of the resource present in the game
	if (resources.size() < 0 || resources.size() + _resourcesInMarket[index].size() + _resourcesInReserve[index].size() >_maxAmountOfResources[index])
		return false;
	//Verifies that all resources are of the right type, and if so, returns them to the storage stack
	for (int i = 0; i < resources.size(); i++){
		Resource res = resources[i];
		if (res.type != index)
			return false;
		res.cost = 0;
		_resourcesInReserve[index].push(res);
	}
	//adds the resources to the storage
	return true;
}

void ResourceMarket::DisplayMarket() {
	//A array of the name of each resource
	std::string resourceNames[4] = { "Coal", "Oil", "Garbage", "Uranium" };

	for (int i = 0; i < 4; i++) {//iterates through all the resources in the market
		cout << "Current amount of " << resourceNames[i] << " in the market: " << _resourcesInMarket[i].size() //Prints the amount of each resource in market
			<< "\nCurrent " << resourceNames[i] << " cost: " << GetResourceCost(i, _resourcesInMarket[i].size()) //Prints the cost of each resource
			<< "\nCurrent " << resourceNames[i] << " reserves: " << _resourcesInReserve[i].size() //Prints the amount of each resource in reserve
			<< "\nTotal amount of " << resourceNames[i] << " in game: " << _maxAmountOfResources[i] << endl; //Prints the amount of each resource in game
	}
}