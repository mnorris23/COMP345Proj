#pragma once

#include "ResourceMarket.h"
#include "ResourceMarket_Observer.h"
#include "Map.h"
#include "MapView.h"
#include "Player.h"
#include "House.h"
#include "PowerPlantMarket_Observer.h"
#include "PowerPlantMarket.h"
#include "GameLog_Subject.h"
#include "GameLog_Observer.h"
#include "GameLog_AllPhase_AllPlayer.h"
#include "GameLog_AllPhase_OnePlayer.h"
#include "GameLog_OnePhase_AllPlayer.h"
#include "GameLog_OnePhase_OnePlayer.h"
#include "pugixml.hpp"

#include <vector>
#include <string>



class GameDriver {
private:
	//The Resource Market for the game
	ResourceMarket* resourceMarket;
	//Resource Market Observer;
	ResourceMarket_Observer *resourceMarketObserver;
	//A vector holding the players of the game
	std::vector<Player> players;
	//Power Plant Market Observable
	PowerPlantMarket *powerplantmarket;
	//Power Plant Market Observer;
	PowerPlantMarket_Observer *powerplantmarket_observer;
	//Game Log Observable
	GameLog_Subject *gameLog;
	//Game Log Observer
	GameLog_Observer *gameLog_ob;
	//Phase1 Method
	void Phase2();
	void Phase2Step3();
	void Phase3();
	//void Phase4();
	void Phase5();
	//Phase2 method
	//creates a vector of players for a new game
	vector<Player> newGame();

	void Auction(int row, int col);
	int bid(int index, int _higgestBid);

	Map brazil;
	MapView *mView;
	
	int phaseNumber;
	int winningNumberOfCities;
	int numberOfCitiesToPhase2;
	int stepNumber;
	int turnNumber;

public:


	//Empty Constructor
	GameDriver();
	void createResourceMarket(pugi::xml_node doc);
	vector<int> createResourceSupply(pugi::xml_node doc);
	//Empty Destructor
	~GameDriver();
	//Initializes the game
	//pugi::xml_document initGame();
	//Method that runs through a turn of the game
	void playTurn(pugi::xml_document&);
	void playerOrder(vector<Player>& players);
	void saveGame(pugi::xml_node);
	bool saveGameOption(pugi::xml_document&);
	vector<Player> loadPlayers(pugi::xml_node);
};