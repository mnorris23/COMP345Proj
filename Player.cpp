#include "Player.h"
#include "House.h"
#include "PPlant.h"

#include <string>
#include <iostream>

using namespace std;

int Player::totalNumberOfPlayers = 0;

Player::Player(std::string n, std::string c) { // constructor that takes in 2 parameters
	if (totalNumberOfPlayers < 6) {
		pName = n;
		color = c;
		elektros = 50; // every player starts with 50 elektros
		numbOfHouses = 0; // every player starts with 0 houses
		numbOfPplants = 0; // every player starts with 0 power plants
		totalNumberOfPlayers++;
	}
	else
		std::cout << "Sorry, there is already 6 players playing the game." << std::endl;
}

