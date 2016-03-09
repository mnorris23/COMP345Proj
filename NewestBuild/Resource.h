//A struct that implements the Resource Market in the game
#pragma once

using namespace std;

struct Resource
{
public:
	//The type of the resource (0 is coal, 1 is oil, 2 is garbage, 3 is uranium)
	int type;
	//The cost of the resource
	int cost;
};