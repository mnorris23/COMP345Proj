#include "GameDriver.h"
#include <iostream>


using namespace std;




//Empty for now
GameDriver::GameDriver() {
	cout << "Press 0 for new game or -1 to load a saved game: ";
	
	int newgame;
	
	cin >> newgame;

	if (newgame == 0){
		
		phaseNumber = 1;
		stepNumber = 1;
		turnNumber = 1;

		players = newGame(); // creating a vector of Player objects by calling the newGame function
		//vector<PowerPlant> pplants =  // creating a vector of all the powerplants


		// document is now a member variable pointer
		//document = new pugi::xml_document();
		pugi::xml_document document;
		pugi::xml_parse_result result = document.load_file("map.xml");  // loading the map into document
		mView = new MapView(&brazil);

		if (result) { // checking if the document was parsed properly
			cout << "XML [" << "map.xml" << "] parsed without errors. \n";

			brazil.createMap(document.child("powergrid")); // a new map object is created from the xml file

		}
		else {
			cout << "XML [" << "map.xml" << "] parsed with errors. \n";
		}
		createResourceMarket(document.child("powergrid"));

		powerplantmarket = new PowerPlantMarket(document.child("powergrid"));
		powerplantmarket_observer = new PowerPlantMarket_Observer(powerplantmarket);

		gameLog = new GameLog_Subject();
		gameLog_ob = new GameLog_Observer(gameLog);
		gameLog_ob = new GameLog_AllPhase_AllPlayer(gameLog_ob, gameLog);
		playTurn(document);
	}
	
}

GameDriver::~GameDriver() {
	delete mView;
	mView = NULL;
	delete powerplantmarket_observer;
	powerplantmarket_observer = NULL;
	delete powerplantmarket;
	powerplantmarket = NULL;
	delete gameLog_ob;
	gameLog_ob = NULL;
	delete gameLog;
	gameLog = NULL;
	
}



vector<Player> GameDriver::newGame() { // asks the users how many players will be playing the game and initiliazes that many players
	int numbOfPlayers;
	cout << "How many players will be playing?\n";
	cin >> numbOfPlayers;
	while (numbOfPlayers < 2 || numbOfPlayers > 6) {
		cout << "This game is played with 2-6 players!\nPlease try again:\n";
		cin >> numbOfPlayers;
	}
	int maxPplants = 3;
	if (numbOfPlayers == 2) {
		maxPplants = 4;
		winningNumberOfCities = 21;
		numberOfCitiesToPhase2 = 10;
	}
	else if (numbOfPlayers == 5) {
		winningNumberOfCities = 15;
	}
	else if (numbOfPlayers == 6) {
		winningNumberOfCities = 14;
		numberOfCitiesToPhase2 = 6;
	}
	else {
		winningNumberOfCities = 17;
		numberOfCitiesToPhase2 = 7;
	}

	vector<Player> players; // creating a vector of Players
	for (int i = 1; i <= numbOfPlayers; ++i) {
		string name;
		string color;
		cout << "What is your name player " << i << "?\n"; // every player is asked their name
		cin >> name;
		cout << "What house color would you like?\n"; // every player is asked to choose a color
		cin >> color;
		players.push_back(Player(name, color, maxPplants));
	}
	return players; // returns the vector of Player objects
}



void GameDriver::createResourceMarket(pugi::xml_node doc) { // function parses the resource market info from the xml

	pugi::xml_node resourceMarketNode = doc.child("resourceMarket");

	// coal, oil, garbage, uranium
	//vector<int> resMarket; 
	int resMarket[4];

	resMarket[0] = 0;
	resMarket[1] = 0;
	resMarket[2] = 0;
	resMarket[3] = 0;

	for (pugi::xml_node currentBox = resourceMarketNode.child("box"); currentBox; currentBox = currentBox.next_sibling()) {

		int cost = stoi(currentBox.child("cost").child_value());

		pugi::xml_node holding = currentBox.child("holds");

		int coal = stoi(holding.child("coal").child_value());
		int oil = stoi(holding.child("oil").child_value());
		int garbage = stoi(holding.child("garbage").child_value());
		int uranium = stoi(holding.child("uranium").child_value());

		//resMarket.push_back(stoi(holding.child("coal").child_value()));
		//resMarket.push_back(stoi(holding.child("oil").child_value()));
		//resMarket.push_back(stoi(holding.child("garbage").child_value()));
		//resMarket.push_back(stoi(holding.child("uranium").child_value()));

		
		resMarket[0] = resMarket[0] + coal;
		resMarket[1] = resMarket[1] + oil;
		resMarket[2] = resMarket[2] + garbage;
		resMarket[3] = resMarket[3] + uranium;

	}

	//cout << resMarket[0] << " " << resMarket[1] << " " << resMarket[2] << " " << resMarket[3] << endl;
	//resourceMarket = ResourceMarket(resMarket[0],resMarket[1],resMarket[2],resMarket[3]);

	// error fixed, resource market is being read from file
	resourceMarket = ResourceMarket(resMarket[0], resMarket[1], resMarket[2], resMarket[3]);

}

