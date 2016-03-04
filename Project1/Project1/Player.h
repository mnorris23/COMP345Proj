//A class that implements the player in the game
#pragma once;
#include <iostream>;
#include "House.h";
#include "PowerPlant.h";
#include <vector>;
#include <string>;
using namespace std;

//A class for the players in the game
class Player{
private:
	//The color of the player
	std::string _color;
	//The amount of elektro of the player
	int _elektro;
	//A vector containing the houses owned by the player
	std::vector<House> _houses;
	//A vector containing the powerplants owned by the player
	std::vector<Powerplant> _powerplants;

public:
	//Empty constructor
	Player() :_elektro(0), _color("black") {}
	//Constructor with a the color of the player and a starting amount of elektro
	Player(int elektro, std::string color) :_elektro(elektro), _color(color){}

	//A Setter for the player color
	void SetColor(std::string color){ _color = color; }

	//A Getter for the player color
	std::string GetColor(){ return _color; }

	//A setter for the elektro
	void SetElektro(int elektro) { _elektro = elektro; }

	//A getter for the elektro
	int GetElektro(){ return _elektro; }

	//A getter for the number of houses owned
	int GetNumberOfHouses() { return _houses.size(); }

	//A getter for the number of powerplants owned
	int GetNumberOfPowerplants() { return _powerplants.size(); }

	//A method to add a house to the player's possessions
	bool AddHouse(House house, int cost) { if (_elektro < cost) return false; _houses.push_back(house); return true; }

	//A method to add a powerplant to the player's possessions
	bool AddPowerplant(Powerplant powerplant, int cost) { if (_elektro < cost) return false; _powerplants.push_back(powerplant); return true; }

	//Returns a pointer to a house owned by the player
	House* GetHouse(int index){ return &(_houses.at(index)); }

	//Returns a pointer to a powerplant owned by the player
	Powerplant* GetPowerplant(int index){ return &(_powerplants.at(index)); }

	//A method to remove a house from the player's possessions
	bool RemoveHouse(int index) {
		if (index > _houses.size() || index < 0)
			return false;//verifies that the index is within the acceptable range for the vector
		_houses.erase(_houses.begin() + index); //removes the house at the specified index
		return true;
	}

	//A method to remove a powerplant from the player's possessions
	bool RemovePowerplant(int index) {
		if (index > _powerplants.size() || index < 0)
			return false;//verifies that the index is within the acceptable range for the vector
		_powerplants.erase(_powerplants.begin() + index);//removes the powerplant at the specified index
		return true;
	}

	//A method that adds a specified number of resources, of a specified type, to a powerplant specified by index, at a specific cost 
	bool AddResources(int index, int amount, int cost, int type) {
		if (cost > _elektro || index > _powerplants.size() || index < 0)
			return false;//verifies that the index is within the acceptable range for the vector and that the player has enough elektro to pay for the resources
		return _powerplants[index].StoreResource(amount, type); //tries to stores the resources in the powerplant

	}

	//displays the player and his possessions
	void DisplayPlayer() {
		////Displays the specific information about the player
		cout << "Player " << _color <<
			"\nElektros: " << _elektro <<
			"\n\nCurrent number of houses: " << _houses.size() <<
			"\nCurrent number of powerplants: " << _powerplants.size() << endl;
		//displays the specific information about the player's houses
		cout << "Locations in which player has houses:" << endl;

		for (int i = 0; i < _houses.size(); i++) {//uses a loop to iterate through all the houses
			cout << _houses[ i].location << endl;
		}
		//displays the specific information about the player's powerplants
		cout << "Summary of Powerplants:" << endl;

		for (int i = 0; i < _powerplants.size(); i++) {//uses a loop to iterate through all the powerplants
			_powerplants[i].DisplayPowerplant();//calls the display method of the powerplant
		}
	}

};