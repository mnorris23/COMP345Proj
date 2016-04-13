#pragma once

#include "House.h"
#include "PowerPlantMarket.h"
#include "PowerPlantMarket_Observer.h"
#include "SummaryCard.h"
#include <string>
#include <sstream>

/**
This class describes all the possessions of a player
*/
class Player {
public:
	/**
	The main constructor for a player
	@param name The name of the player
	@param color The color of the player
	*/
	Player(std::string name, int color, int maxNumberOfPplants);
	/**
	Another constructor. Not really used
	@param name The name of the player
	*/
	Player(std::string name, int maxNumberOfPplants);

	Player(std::string name, std::string color, int maxNumberOfPplants);

	Player(std::string name, int color, int money, int maxNumberOfPplants);

	Player(std::string name, std::string color, int money, int maxNumberOfPplants);

	/**
	The default constructor. Not used.
	*/
	Player();
	/**
	The defautlt destructor.
	*/
	~Player();
	/**
	Method to get the color of a player
	@return The color of the player
	*/
	std::string getColor();
	/**
	Method to set the color of a player
	@param c The color of the player
	*/
	void setColor(std::string c);
	/**
	Method to get the name of the player
	@return The name of the player
	*/
	std::string getName();
	/**
	Method to set the name of the player
	@param name The name of the player
	*/
	void setName(std::string name);

	//A method to add a house to the player's possessions
	bool AddHouse(House house, int cost);

	// used only for loading from file and adding a house to a player
	void AddHouse(House house);

	//A method to add a powerplant to the player's possessions
	bool AddPowerplant(PowerPlantMarket::PowerPlant powerplant, int cost);

	//Returns a pointer to a house owned by the player
	House* GetHouse(int index);

	//Returns a pointer to a powerplant owned by the player
	PowerPlantMarket::PowerPlant* GetPowerplant(int index);


	bool SwapResource(int index1, int index2, int type, int amount);

	//A method that adds a specified number of resources, of a specified type, to a powerplant specified by index, at a specific cost 
	bool AddResources(int index, int type, int amount, int totalCost);
	/**
	Method to get the amount of money the player has
	@return The amount of money
	*/
	int getMoney();
	/**
	Method to increment or decrement the money a player has
	@param a The value to increment of decrement
	*/
	void setMoney(int a);

	/**
	Method to get the number of cities the player has currently a house on.
	@return The number of cities owned
	*/
	int getNumberOfHouses();
	/**
	Method to increment the number of cities owned by a player by one
	*/
	void setNumberOfHouses();
	//Max Number of powerplants
	int maxNumberOfPowerplants;
	/**
	Method to get the number of power plant the player has .
	@return The number of power plant owned
	*/
	int getNumberOfPowerPlants();
	/**
	Method to increment the number of power plant owned by a player by one
	*/
	void setNumberOfPowerPlants();
	/**
	Method to obtain all the relevant information about the possession of a player
	@return The name of the player, the number of cities he owns, the money he has, the power plant he owns
	*/
	void displayPlayerInformation(PowerPlantMarket_Observer*);
	void DisplayPowerplant(PowerPlantMarket::PowerPlant powerplant);
	//Method to get how much the player is to be payed
	std::string getPayment();
	//Method to get the highest value out of the player's powerplants.
	int getMaxValuePowerplant();

	bool canBid;
	bool canBidForAuction;
private:
	//An array containing the houses owned by the player
	House _houses[24];
	//An array containing the powerplants owned by the player
	PowerPlantMarket::PowerPlant _powerplants[4];

	std::string color; 		///< The color of the player
	std::string name;		///< The name of the player

	int money;				///< The amount of money the player has

	int numberOfHouses;			///< The number of cities the player owns
	int numberOfPowerPlant;		///< The number of power plant the player owns

	SummaryCard* summaryCard; //A pointer to the summary card for the player
};