vector<int> GameDriver::createResourceSupply(pugi::xml_node doc) { // function parses the resource supply info from the xml
	pugi::xml_node resourceSupplyNode = doc.child("resourceSupply");
	vector<int> resourceSupply; // coal, oil, garbage, uranium
	resourceSupply.push_back(stoi(resourceSupplyNode.child("coal").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("oil").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("garbage").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("uranium").child_value()));
	return resourceSupply;
}

void GameDriver::saveGame(pugi::xml_node node) {
	int numbOfPlayers = players.size();

	pugi::xml_node cityNode;
	vector<Map::City>::iterator cityItr;
	for (cityItr = brazil.cities.begin(), cityNode = node.child("map").child("city"); cityItr != brazil.cities.end(); cityItr++, cityNode = cityNode.next_sibling()) {
		int numbOfHouses = (*cityItr).getNumbOfOccupants();
		if (numbOfHouses > 0) {
			Player* p = (*cityItr).getOccupants();
			pugi::xml_node occupantNode;
			int i;
			for (i = 0, occupantNode = cityNode.child("occupants").child("occupant"); i < numbOfHouses; i++, occupantNode = occupantNode.next_sibling()) {
				p = p + i;
				string playerName = (*p).getName();
				const char* pN = playerName.c_str();
				occupantNode.append_child(pugi::node_pcdata).set_value(pN);
			}
		}
	}

	// adding xml nodes to store all information about players
	pugi::xml_node player;
	for (int i = 0; i < numbOfPlayers - 2; i++) { // if there are more than 2 players, then the xml file is extended to be able to store those players' data
		player = node.child("players"); // adding xml elements to add player's info
		player.append_copy(player.first_child());
		player = node.child("playerOrder"); // adding xml elements to add the player order slot
		player.append_copy(player.first_child());
	}

	// if there are more than 2 players, then the scoringTrack is extended to accomodate those players
	for (player = node.child("scoringTrack").child("position"); player; player = player.next_sibling()) {
		for (int i = 0; i < numbOfPlayers - 2; i++) {
			player.append_child(pugi::node_element).set_name("spot");
		}
	}

	vector<Player>::iterator it;
	for (player = node.child("playerOrder").child("order"), it = players.begin(); it != players.end(); player = player.next_sibling(), ++it) { // adding player names to the player order section
		string playerName = (*it).getName();
		const char* pN = playerName.c_str();
		player.append_child(pugi::node_pcdata).set_value(pN);
	}

	for (player = node.child("players").child("player"), it = players.begin(); it != players.end(); player = player.next_sibling(), ++it) { // adding player info into the players section
		string playerName = (*it).getName();
		string playerColor = (*it).getColor();
		string elektros = to_string((*it).getMoney());

		const char* pN = playerName.c_str();
		const char* pC = playerColor.c_str();
		const char* el = elektros.c_str();
		player.child("name").append_child(pugi::node_pcdata).set_value(pN); // saving player name
		player.child("color").append_child(pugi::node_pcdata).set_value(pC); // saving player color
		player.child("elektros").append_child(pugi::node_pcdata).set_value(el); // saving player's money

		pugi::xml_node houseNode;
		int numbOfHouses = (*it).getNumberOfHouses();
		for (int i = 0; i < numbOfHouses - 1; i++) { // if the player owns more than one house, then the xml file is extended to store those houses (their locations)
			houseNode = player.child("houses");
			houseNode.append_child(pugi::node_element).set_name("location");
		}

		int j;
		for (houseNode = player.child("houses").child("location"), j = 0; j < numbOfHouses; houseNode = houseNode.next_sibling(), j++) {
			string loc = (*(*it).GetHouse(j)).location;
			const char* constLoc = loc.c_str();
			houseNode.append_child(pugi::node_pcdata).set_value(constLoc); // saving player's house locations
		}

		pugi::xml_node pplantNode;
		int numbOfPplants = (*it).getNumberOfPowerPlants();
		for (int i = 0; i < numbOfPplants - 3; i++) { // if the player owns more than one house, then the xml file is extended to store those houses (their locations)
			pplantNode = player.child("powerPlants");
			pplantNode.append_copy(pplantNode.first_child());
		}

		for (pplantNode = player.child("powerPlants").child("powerPlant"), j = 0; j < numbOfPplants; pplantNode = pplantNode.next_sibling(), j++) {
			int value = (*(*it).GetPowerplant(j)).GetValue();
			int resources = (*(*it).GetPowerplant(j)).GetAmountStored();
			string v = to_string(value);
			string r = to_string(resources);
			const char* constV = v.c_str();
			const char* constR = r.c_str();
			pplantNode.child("value").append_child(pugi::node_pcdata).set_value(constV);
			pplantNode.child("resources").append_child(pugi::node_pcdata).set_value(constR);
		}
	}
}

