#include <iostream>
#include "powergrid.h"
using namespace std;

int main () {
	Player* player1 = createPlayer();
	delete player1;
	player1 = NULL;
	
}

Player* createPlayer() {
	char color;
	Player *player;

	cout << "Choose a color you want to be for this game." << endl;
	cout << "Enter \"b\" for black, \"r\" for red or \"w\" for white: ";
	cin >> color;

	switch(color) {
		case 'b': cout << "You are black" << endl; break;
		case 'r': cout << "Tou are red" << endl; break;
		case 'w': cout << "You are white" << endl; break;
		default : cout << "Wrong choice" << endl;

	}
	player = new Player(color);
	return player;
}