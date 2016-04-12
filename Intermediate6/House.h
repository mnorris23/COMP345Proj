//A struct that implements the houses in the game
#pragma once
using namespace std;
#include <string>
//A struct used to symbolize the houses in the game
struct House
{
public:
	//Location of the house, for this assignment, it is represented as a string, but would normally be a pointer to a City object.
	std::string location;

};