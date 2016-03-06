//A class that implements the player in the game
#pragma once;

#include "House.h";
#include "PowerPlant.h";
#include <vector>;
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
	bool RemoveHouse(int index);

	bool SwapResource(int index1, int index2, int amount);

	//A method to remove a powerplant from the player's possessions
	bool RemovePowerplant(int index);

	//A method that adds a specified number of resources, of a specified type, to a powerplant specified by index, at a specific cost 
	bool AddResources(int index, std::vector<Resource> res);

	//displays the player and his possessions
	void DisplayPlayer();

};