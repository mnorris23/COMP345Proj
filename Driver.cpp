#include "Map.h"
#include "Player.h"
#include "House.h"
#include "PowerPlant.h"
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

vector<int> createResourceMarket(pugi::xml_node doc) { // function parses the resource market info from the xml
	pugi::xml_node resourceMarketNode = doc.child("resourceMarket");
	vector<int> resourceMarket; // coal, oil, garbage, uranium
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	for (pugi::xml_node currentBox = resourceMarketNode.child("box"); currentBox; currentBox = currentBox.next_sibling()) {
		pugi::xml_node holding = currentBox.child("holds");
		int coal = stoi(holding.child("coal").child_value());
		int oil = stoi(holding.child("oil").child_value());
		int garbage = stoi(holding.child("garbage").child_value());
		int uranium = stoi(holding.child("uranium").child_value());
		resourceMarket[0] = resourceMarket[0] + coal;
		resourceMarket[1] = resourceMarket[1] + oil;
		resourceMarket[2] = resourceMarket[2] + garbage;
		resourceMarket[3] = resourceMarket[3] + uranium;
	}
	return resourceMarket;
}

vector<int> createResourceSupply(pugi::xml_node doc) { // function parses the resource supply info from the xml
	pugi::xml_node resourceSupplyNode = doc.child("resourceSupply");
	vector<int> resourceSupply; // coal, oil, garbage, uranium
	resourceSupply.push_back(stoi(resourceSupplyNode.child("coal").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("oil").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("garbage").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("uranium").child_value()));
	return resourceSupply;
}

int costToLocation(Player p, string newCityLocation, Map m) { // function calculates the cost to get to a new location, takes in the player buying a new house, the city name and the map object
	vector<House> h = p.getHouses();
	string location;
	vector<int> minCosts;
	for (vector<House>::iterator it = h.begin(); it != h.end(); it++) {
		location = (*it).getLocation();
		minCosts.push_back(m.shortestDistance(location, newCityLocation));
	}
	int minCost = 9000;
	for (vector<int>::iterator it = minCosts.begin(); it != minCosts.end(); it++) {
		if (minCost > *it)
			minCost = *it;
	}
	return minCost;
}

void loadPlayers(pugi::xml_node doc, vector<Powerplant> pplants) {
	pugi::xml_node playersNode = doc.child("players");
	vector<Player> players;
	for (pugi::xml_node currentPlayerNode = playersNode.child("player"); currentPlayerNode; currentPlayerNode = currentPlayerNode.next_sibling()) {
		string pName = currentPlayerNode.child("name").child_value();
		string pColor = currentPlayerNode.child("color").child_value();
		int elektros = stoi(currentPlayerNode.child("elektros").child_value());
		Player player(pName, pColor, elektros);
		for (pugi::xml_node currentHouseNode = currentPlayerNode.child("houses").child("location"); currentHouseNode; currentHouseNode = currentHouseNode.next_sibling()) {
			string location = currentHouseNode.child_value();
			House h(location);
			player.addHouse(h);
		}
		for (pugi::xml_node currentPPlantNode = currentPlayerNode.child("powerPlants").child("powerPlant"); currentPPlantNode; currentPPlantNode = currentPPlantNode.next_sibling()) {
			int value = stoi(currentPPlantNode.child("value").child_value());
			int resourceType = pplants[value].GetResType();
			Powerplant pplant = pplants[value];
			vector<Resource> r;
			int resourceAmount = stoi(currentPPlantNode.child("resources").child_value());
			if (resourceAmount > 6) { // if there is more than 6 resources than the plant is a hybrid and is storing resources as a double digit
				int coalAmount = resourceAmount / 10; // first digit represnts the coal amount
				int oilAmount = resourceAmount % 10; // second digit represents the oil amount 
				for (int i = 1; i <= coalAmount; i++) {
					Resource resource;
					resource.type = 0; // coal
					r.push_back(resource);
				}
				for (int i = 1; i <= oilAmount; i++) {
					Resource resource;
					resource.type = 1; // oil
					r.push_back(resource);
				}
			}
			else { // not a hybrid
				for (int i = 1; i <= resourceAmount; i++) {
					Resource resource;
					resource.type = resourceType; // resource type the powerplant is holding
					r.push_back(resource);
				}
			}
			pplant.StoreResource(r);
		}
	}
}


