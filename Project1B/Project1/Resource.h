//A class that implements the Resource Market in the game
#pragma once;

using namespace std;

struct Resource
{
public:
	//Location of the house, for this assignment, it is represented as a string, but would normally be a pointer to a City object.
	int type;
	int cost;
};