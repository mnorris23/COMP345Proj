#pragma once

#include <vector>
#include <string>
#include "Observable.h"
#include "pugixml.hpp"

/*
Class for the market of power plant. It is also the outer class for the class powerplant.
This is the observable class by the observer class PowerPlant_Observer. 
*/

class PowerPlantMarket : public Observable {

private:
	
	//A class for the powerplant cards in the game. It is a private inner class of PowerPlantMarket, but
	//it can be accessed by the Player class, as well as the PowerPlantMarket_Observer.
	class PowerPlant {
	private:
		//initial value
		int _value;
		//the maximum amount of cities it can power
		int _maxCitiesPowered;
		//the amount of resources it costs to run it
		int _resCost;
		//the current amount of cities powered by the powerplant
		int _citiesPowered;
		//the number of resources stored on the card.
		int _resStored[4];
		//the type(s) of resource(s) used by the powerplant. 1 is coal, 2 is oil, 3 is garbage, 4 is uranium and 5 is coal AND oil. Anything else means the powerplant doesnt use resources.
		int _resType;
		//Initializes the initial values of some variables
		void initValues();

	public:
		//empty constructor
		PowerPlant();
		//a constructor to build the card
		PowerPlant(int value, int maxCitiesPowered, int resCost, int resType);

		//returns the value of the powerplant
		int GetValue();
		//returns the maximum amount of cities powered
		int GetMaxCitiesPowered();
		int GetCurrentCitiesPowered();
		//returns the resource cost of the powerplant
		int GetResCost();
		//returns the type of resource used by the powerplant
		int GetResType();
		//Get the amount of resources currently stored
		int GetAmountStored();
		//Accesses the resources at specified index
		//Resource* GetResStoredAt(int index);



		//returns the available space for resources
		//The total available space is the amount in resource cost *2 minus the resources already stored
		int GetStorageSpace();



		//adds a number of cities to be powered by the powerplant 
		bool AddCities(int cities);

		//removes a number of cities being powered
		bool RemoveCities(int cities);

		//Stores an amount of resources of a certain type on the card
		bool StoreResource(int type, int amount);
		//Removes the resource from the powerplant without consuming anything
		bool RemoveResource(int type, int amount);

		//Consumes the amount of resources needed (if they have been previously stored on the card
		int ConsumeResources();
		//Consumes the resources of a certain type
		int ConsumeResources(int type, int amountToConsume);

		

	};

	//2d array of power plants representing present and future market 
	PowerPlant** market;
	//array for the power plant market in step 3
	PowerPlant* marketStep3[6];
	//Deck of all powerplant to draw
	std::vector<PowerPlant> deck;
	//Initial vector of powerplants when loaded from the xml file. When randomly ordered, will become the deck
	std::vector<PowerPlant> powerplants;

	//load all the plants from the xml file
	void createPowerPlantMarket(pugi::xml_node doc);
	void initDeck();
	void buildMarkets();
	void reorderMarket();
	
	//Class that need direct access to a powerplant object
	friend class Player;
	friend class PowerPlantMarket_Observer;
	friend class GameDriver;

public:
	PowerPlantMarket();
	PowerPlantMarket(pugi::xml_node doc);
	~PowerPlantMarket();

	//Method that will notify the observer.
	bool updateMarket(int, int, bool);
	//Return powerplant object for class that are friend
	PowerPlantMarket::PowerPlant getPowerPlant(int, int);
	PowerPlantMarket::PowerPlant getPowerPlant(int);
	void removeBiggestValued();
	//Create powerplant market for step 3
	void createMarketStep3();
	//Update market for step 3
	void updateMarketStep3(int);

	
	PowerPlantMarket::PowerPlant** getMarket() { return market; };
	
	std::vector<PowerPlantMarket::PowerPlant> getDeck() { return deck; };
};