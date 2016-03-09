#pragma once

//#include "Player.h";
#include "PowerPlant.h";
#include "Player.h"
#include <vector>


using namespace std;

class Auction{
private:

	std::vector<Player> _participants;
	//std::vector<Player*> _participants;

	int bid(int bidder);
	int _highestBid;
	PowerPlant _powerPlant;

public:

	Auction();

	//Auction(std::vector<int*> participants, int startingPrice);
	Auction(std::vector<Player>, PowerPlant);
	

	void run();


};