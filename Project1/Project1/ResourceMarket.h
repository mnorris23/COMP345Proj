//A class that implements the Resource Market in the game
#pragma once;
#include <iostream>;
#include <string>;

using namespace std;
//A class to regulate the Resource Market in the game
class ResourceMarket
{
private:
	//A three-dimensional array that holds the value by which each resource is incremented after each turn, seperated by resource, stage in the game and number of players.
	int _addedResources[4][3][5] /*= {
			{ { 3, 4, 5, 5, 7 }, { 4, 5, 6, 7, 9 }, { 3, 3, 4, 5, 6 } },
			{ { 2, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 4, 4, 5, 6, 7 } },
			{ { 1, 1, 2, 3, 3 }, { 2, 2, 3, 3, 5 }, { 3, 3, 4, 5, 6 } },
			{ { 1, 1, 1, 2, 2 }, { 1, 1, 2, 3, 3 }, { 1, 1, 2, 2, 3 } }
	}*/;

	//For all arrays, coal is index 0, oil is 1, garbage is 2 and uranium 3
	//The amount of resources available in the market
	int _resourcesInMarket[4];
	//The amount of resources in reserve (not in the market or stored in a powerplant)
	int _resourcesInReserve[4];
	//The maximum amount of a resource that can be found in the game
	int _maxAmountOfResources[4] /*= { 24, 24, 24, 12 }*/;

	//a method that sets the value for the reserve of each resources, only called at the beginning of the game
	void establishResourceReserves(){

		initializeArrays();

		for (int i = 0; i < 4; i++)//Iterates through the array
			_resourcesInReserve[i] = _maxAmountOfResources[i] - _resourcesInMarket[i];
		//The amount of resources in reserve at the start of the game is all resources except those in the market
	}
	void initializeArrays(){

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

		_addedResources[1][0][0] = 2;
		_addedResources[1][0][1] = 2;
		_addedResources[1][0][2] = 3;
		_addedResources[1][0][3] = 4;
		_addedResources[1][0][4] = 5;

		_addedResources[1][1][0] = 2;
		_addedResources[1][1][1] = 3;
		_addedResources[1][1][2] = 4;
		_addedResources[1][1][3] = 5;
		_addedResources[1][1][4] = 6;

		_addedResources[1][2][0] = 4;
		_addedResources[1][2][1] = 4;
		_addedResources[1][2][2] = 5;
		_addedResources[1][2][3] = 6;
		_addedResources[1][2][4] = 7;

		//garbage

		_addedResources[2][0][0] = 1;
		_addedResources[2][0][1] = 1;
		_addedResources[2][0][2] = 2;
		_addedResources[2][0][3] = 3;
		_addedResources[2][0][4] = 3;

		_addedResources[2][1][0] = 2;
		_addedResources[2][1][1] = 2;
		_addedResources[2][1][2] = 3;
		_addedResources[2][1][3] = 3;
		_addedResources[2][1][4] = 5;

		_addedResources[2][2][0] = 3;
		_addedResources[2][2][1] = 3;
		_addedResources[2][2][2] = 4;
		_addedResources[2][2][3] = 5;
		_addedResources[2][2][4] = 6;

		//uranium

		_addedResources[3][0][0] = 1;
		_addedResources[3][0][1] = 1;
		_addedResources[3][0][2] = 1;
		_addedResources[3][0][3] = 2;
		_addedResources[3][0][4] = 2;

		_addedResources[3][1][0] = 1;
		_addedResources[3][1][1] = 1;
		_addedResources[3][1][2] = 2;
		_addedResources[3][1][3] = 3;
		_addedResources[3][1][4] = 3;

		_addedResources[3][2][0] = 1;
		_addedResources[3][2][1] = 1;
		_addedResources[3][2][2] = 2;
		_addedResources[3][2][3] = 2;
		_addedResources[3][2][4] = 3;
		
		/*_addedResources = {
				{ { 3, 4, 5, 5, 7 }, { 4, 5, 6, 7, 9 }, { 3, 3, 4, 5, 6 } },
				{ { 2, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 4, 4, 5, 6, 7 } },
				{ { 1, 1, 2, 3, 3 }, { 2, 2, 3, 3, 5 }, { 3, 3, 4, 5, 6 } },
				{ { 1, 1, 1, 2, 2 }, { 1, 1, 2, 3, 3 }, { 1, 1, 2, 2, 3 } }
		};*/
	}

public:

