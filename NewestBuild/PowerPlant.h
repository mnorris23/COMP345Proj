//A class that implements the powerplant cards in the game
#pragma once;

using namespace std;
#include <vector>;
#include "Resource.h";

//A class for the powerplant cards in the game
class PowerPlant
{
private:
	//initial value
	int _value;
	//the maximum amount of cities it can power
	int _maxCitiesPowered;
	//the amount of resources it costs to run it
	int _resCost;
	//the current amount of cities powered by the powerplant
	int _citiesPowered;
	//the number of resources stored on the card.
	std::vector<Resource> _resStored;
	//the type(s) of resource(s) used by the powerplant. 1 is coal, 2 is oil, 3 is garbage, 4 is uranium and 5 is coal AND oil. Anything else means the powerplant doesnt use resources.
	int _resType;

	void initValues(){
		_citiesPowered = 0;
	}

public:
	//empty constructor
	PowerPlant() : _value(0), _maxCitiesPowered(0), _resCost(0), _resType(0) { initValues(); }
	//a constructor to build the card
	PowerPlant(int value, int maxCitiesPowered, int resCost, int resType) :
		_value(value), _maxCitiesPowered(maxCitiesPowered), _resCost(resCost), _resType(resType){
		initValues();
	}

	//returns the value of the powerplant
	int GetValue(){ return _value; }
	//returns the maximum amount of cities powered
	int GetMaxCitiesPowered(){ return _maxCitiesPowered; }
	//returns the resource cost of the powerplant
	int GetResCost(){ return _resCost; }
	//returns the type of resource used by the powerplant
	int GetResType(){ return _resType; }
	int GetAmountStored(){ return _resStored.size(); }
	Resource* GetResStoredAt(int index){ return &_resStored[index]; }



	//returns the available space for resources
	//The total available space is the amount in resource cost *2 minus the resources already stored
	int GetStorageSpace() { return _resCost * 2 - _resStored.size(); }



	//adds a number of cities to be powered by the powerplant 
	bool AddCities(int cities);

	//removes a number of cities being powered
	bool RemoveCities(int cities);

	//Stores an amount of resources of a certain type on the card
	bool StoreResource(std::vector<Resource> resources);

	Resource RemoveResource(int index);

	//Consumes the amount of resources needed (if they have been previously stored on the card
	std::vector<Resource> ConsumeResources();

	std::vector<Resource> ConsumeResources(int type);

	//Displays the powerplant card.
	void DisplayPowerplant();

};