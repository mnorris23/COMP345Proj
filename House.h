#pragma once

#include <string>


class House {

private:
	std::string location;

public:
	House() { location = ""; }
	House(std::string l) { location = l; } // constructor that takes in the location of the house
	std::string getLocation() { return location; } // accessor for the location of a House object

};