bool GameDriver::saveGameOption(pugi::xml_document& doc) {
	int saveGameNow = 0;
	cout << "\nWould you like to save the game? Enter -1 if so or 0 to continue:\n";
	cin >> saveGameNow;
	if (saveGameNow == -1) {
		saveGame(doc.child("powergrid")); // adding the game's current state to the node object

		cout << "\nWhat would you like to save the game as?\n"; // saving the map into the specified file by the user
		string gameName;
		cin >> gameName;
		const char* gN = gameName.c_str();
		doc.save_file(gN);

		return true;
	}
	return false;
}

void GameDriver::playTurn(pugi::xml_document& doc) {
	
	//Determine player order
	//Temp vector of players
	bool lastTurn = false;
	string line = "\n---------------------------------------------------------------\n";

	if (phaseNumber == 1 && turnNumber == 1){
		for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
			(*it).displayPlayerInformation(powerplantmarket_observer);
			(*it).canBidForAuction = true;
		}
		phaseNumber = 2;
		
		Phase2();

		phaseNumber = 3;
		playerOrder(players);
		
		if (saveGameOption(doc))
			return;

		for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
			(*it).displayPlayerInformation(powerplantmarket_observer);
		}
		
		Phase3();

		phaseNumber = 4;
		
		if (saveGameOption(doc))
			return;

		
		
		gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, phaseNumber, false, "all");
		lastTurn = brazil.Phase4(players, powerplantmarket_observer, gameLog, winningNumberOfCities, stepNumber);

		phaseNumber = 5;
		
		if (saveGameOption(doc))
			return;

		
		Phase5();

		phaseNumber = 1;

		if (saveGameOption(doc))
			return;
	}
	else{
		if (phaseNumber == 1){
			for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
				(*it).displayPlayerInformation(powerplantmarket_observer);
				(*it).canBidForAuction = true;
			}
			phaseNumber = 2;
		}
		if (phaseNumber == 2){
			Phase2();

			phaseNumber = 3;
			
			if (saveGameOption(doc))
				return;

			for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
				(*it).displayPlayerInformation(powerplantmarket_observer);
			}	

			
		}
		if (phaseNumber == 3){
			Phase3();

			phaseNumber = 4;
			
			if (saveGameOption(doc))
				return;

			
		}
		if (phaseNumber == 4){
			gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, phaseNumber, false, "all");
			lastTurn = brazil.Phase4(players, powerplantmarket_observer, gameLog, winningNumberOfCities, stepNumber);
			
			phaseNumber = 5;
			
			if (saveGameOption(doc))
				return;

			
		}
		if (phaseNumber == 5){
			Phase5();
			phaseNumber = 1;
			if (saveGameOption(doc))
				return;
		}
	}
	while (lastTurn == false) {
		turnNumber++;
		//Determine player order
		
		playerOrder(players);
		//Temp vector of players
		for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
			(*it).displayPlayerInformation(powerplantmarket_observer);
			(*it).canBidForAuction = true;
		}
		phaseNumber = 2;
		
		if (saveGameOption(doc))
			return;

		
		Phase2();
		
		phaseNumber = 3;
		
		if (saveGameOption(doc))
			return;

		for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
			(*it).displayPlayerInformation(powerplantmarket_observer);
		}

		
		Phase3();
		
		phaseNumber = 4;

		if (saveGameOption(doc))
			return;

		
		
		gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, 2, false, "all");
		lastTurn = brazil.Phase4(players, powerplantmarket_observer, gameLog, winningNumberOfCities, stepNumber);
		gameLog->updateLog("\nThis is the end of the building phase for turn #" + to_string(turnNumber) + "\n", phaseNumber, false, "all");
		if (stepNumber == 1) {
			for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
				if ((*it).getNumberOfHouses() >= numberOfCitiesToPhase2) {
					stepNumber = 2;
					powerplantmarket->updateMarket(0, 0, true);
					break;
				}
			}
		}
		
		phaseNumber = 5;
		
		if (saveGameOption(doc))
			return;

		
		Phase5();

		phaseNumber = 1;
		
		if (saveGameOption(doc))
			return;
	}


	int j;
	cin >> j;


}