vector<Powerplant> buildPowerplants() {

	vector<Powerplant> powerplants;


	// These are no being used just filler objects
	powerplants[0] = Powerplant(0, 0, 0, 0);
	powerplants[1] = Powerplant(0, 0, 0, 0);
	powerplants[2] = Powerplant(0, 0, 0, 0);
	powerplants[41] = Powerplant(0, 0, 0, 0);
	powerplants[43] = Powerplant(0, 0, 0, 0);
	powerplants[45] = Powerplant(0, 0, 0, 0);
	powerplants[47] = Powerplant(0, 0, 0, 0);
	powerplants[48] = Powerplant(0, 0, 0, 0);
	powerplants[49] = Powerplant(0, 0, 0, 0);

	//Powerplant(int value, int maxCitiesPowered, int resCost, int resType) 
	// -1 for resType represents eco powerplants
	powerplants[3] = Powerplant(3, 1, 2, 1);
	powerplants[4] = Powerplant(4, 1, 2, 0);
	powerplants[5] = Powerplant(5, 1, 2, 4);
	powerplants[6] = Powerplant(6, 1, 1, 2);

	powerplants[7] = Powerplant(7, 2, 3, 1);
	powerplants[8] = Powerplant(8, 2, 3, 0);
	powerplants[9] = Powerplant(9, 1, 1, 1);
	powerplants[10] = Powerplant(10, 2, 2, 0);

	powerplants[11] = Powerplant(11, 2, 1, 3);
	powerplants[12] = Powerplant(12, 2, 2, 4);
	powerplants[13] = Powerplant(13, 1, 0, -1);
	powerplants[14] = Powerplant(14, 2, 2, 2);

	powerplants[15] = Powerplant(15, 3, 2, 0);
	powerplants[16] = Powerplant(16, 3, 2, 1);
	powerplants[17] = Powerplant(17, 2, 1, 3);
	powerplants[18] = Powerplant(18, 2, 0, -1);

	powerplants[19] = Powerplant(19, 3, 2, 2);
	powerplants[20] = Powerplant(20, 5, 3, 0);
	powerplants[21] = Powerplant(21, 4, 2, 4);
	powerplants[22] = Powerplant(22, 2, 0, -1);

	powerplants[23] = Powerplant(23, 3, 1, 3);
	powerplants[24] = Powerplant(24, 4, 2, 2);
	powerplants[25] = Powerplant(25, 5, 2, 0);
	powerplants[26] = Powerplant(26, 5, 2, 1);

	powerplants[27] = Powerplant(27, 3, 0, -1);
	powerplants[28] = Powerplant(28, 4, 1, 3);
	powerplants[29] = Powerplant(29, 4, 1, 4);
	powerplants[30] = Powerplant(30, 6, 3, 2);

	powerplants[31] = Powerplant(31, 6, 3, 0);
	powerplants[32] = Powerplant(32, 6, 3, 1);
	powerplants[33] = Powerplant(33, 4, 0, -1);
	powerplants[34] = Powerplant(34, 5, 1, 3);

	powerplants[35] = Powerplant(35, 5, 1, 1);
	powerplants[36] = Powerplant(36, 7, 3, 0);
	powerplants[37] = Powerplant(37, 4, 0, -1);
	powerplants[38] = Powerplant(38, 7, 3, 2);

	powerplants[39] = Powerplant(39, 6, 1, 3);
	powerplants[40] = Powerplant(40, 6, 2, 1);

	powerplants[42] = Powerplant(42, 6, 2, 0);

	powerplants[44] = Powerplant(44, 5, 0, -1);

	powerplants[46] = Powerplant(46, 7, 3, 4);
	powerplants[50] = Powerplant(50, 6, 0, -1);

	return powerplants;
}

int main() {

	vector<Player> players = newGame(); // creating a vector of Player objects by calling the newGame function
	vector<Powerplant> pplants = buildPowerplants(); // creating a vector of all the powerplants

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
	House house("Belem");
	players[1].addHouse(house, 10);
	House house1("Vilhena");
	players[1].addHouse(house1, 10);
	cout << "The minimum cost to get to Palmas is " << costToLocation(players[1], "Palmas", brazil) << endl;

	// THESE 2 FUNCTIONS NEED TO BE USED BY OLIVIER
	createResourceMarket(document.child("powergrid")); // creating the resource Market from the xml file
	createResourceSupply(document.child("powergrid")); // creating the resource Supply from the xml file
	
	
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
