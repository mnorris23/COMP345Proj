#pragma once

//#include "Player.h";
//#include "PowerPlant.h";
#include <vector>


using namespace std;

class Auction{
private:
	
	//Powerplant _powerplant;

	std::vector<int*> _participants;
	//std::vector<Player*> _participants;

	int bid(int bidder);
	int _highestBid;

public:

	Auction();

	Auction(std::vector<int*> participants, int startingPrice);
	//Auction(std::vector<Player*> participants, Powerplant powerplant);
	

	void run();


};