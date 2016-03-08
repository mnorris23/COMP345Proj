#pragma once

#include "Auction.h"
#include "ResourceMarket.h"
#include "Player.h"
#include "PowerPlant.h"
#include "House.h"
#include <vector>
#include <string>

using namespace std;

class GameDriver{
private:
	//The Resource Market for the game
	ResourceMarket resourceMarket;
	//A vector holding the players of the game
	std::vector<Player> players;
	//Powerplants in the present market
	PowerPlant presentMarket[4];
	//PowerPlants in the futur market
	PowerPlant futurMarket[4];

public:
	//Empty Constructor
	GameDriver();
	//Constructor using an vector of Players
	GameDriver(std::vector<Player> players);
	//Empty Destructor
	~GameDriver();
	//Initializes the game
	void initGame();
	//Method that runs through a turn of the game
	void playTurn();
};