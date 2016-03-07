#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "House.h"
#include "PPlant.h"


class Player {

private:
	static int totalNumberOfPlayers; // static variable shared between all players to keep track of how many players are playing the game
	std::string pName; // player name
	std::string color; // player color
	int elektros; // number of elektros that the player has
	int numbOfHouses; // number of houses that the player has
	int numbOfPplants; // number of plants that the player has
	//const int MAX_NUMB_HOUSES = 17;
	House houses[17]; // array that holds up to 17 houses
	//std::vector<House> houses;
	
	//const int MAX_NUMB_PPLANTS = 3;
	PPlant pPlants[3]; // array that holds up to 3 plants
	
public:
	Player() {};
	Player(std::string, std::string);
	std::string getPname() { return pName; } // accessor for the pName
	std::string getColor() { return color; } // accessor for the color
	int getElektros() { return elektros; } // accessor for the elektros
	int getNumbOfHouses() { return numbOfHouses; } // accessor for the numbOfHouses
	int getNumbOfPplants() { return numbOfPplants; } // accessor for the numbOfpPlants
	House* getHouses() { return houses; } 
	PPlant* getPPlants() { return pPlants; } 
	void setElektros(int e) { elektros = e; } // mutator for elektros
	void setNumbOfHouses(int h) { numbOfHouses = h; } // mutator for numbOfHouses
	void setNumbOfPplants(int p) { numbOfPplants = p; } // mutator for numbOfPplants
};