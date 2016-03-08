#include "Auction.h"
#include <iostream>
using namespace std;

int Auction::bid(int bidder){	
	int bid;
	do{
		cout << "Enter your bid, or -1 if you do not wish to bid: ";
		cin >> bid;
		if (bid != -1 && bid <= _highestBid)
			cout << "Your bid must be at least: " << _highestBid + 1 << endl;
		else if (bid > *(_participants[bidder]))
			cout << "You cannot afford to make this bid: ";
		else
			return bid;
	} while (1==1);
}

Auction::Auction(){
	_highestBid = 0;
	_participants;

}

Auction::Auction(std::vector<int*> participants, int startingPrice){
	_highestBid = startingPrice - 1;
	_participants = participants;
}

void Auction::run(){
	cout << "Welcome to the Auction. \nThe starting bid is " << _highestBid + 1 << "\nGood Luck!" << endl;

	while (_participants.size() > 1){
		for (int i = 0; i < _participants.size(); i++){
			
			cout << "Player " << i + 1 << "\'s turn." << endl;
			cout << "\n " << *_participants[i] << " and i = " << i << " current highest bid " << _highestBid << endl;
			int bid = this->bid(i);
			
			if (bid == -1){
				_participants.erase(_participants.begin() + i);
				cout << "\nSize " << _participants.size() << " and i is " << i << endl;
				if(_participants.size() == 1)
					break;
			}
			else{
				
				_highestBid = bid;
				
			}
			
		}
		
	}

	//if()
	*_participants[0] -= _highestBid;
	cout << *_participants[0];
	int j;
	cin >> j;
	//add powerplant to participant
}
