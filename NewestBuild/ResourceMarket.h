//A class that implements the Resource Market in the game
#pragma once
#include "Resource.h"
#include <stack>
#include <vector>

using namespace std;
//A class to regulate the Resource Market in the game
class ResourceMarket
{
private:
	//A three-dimensional array that holds the value by which each resource is incremented after each turn, seperated by resource, stage in the game and number of players.
	int _addedResources[4][3][5];

	//For all arrays, coal is index 0, oil is 1, garbage is 2 and uranium 3
	//The amount of resources available in the market
	std::stack<Resource> _resourcesInMarket[4];
	//The amount of resources in reserve (not in the market or stored in a powerplant)
	std::stack<Resource> _resourcesInReserve[4];
	//The maximum amount of a resource that can be found in the game
	int _maxAmountOfResources[4];

	//a method that sets the value for the reserve of each resources, only called at the beginning of the game
	void establishResourceReserves(int coalAmount, int oilAmount, int garbageAmount, int uraniumAmount);
	//A private method to initialize the arrays used by the class
	void initializeArrays();

public:

	//empty constructor, the market starts empty
	ResourceMarket();
	//constructor that initializes the market with a certain amount of resources available
	ResourceMarket(int coal, int oil, int garbage, int uranium);
	
	//a method to replenish the market with a certain amount of resources each turn. The amount of resources depends on the number of players and the stage of the game.
	void ReplenishMarket(int numPlayers, int step);

	//A method to buy a certain amount of the resource at the specified index. Returns the cost of buying the specified amount of said resource, or -1 if there isn't enough of the resource
	std::vector<Resource> BuyResource(int index, int amount, int currentFunds);


	//A method to get the cost of 1 unit of the resource at the specified index, depending on the specified amount of units of the resource present in the market,
	//or -1 if the index or amount are in none acceptible ranges 
	int GetResourceCost(int index, int amount);

	//A Getter method for the resources (the amount available in the market)
	int GetResourceInMarket(int index);

	//A Getter method for the resources in reserve
	int GetResourcesInReserve(int index);

	//Getter methods for the maximum amount of a given resource
	int GetTotalResources(int index);

	//A method to recover resources that have been bought, once they have been consumed. Said resources are stored until they can be used to replenish the market
	bool RestoreResources(int index, std::vector<Resource> resources);

	//A method to display all the information about the Resource Market
	void DisplayMarket();

};