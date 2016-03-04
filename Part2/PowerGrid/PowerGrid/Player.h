#pragma once

#include "City.h"
#include "PowerPlant.h"
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
	Player(std::string name, int color);
	/**
	Another constructor. Not really used
	@param name The name of the player
	*/
	Player(std::string name);
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
	/**
	Method to obtain the list of cities the player has a house on
	@return An pointer to an array of cities
	*/
	City* getCity();
	/**
	Method to add a City to the list of cities the player has a house on
	@param e The city to add to the array
	*/
	void setCity(City* e);
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
	Method to get the array of power plant the player currently owns
	@return The array of power plant
	*/
	PowerPlant* getPowerPlants();
	/**
	Method to add a power plant to the array of a player
	@param plant The power plant to be added to the player
	*/
	void setPowerPlant(PowerPlant* plant);
	/**
	Method to get the number of cities the player has currently a house on.
	@return The number of cities owned
	*/
	int getNumberOfCities();
	/**
	Method to increment the number of cities owned by a player by one
	*/
	void setNumberOfCities();
	/**
	Method to get the number of power plant the player has .
	@return The number of power plant owned
	*/
	int getNumberOfPowerPlant();
	/**
	Method to increment the number of power plant owned by a player by one
	*/
	void setNumberOfPowerPlant();
	/**
	Method to obtain all the relevant information about the possession of a player
	@return The name of the player, the number of cities he owns, the money he has, the power plant he owns
	*/
	std::string getPlayerInformation();
private:

	std::string color; 		///< The color of the player
	std::string name;		///< The name of the player
	City* cities[24];		///< The array of cities the player owns
	int money;				///< The amount of money the player has
	PowerPlant* power_plant[3];	///< The array of power plant the player owns
	int numberOfCities;			///< The number of cities the player owns
	int numberOfPowerPlant;		///< The number of power plant the player owns
};