void GameDriver::Phase2() {

	powerplantmarket_observer->displayMarket();

	bool auctioned = false;

	string line = "\n---------------------------------------------------------------\n";
	gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, 2, false, "all");

	for (int index = 0; index < players.size(); index++) {

		for (int i = index; i < players.size() + index; i++) {
			if (players[i % players.size()].canBidForAuction == true) {
				int bidOn;
				do {
					if (turnNumber == 1) {
						cout << "\nPlayer " << players[i % players.size()].getName() << ", enter the number of the powerplant you wish to bid on (1-4): "; // players[i].getName() has been switched to players[i % players.size()].getName() to avoid indexOutOfBounds
						cin >> bidOn;
						auctioned = true;
					}
					else {
						cout << "\nPlayer " << players[i % players.size()].getName() << ", enter the number of the powerplant you wish to bid on (1-4) or -1 to skip: "; // players[i].getName() has been switched to players[i % players.size()].getName() to avoid indexOutOfBounds
						cin >> bidOn;
						if (bidOn == -1) {
							players[i].canBidForAuction = false;
							break;
						}
						auctioned = true;
					}
				} while (bidOn > 4);
				if (bidOn > 0) {
					gameLog->updateLog(players[i % players.size()].getName() + " put powerplant #" + to_string(powerplantmarket->getPowerPlant(0, bidOn - 1).GetValue()) + " to auction\n", 2, false, "all");
					Auction(0, bidOn - 1);
					powerplantmarket->updateMarket(0, bidOn - 1, true);
				}
				break;
			}
		}
		
	}
	gameLog->updateLog("\nThis is the end of the auction phase for turn #" + to_string(turnNumber) + "\n", 2, false, "all");

	if (auctioned == false) {
		powerplantmarket->updateMarket(0, 0, true);
	}

}

