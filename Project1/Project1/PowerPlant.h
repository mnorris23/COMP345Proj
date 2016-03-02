//A class that implements the powerplant cards in the game
#pragma once;

using namespace std;
#include <iostream>;
#include <string>;
#include <vector>;

//A class for the powerplant cards in the game
class Powerplant
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
	int _resStored;
	//the type(s) of resource(s) used by the powerplant. 1 is coal, 2 is oil, 3 is garbage, 4 is uranium and 5 is coal AND oil. Anything else means the powerplant doesnt use resources.
	int _resType;

	void initValues(){
		_citiesPowered = 0;
		_resStored = 0;
	}

public:
	//empty constructor
	Powerplant() : _value(0), _maxCitiesPowered(0), _resCost(0), _resType(0) {
		initValues();
	}
	//a constructor to build the card
	Powerplant(int value, int maxCitiesPowered, int resCost, int resType) :
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

	//returns the available space for resources
	int GetStorageSpace() {
		return _resCost * 2 - _resStored; //The total available space is the amount in resource cost *2 minus the resources already stored
	}



	//adds a number of cities to be powered by the powerplant 
	bool AddCities(int cities) {
		//verifies that the amount of cities being powered doesn't exceed the maximum
		if (_citiesPowered + cities > _maxCitiesPowered)
			return false;
		_citiesPowered += cities; //adds the specified amount of new cities to those being powered
		return true;
	}

	//removes a number of cities being powered
	bool RemoveCities(int cities) {
		//verifies that the value of _citiesPowered doesn't go below 0 (which would be impossible).
		if (_citiesPowered - cities < 0)
			return false;
		_citiesPowered -= cities; //removes specified amount of cities from those being powered
		return true;
	}

	//Stores an amount of resources of a certain type on the card
	bool StoreResource(int res, int type) {
		//verifies that the amount of resources stored doesn't exceed the maximum
		if (_resStored + res > _resCost * 2)
			return false;
		//verifies if the type of resource being stored is accepted
		if (_resType != type) {
			if (_resType == 5 && (type == 1 || type == 2)) {}
			else return false;
		}
		_resStored += res;//adds the resources
		return true;
	}

	//Consumes the amount of resources needed (if they have been previously stored on the card
	bool ConsumeResources() {
		if (_resStored < _resCost)//verifies that there are enough resources to be consumed
			return false;
		_resStored -= _resCost; //removes them from the resources stored
		return true;
	}

	//Displays the powerplant card.
	void DisplayPowerplant() {
		//a string with the name of the resource being stored
		std::string type;
		//Setting the name according to type
		switch (_resType) {
		case 1: type = "Coal"; break;
		case 2: type = "Oil"; break;
		case 3: type = "Garbage"; break;
		case 4: type = "Uranium"; break;
		case 5: type = "Coal and Oil"; break;
		default: type = "None";
		}
		//displaying powerplant name, cities powered, max cities powered, resource needed, resource cost and resources stored
		cout << "Value: "
			<< _value << "\nMax Cities Powered: " << _maxCitiesPowered
			<< "\nCities currently powered: " << _citiesPowered <<
			"\nResources needed: " << type << "\nResource cost: " << _resCost <<
			"\nResources stored: " << _resStored << endl;


	}

};