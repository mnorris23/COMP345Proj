#pragma once

#include "Player.h"
#include <vector>

/**
Class with only purpose is to contain a vector with all the players
*/
class PlayerVector {
public:
	/**
	Default constructor set the size of the vector to 2
	*/
	PlayerVector();
	/**
	Main constructor set the size of the vector given by the parameter
	@param size The size of the vector
	*/
	PlayerVector(int size);
	/**
	Default destructor
	*/
	~PlayerVector();
	/**
	Method to get to a specific player in the vector
	@param index The position of the player in the vector
	@return A player
	*/
	Player getPlayer(int index);
	/**
	Method to add a player to the vector
	@param p The player to add
	@param i The position of the player
	*/
	void setPlayer(Player p, int i);
private:
	int size;				///< The size of the vector of players
	std::vector<Player> arrayPlayer;	///< The vector of players
};