void GameDriver::Auction(int row, int column) {
	int _highestBid = powerplantmarket->getPowerPlant(row, column).GetValue() - 1;

	int bidders = 0;

	for (vector<Player>::iterator i = players.begin(); i < players.end(); i++) {
		if ((*i).canBidForAuction == true) {
			bidders++;
			(*i).canBid = true;
			gameLog->updateLog((*i).getName() + " can bid!\n", 2, false, (*i).getColor());
		}
		else {
			(*i).canBid = false;
			gameLog->updateLog((*i).getName() + " cannot bid!\n", 2, false, (*i).getColor());
		}
	}

	if (bidders > 1) {
		cout << "Welcome to the Auction. \nThe starting bid is " << _highestBid + 1 << "\nGood Luck!" << endl;
		while (bidders > 1) {
			int index = 0;
			for (vector<Player>::iterator i = players.begin(); i < players.end(); i++) {
				if ((*i).canBid == true) {

					int currentbid = bid(index, _highestBid);

					if (currentbid == -1) {
						gameLog->updateLog("\n" + (*i).getName() + " doesn't bid on powerplant #" + to_string(powerplantmarket->getPowerPlant(row, column).GetValue()) + " and is now out of this auction.\n", 2, false, (*i).getColor());
						(*i).canBid = false;
						bidders--;
						if (bidders == 1) {
							break;
						}
					}
					else {
						_highestBid = currentbid;
						gameLog->updateLog("\n" + (*i).getName() + " made a bid of " + to_string(_highestBid) + " elektros on powerplant #" + to_string(powerplantmarket->getPowerPlant(row, column).GetValue()) + "\n", 2, false, (*i).getColor());
					}
				}
				index++;
			}
		}
	}

	for (vector<Player>::iterator i = players.begin(); i < players.end(); i++) {
		if ((*i).canBid == true) {
			(*i).canBidForAuction = false;
			if (_highestBid < powerplantmarket->getPowerPlant(row, column).GetValue()) {
				_highestBid++;
			}
			string str = (*i).getName() + " is the winner of the auction of powerplant #" + to_string(powerplantmarket->getPowerPlant(row, column).GetValue()) + " for " + to_string(_highestBid) + " elektros\n";
			str += (*i).getName() + " had " + to_string((*i).getMoney()) + " and now has " + to_string((*i).getMoney() - _highestBid) + " elektros.\n";
			gameLog->updateLog(str, 2, false, (*i).getColor());
			(*i).AddPowerplant(powerplantmarket->getPowerPlant(row, column), _highestBid);		
			break;
		}
	}

}

int GameDriver::bid(int bidder, int _highestBid) {
	int bid;
	do {
		cout << "\nPlayer " << players[bidder].getName() << " enter your bid, or -1 if you do not wish to bid: ";
		cin >> bid;
		if (bid == -1)
			return bid;
		else if (bid <= _highestBid)
			cout << "\nYour bid must be at least: " << _highestBid + 1 << endl;
		else if (bid > players[bidder].getMoney())
			cout << "\nYou cannot afford to make this bid: ";
		else
			return bid;
	} while (true);
}

void GameDriver::Phase3() {

	string line = "\n---------------------------------------------------------------\n";
	gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, phaseNumber, false, "all");

	for (vector<Player>::reverse_iterator rit = players.rbegin(); rit != players.rend(); rit++) {

		resourceMarket.DisplayMarket();

		do {
			rit->displayPlayerInformation(powerplantmarket_observer);
			cout << "\nPlayer " << (*rit).getName() << " it is your turn to buy resources." << endl;
			cout << "\nCoal is 1, Oil is 2, Garbage is 3 and Uranium is 4."
				<< "\nEnter the type of the resource you wish to buy (or -1 to exit): ";
			int type;
			cin >> type;
			if (type == -1) break;
			cout << "\nEnter the amount of resources you wish to buy (or -1 to exit): ";
			int amount;
			cin >> amount;
			if (amount == -1) break;
			cout << "\nEnter the index of the PowerPlant that will store the resources (1-" << (*rit).getNumberOfPowerPlants() << ") (or -1 to exit): ";
			int index;
			cin >> index;
			if (index == -1) break;
			int totalCost = resourceMarket.BuyResource(type - 1, amount, (*rit).getMoney());
			if ((*rit).AddResources(index - 1, type - 1, amount, totalCost)) {
				string res = "";
				switch (type) {
					case 1: res = " coal "; break;
					case 2: res = " oil "; break;
					case 3: res = " garbage "; break;
					case 4: res = " uranium "; break;
				}
				string str = "\n" + (*rit).getName() + " bought " + to_string(amount) + res + " for " + to_string(totalCost) + " elektros";
				str += " and stored it on powerplant #" + to_string((*(*rit).GetPowerplant(index - 1)).GetValue()) + "\n";
				str += "Resources stored in PowerPlant # " + to_string((*(*rit).GetPowerplant(index - 1)).GetValue()) + ": " + to_string((*(*rit).GetPowerplant(index -1)).GetAmountStored());
				str += "\n" + (*rit).getName() + " had " + to_string((*rit).getMoney() + totalCost) + " and now has " + to_string((*rit).getMoney()) + " elektros.\n";
				gameLog->updateLog(str, phaseNumber, false, (*rit).getColor());
			}
			else {
				resourceMarket.pushResources(amount, type - 1);
				cout << "You cannot make this operation." << endl;
			}

			resourceMarket.DisplayMarket();
		} while (true);

		
	}
	gameLog->updateLog("\nThis is the end of the resource phase for turn #" + to_string(turnNumber) + "\n", phaseNumber, false, "all");
}

