#include "GameDriver.h"

using namespace std;




//Empty for now
GameDriver::GameDriver(){

}


GameDriver::GameDriver(std::vector<Player> players){
	//Initializes the vector of players
	this->players = players;

}

void GameDriver::initGame(){

}

void GameDriver::playTurn(){

	//Determine player order
	//Temp vector of players
	std::vector<Player> playersInOrder;
	playersInOrder = playerOrder(players);
	
	//Auction PowerPlants

	//Buy Resources

	//Bureaucracy


}  

/**
Determine player order in the beginning of every turn based on first how many houses 
owned by the player. If there is a tie then we check the powerplant with the 
max value.
@return descending order vector<player>
*/

vector<Player> GameDriver::playerOrder(vector<Player> players) {

	Player temp;
	for (int i = 0; i < players.size(); i++) {
		for (int j = players.size() - 1; j > i; j--) {
			if (players[j].getNumberOfHouses() > players[j - 1].getNumberOfHouses()) {
				temp = players[j - 1];
				players[j - 1] = players[j];
				players[j] = temp;
			}
		}
	}

	for (int i = 0; i < players.size(); i++) {
		for (int j = players.size() - 1; j > i; j--) {
			if (players[j].getNumberOfHouses() == players[j - 1].getNumberOfHouses()) {
				if (players[j].getMaxValuePowerplant() > players[j - 1].getMaxValuePowerplant()) {
					temp = players[j - 1];
					players[j - 1] = players[j];
					players[j] = temp;
				}
			}

		}
	}
	return players;
}