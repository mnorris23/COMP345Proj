//The driver for the program
#pragma once;
//Including all the classes of the game
#include "Player.h";
#include "PowerPlant.h";
#include "House.h";
#include "ResourceMarket.h";
#include <string>;
using namespace std;

class Driver {

private:
	/*//The resource market
	ResourceMarket market;
	//Two players
	Player player1;
	Player player2;

	//Two houses
	House house1;
	House house2;

	//Two powerplants
	Powerplant pp1;
	Powerplant pp2;*/

public:
	Driver() {
		//Initializing new instances of the classes for the game
		/*market = ResourceMarket(24, 15, 6, 2);

		player1 = Player(50, "RED");
		player2 = Player(50, "BLUE");

		house1.location = "Montreal";
		house2.location = "Quebec";

		pp1 = Powerplant(19, 3, 2, 2);
		pp2 = Powerplant(20, 5, 3, 0);*/
	}
	//The method that will run the simulation
	void run();
};