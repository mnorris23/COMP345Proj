#pragma once

#include <string>
#include <iostream>
#include "Player.h"

/**
Basic struct to contain the payment table
*/
struct Payment {
	static const unsigned int payment_table[21];
};


/**
Class to display the relevant information about the different phases of the game
*/
class SummaryCard {
public:
	/**
	Default constructor
	*/
	SummaryCard();
	/**
	Default destructor
	*/
	~SummaryCard();
	/**
	Details of the first phase of a turn
	@return A string
	*/
	const char* firstPhase();
	/**
	Details of the second phase of a turn
	@return A string
	*/
	const char* secondPhase();
	/**
	Details of the third phase of a turn
	@return A string
	*/
	const char* thirdPhase();
	/**
	Details of the fourth phase of a turn
	@return A string
	*/
	const char* fourthPhase();
	/**
	Details of the fifth phase of a turn
	@return A string
	*/
	const char* fifthPhase();
	/**
	Method to combine the information about all the phases of the game.
	@return A string
	*/
	std::string allPhases();
	/**
	Method to create a string to display the amount of money the player will receive on the fifth phase of the game given the number of cities he currently has
	@param player The player
	@return A string
	*/
	std::string payment(Player player);
};


