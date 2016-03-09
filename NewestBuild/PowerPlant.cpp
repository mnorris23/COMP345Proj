
#include <iostream>
#include <string>
#include "PowerPlant.h"

using namespace std;

PowerPlant::PowerPlant() : _value(0), _maxCitiesPowered(0), _resCost(0), _resType(0) {
	initValues(); 
}

PowerPlant::PowerPlant(int value, int maxCitiesPowered, int resCost, int resType) :
_value(value), _maxCitiesPowered(maxCitiesPowered), _resCost(resCost), _resType(resType){
	initValues();
}

int PowerPlant::GetValue(){ 
	return _value; 
}

int PowerPlant::GetMaxCitiesPowered(){
	return _maxCitiesPowered;
}

int PowerPlant::GetResCost(){
	return _resCost; 
}

int PowerPlant::GetResType(){ 
	return _resType; 
}

int PowerPlant::GetAmountStored(){ 
	return _resStored.size(); 
}

Resource* PowerPlant::GetResStoredAt(int index){ 
	return &_resStored[index]; 
}

int  PowerPlant::GetStorageSpace() {
	return _resCost * 2 - _resStored.size();
}

void PowerPlant::initValues(){
	//initializes cities powered
	_citiesPowered = 0;
}


bool PowerPlant::AddCities(int cities) {
	//verifies that the amount of cities being powered doesn't exceed the maximum
	if (_citiesPowered + cities > _maxCitiesPowered)
		return false;
	_citiesPowered += cities; //adds the specified amount of new cities to those being powered
	return true;
}

bool PowerPlant::RemoveCities(int cities) {
	//verifies that the value of _citiesPowered doesn't go below 0 (which would be impossible).
	if (_citiesPowered - cities < 0)
		return false;
	_citiesPowered -= cities; //removes specified amount of cities from those being powered
	return true;
}

bool PowerPlant::StoreResource(std::vector<Resource> resources) {
	//verifies that the amount of resources stored doesn't exceed the maximum
	if (_resStored.size() + resources.size() > _resCost * 2)
		return false;
	//verifies if the type of resource being stored is accepted
	for (int i = 0; i < resources.size(); i++){
		if (_resType != resources[i].type) {
			if (_resType == 4 && (resources[i].type == 0 || resources[i].type == 1)) {}
			else return false;
		}
		_resStored.push_back(resources[i]);//adds the resources
	}
	return true;
}

Resource PowerPlant::RemoveResource(int index){
	Resource res = _resStored[index];
	_resStored.erase(_resStored.begin() + index);
	//Removes the resource at specified index and returns it.
	return res;
}

std::vector<Resource> PowerPlant::ConsumeResources() {
	std::vector<Resource> res;
	if (_resStored.size() < _resCost)//verifies that there are enough resources to be consumed
		return res;//if not return empty vector
	for (int i = 0; i < _resCost; i++){
		res.push_back(_resStored[_resStored.size() - 1]);
		_resStored.pop_back(); //removes them from the resources stored
	}
	return res;
}

std::vector<Resource> PowerPlant::ConsumeResources(int type){
	std::vector<Resource> res, res1;
	for (int i = 0; i < _resStored.size(); i++){
		if (_resStored[i].type == type){//puts all of the resources of the type in a temp vector
			res.push_back(_resStored[i]);
			_resStored.erase(_resStored.begin() + i);
		}
	}
	if (res.size() < _resCost){//verifies that there are enough resources to be consumed
		for (int i = 0; i < res.size(); i++)
			_resStored.push_back(res[i]);

		return res1;//if not, returns empty vector
	}
	
	for (int i = 0; i < _resCost; i++){
		res1.push_back(res[_resStored.size() - 1]);
		res.pop_back();//removes them from the resources stored
	}

	for (int i = 0; i < res.size(); i++)
		_resStored.push_back(res[i]);//pushes back the remaining resources
	return res1;//returns the resources consumed
}

void PowerPlant::DisplayPowerplant() {
	//a string with the name of the resource being stored
	std::string type;
	//Setting the name according to type
	switch (_resType) {
	case 0: type = "Coal"; break;
	case 1: type = "Oil"; break;
	case 2: type = "Garbage"; break;
	case 3: type = "Uranium"; break;
	case 4: type = "Coal and Oil"; break;
	default: type = "None";
	}
	//displaying powerplant name, cities powered, max cities powered, resource needed, resource cost and resources stored
	cout << "Value: " << _value
		<< "\nMax Cities Powered: " << _maxCitiesPowered
		<< "\nResources needed: " << type
		<< "\nResource cost: " << _resCost << endl;
}