	//empty constructor, the market starts empty
	ResourceMarket()
	{
		for (int i = 0; i < 4; i++)//Iterates through the array
			_resourcesInMarket[i] = 0;//assigns 0 as a default value
		establishResourceReserves();
	}
	//constructor that initializes the market with a certain amount of resources available
	ResourceMarket(int coal, int oil, int garbage, int uranium) 		
	{
		_resourcesInMarket[0] = coal;
		_resourcesInMarket[1] = oil;
		_resourcesInMarket[2] = garbage;
		_resourcesInMarket[3] = uranium;

		establishResourceReserves();
	}
	//a method to replenish the market with a certain amount of resources each turn. The amount of resources depends on the number of players and the stage of the game.
	void ReplenishMarket(int numPlayers, int step) {
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
			if (_resourcesInReserve[i] >= addedResources[i]) {
				_resourcesInReserve[i] -= addedResources[i];
				_resourcesInMarket[i] += addedResources[i];
			}
			else {
				_resourcesInMarket[i] += _resourcesInReserve[i];
				_resourcesInReserve[i] = 0;
			}
		}
	}

	//A method to buy a certain amount of the resource at the specified index. Returns the cost of buying the specified amount of said resource, or -1 if there isn't enough of the resource
	int BuyResource(int index, int amount) {
		if (index < 0 || index > 3) //verifies that the index is within the acceptable range for the array 
			return -1;
		//variable for the total cost of the resources
		int cost = 0;
		//a variable in case the method terminates in fallure due to an insufficient amount of resources in the market
		int amountRemoved = 0;
		//uranium is a special case 
		if (index == 3) {
			while (amount > 0) {
				if (_resourcesInMarket[index] == 0) { _resourcesInMarket[index] += amountRemoved; return -1; } //makes sure that if amount is bigger than the inital amount of resources in the market, the method stops

				//the price depending on how much uranium is available
				switch (_resourcesInMarket[index]) {
				case 1: cost += 16; break;
				case 2: cost += 14; break;
				case 3: cost += 12; break;
				case 4: cost += 10; break;
				default: cost += _maxAmountOfResources[index] - _resourcesInMarket[index] + 1;
				}
				//remove a unit of uranium
				_resourcesInMarket[index]--;
				amount--;
				amountRemoved++;
			}
		}
		else {
			while (amount > 0) {
				if (_resourcesInMarket[index] == 0) { _resourcesInMarket[index] += amountRemoved; return -1; }//makes sure that if amount is bigger than the inital amount of resources in the market, the method stops

				//the price depending on how much of the resource is available
				cost += (_maxAmountOfResources[index] - _resourcesInMarket[index]) / 3 + 1;
				//remove a unit of the resource
				_resourcesInMarket[index]--;
				amount--;
				amountRemoved++;
			}
		}
		return cost;//return the cost
	}

	//A method to get the cost of 1 unit of the resource at the specified index, depending on the specified amount of units of the resource present in the market,
	//or -1 if the index or amount are in none acceptible ranges 
	int GetResourceCost(int index, int amount) {
		if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
			return -1;

		if (index != 3)//if the reource isn't uranium
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

	//A Getter method for the resources (the amount available in the market)
	int GetResourceInMarket(int index) { if (index >= 0 || index <= 3) return _resourcesInMarket[index]; else return -1; }

	//A Getter method for the resources in reserve
	int GetResourcesInReserve(int index) { if (index >= 0 || index <= 3) return _resourcesInReserve[index]; else return -1; }

	//Getter methods for the maximum amount of a given resource
	int GetTotalResources(int index) { if (index >= 0 || index <= 3) return _maxAmountOfResources[index]; else return -1; }

	//A method to recover resources that have been bought, once they have been consumed. Said resources are stored until they can be used to replenish the market
	bool RestoreResources(int index, int amount) {
		if (index < 0 || index > 3)//verifies that the index is within the acceptable range for the array 
			return false;
		//verifies that the current resources in storage and in the market with the added amount does not exceed the total amount of the resource present in the game
		if (amount < 0 || amount + _resourcesInMarket[index] + _resourcesInReserve[index] >_maxAmountOfResources[index])
			return false;
		_resourcesInReserve[index] += amount; //adds the resources to the storage
		return true;
	}

	//A method to display all the information about the Resource Market
	void DisplayMarket() {
		//A array of the name of each resource
		std::string resourceNames[4] = { "Coal", "Oil", "Garbage", "Uranium" };

		for (int i = 0; i < 4; i++) {//iterates through all the resources in the market
			cout << "Current amount of " << resourceNames[i] << "in the market: " << _resourcesInMarket[i] //Prints the amount of each resource in market
				<< "\nCurrent " << resourceNames[i] << " cost: " << GetResourceCost(i, _resourcesInMarket[i]) //Prints the cost of each resource
				<< "\nCurrent " << resourceNames[i] << " reserves: " << _resourcesInReserve[i] //Prints the amount of each resource in reserve
				<< "\nTotal amount of " << resourceNames[i] << " in game: " << _maxAmountOfResources[i] << endl; //Prints the amount of each resource in game
		}
	}

};