void GameDriver::Phase5() {
	//Bureaucracy


	string line = "\n---------------------------------------------------------------\n";
	gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, phaseNumber, false, "all");

	for (vector<Player>::iterator i = players.begin(); i < players.end(); i++) {
		//display the amount of houses (cities)
		//display the amount that can be powered by each powerplant of the player
		//ask the player how much he wants each powerplant to power
		//ajust the value in powerplant
		int citiesToPower = (*i).getNumberOfHouses();
		int amountOfCitiesPowered = 0;
		(i)->displayPlayerInformation(powerplantmarket_observer);

		cout << "\n-------------------------------------";
		cout << "\nPlayer " << (*i).getName() << " has " << citiesToPower << " cities he needs to power." << endl;
		for (int j = 0; j < (*i).getNumberOfPowerPlants(); j++) {
			if ((*(*i).GetPowerplant(j)).GetAmountStored() >= (*(*i).GetPowerplant(j)).GetResCost()) {
				cout << "PowerPlant " << (*(*i).GetPowerplant(j)).GetValue() << " can power " << (*(*i).GetPowerplant(j)).GetMaxCitiesPowered() << " cities." << endl;
				cout << "It has " << (*(*i).GetPowerplant(j)).GetAmountStored() << " resources currently stored." << endl;
			}
			else {
				cout << "PowerPlant " << j << " cannot power any cities due to insufficiant resources." << endl;
				cout << "It has " << (*(*i).GetPowerplant(j)).GetAmountStored() << " resources currently stored." << endl;
			}	
		}
		cout << "\n\tPlease enter the amount of cities you want each powerplant to power:\n" << endl;
		for (int j = 0; j < (*i).getNumberOfPowerPlants(); j++) {
			if (citiesToPower == 0)
				break;
			if ((*(*i).GetPowerplant(j)).GetAmountStored() >= (*(*i).GetPowerplant(j)).GetResCost()) {
				do {
					cout << "PowerPlant " << (*(*i).GetPowerplant(j)).GetValue() << " will power: ";
					int amount;
					cin >> amount;
					if (amount >(*(*i).GetPowerplant(j)).GetMaxCitiesPowered()) {
						cout << "PowerPlant " << (*(*i).GetPowerplant(j)).GetValue() << " cannot power that many cities." << endl;
					}
					else if (amount > citiesToPower) {
						cout << "You do not need to power that many cities." << endl;
					}
					else {
						if (amount < 0)
							amount = 0;
						citiesToPower -= amount;
						amountOfCitiesPowered += amount;
						(*(*i).GetPowerplant(j)).AddCities(amount);
						string str = "PowerPlant #" + to_string((*(*i).GetPowerplant(j)).GetValue()) + " will power " + to_string(amount) + " cities.\n";
						str += (*i).getName() + " now powers a total of " + to_string(amountOfCitiesPowered) + " cities and has " + to_string(citiesToPower) + " cities left to power.\n";
						gameLog->updateLog(str, phaseNumber, false, (*i).getColor());
						break;
					}
				} while (true);
			}
		}
		cout << "\n-------------------------------------";

		//consume resources in powerplants powering cities
		//restore resources to market
		for (int j = 0; j < (*i).getNumberOfPowerPlants(); j++) {
			if ((*(*i).GetPowerplant(j)).GetCurrentCitiesPowered() > 0) {
				resourceMarket.RestoreResources((*(*i).GetPowerplant(j)).GetResType(), (*(*i).GetPowerplant(j)).ConsumeResources());
				string res = "";
				switch ((*(*i).GetPowerplant(j)).GetResType()) {
				case 0: res = " coal "; break;
				case 1: res = " oil "; break;
				case 2: res = " garbage "; break;
				case 3: res = " uranium "; break;
				case 4: res = " coal/oil "; break;
				}
				string str = "\nPowerPlant #" + to_string((*(*i).GetPowerplant(j)).GetValue()) + " consumes " + to_string((*(*i).GetPowerplant(j)).GetResCost()) + res;
				str += "to power " + to_string((*(*i).GetPowerplant(j)).GetCurrentCitiesPowered()) + " cities.\n";
				gameLog->updateLog(str, phaseNumber, false, (*i).getColor());
			}
		}
		//pay player
		string str = "\n" + (*i).getName() + " powers " + to_string(amountOfCitiesPowered) + " cities. Therefore, he receives " + to_string(Payment::payment_table[amountOfCitiesPowered]) + " elektros.";
		str += "\n" + (*i).getName() + " had " + to_string((*i).getMoney()) + " and now has " + to_string((*i).getMoney() + Payment::payment_table[amountOfCitiesPowered]) + " elektros.\n";
		gameLog->updateLog(str, phaseNumber, false, (*i).getColor());
		(*i).setMoney(Payment::payment_table[amountOfCitiesPowered]);
		
		(i)->displayPlayerInformation(powerplantmarket_observer);
	}
	//take out highest valued powerplant from market
	//Replenish Market
	resourceMarket.ReplenishMarket(players.size(), stepNumber, gameLog);
	if (stepNumber != 3) {
		powerplantmarket->updateMarket(1, 3, false);
	}
	gameLog->updateLog("\nThis is the end of the bureaucracy phase for turn #" + to_string(turnNumber) + "\n\n\n", phaseNumber, false, "all");
	
	while (true) {
		int choice;
		string color;
		int phase;
		cout << "You can choose to see the log of the game: \nChoose 1 to see all the logs, \n2 to see the log of one player, \n3 to see the logs of one phase, \n4 to see the log of a specific phase for a specific player or \n0 to continue." << endl;
		cin >> choice;
		switch (choice) {
		case 0: break;
		case 1: gameLog_ob->displayLog(); break;
		case 2: gameLog_ob = new GameLog_AllPhase_OnePlayer(gameLog_ob, gameLog);
			cout << "Enter the color of the player you want the log to be displayed: ";
			cin >> color;
			dynamic_cast<GameLog_AllPhase_OnePlayer*>(gameLog_ob)->displayLog(color); break;
		case 3: gameLog_ob = new GameLog_OnePhase_AllPlayer(gameLog_ob, gameLog);
			cout << "Choose the phase you want to display :";
			cin >> phase;
			gameLog_ob->displayLog(phase); break;
		case 4: gameLog_ob = new GameLog_OnePhase_OnePlayer(gameLog_ob, gameLog);
			cout << "Enter the color of the player you want the log to be displayed: ";
			cin >> color;
			cout << "\nChoose the phase you want to display :";
			cin >> phase;
			gameLog_ob->displayLog(phase, color);
		}
		if (choice == 0)
			break;
	}
	gameLog_ob = new GameLog_AllPhase_AllPlayer(gameLog_ob, gameLog);

}


/**
Determine player order in the beginning of every turn based on first how many houses
owned by the player. If there is a tie then we check the powerplant with the
max value.
@return descending order vector<player>
*/

void GameDriver::playerOrder(vector<Player>& players) { //phase1

	string line = "\n---------------------------------------------------------------\n";
	if (turnNumber == 1)
		gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: Player Reorder after phase 2" + line, 1, false, "all");
	else
		gameLog->updateLog(line + "Turn: " + to_string(turnNumber) + "\nPhase: " + to_string(phaseNumber) + line, 1, false, "all");

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

	string str = "\nNew Player Order (First -...- Last):\n ";
	for (vector<Player>::iterator it = players.begin(); it != players.end(); it++) {
		str += (*it).getName() + "  ";
	}
	str += "\n";
	gameLog->updateLog(str, 1, false, "all");
}


//////////////////////////////////////////////////////////
int main() {
	GameDriver* game = new GameDriver();
	delete game;
	game = NULL;
	return 0;
}