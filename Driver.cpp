#include "Map.h"
#include "Player.h"
#include "House.h"
#include "PPlant.h"
#include "pugixml.hpp"

#include <iostream>

using namespace std;

vector<Player> newGame() { // asks the users how many players will be playing the game and initiliazes that many players
	int numbOfPlayers;
	cout << "How many players will be playing?\n";
	cin >> numbOfPlayers;
	while (numbOfPlayers < 2 || numbOfPlayers > 6) {
		cout << "This game is played with 2-6 players!\nPlease try again:\n";
		cin >> numbOfPlayers;
	}

	vector<Player> players; // creating a vector of Players
	for (int i = 1; i <= numbOfPlayers; ++i) {
		string name;
		string color;
		cout << "What is your name player " << i << "?\n"; // every player is asked their name
		cin >> name;
		cout << "What house color would you like?\n"; // every player is asked to choose a color
		cin >> color;
		players.push_back(Player(name, color));
	}
	return players; // returns the vector of Player objects
}

void createResourceMarket(pugi::xml_node doc) { // function parses the resource info from the xml
	pugi::xml_node resourceMarket = doc.child("resourceMarket");
	int resourceAmount[4] = { 0, 0, 0, 0 }; // coal, oil, garbage, uranium

	for (pugi::xml_node currentBox = resourceMarket.child("box"); currentBox; currentBox = currentBox.next_sibling()) {
		pugi::xml_node holding = currentBox.child("holds");
		int coal = stoi(holding.child("coal").child_value());
		int oil = stoi(holding.child("oil").child_value());
		int garbage = stoi(holding.child("garbage").child_value());
		int uranium = stoi(holding.child("uranium").child_value());
		resourceAmount[0] = resourceAmount[0] + coal;
		resourceAmount[1] = resourceAmount[1] + oil;
		resourceAmount[2] = resourceAmount[2] + garbage;
		resourceAmount[3] = resourceAmount[3] + uranium;
	}
	for (int i = 0; i < 4; i++) {
		cout << resourceAmount[i] << endl;
	}
}

int main() {

	vector<Player> players = newGame(); // creating a vector of Player objects by calling the newGame function
	
	Map brazil;
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file("map.xml");  // loading the map into document
	
	if (result) { // checking if the document was parsed properly
		cout << "XML [" << "map.xml" << "] parsed without errors. \n";
		brazil.createMap(document.child("powergrid")); // a new map object is created from the xml file
	}
	else {
		cout << "XML [" << "map.xml" << "] parsed with errors. \n";
	}
	
	createResourceMarket(document.child("powergrid")); // creating the resource Market from the xml file

	brazil.printMap(); // printing out the contents of the map

	cout << "\nMin. cost from Belem to Maceio is: " << brazil.shortestDistance("Belem", "Maceio") << endl;

	brazil.saveMap(players, document.child("powergrid")); // storing all player info into the map
	
	cout << "\nWhat would you like to save the game as?\n"; // saving the map into the specified file by the user
	string gameName;
	cin >> gameName;
	const char* gN = gameName.c_str();
	document.save_file(gN);

	string done; // keeping the command prompt open (type in anything to exit)
	cin >> done;
	return 0;
}

