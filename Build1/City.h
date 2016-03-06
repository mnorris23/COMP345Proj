#pragma once

#include <string>
#include <vector>

/** This class describes a City on the board.

*/
class City {
public:
	/**
	Default Constructor for a City. Not supposed to be used.
	*/
	City();
	/**
	Constructor Of a City for a City
	@param name The name of the city
	*/
	City(std::string name);
	/**
	Default destructor
	*/
	~City();
	/**
	A setter method to set the name of a City.
	@param name The name of the City
	*/
	void setName(std::string name);
	/**
	A getter method for the name of a City.
	@return The name of a City
	*/
	std::string getName();
	/**
	A getter for the value to build a house on the City
	@return An int
	*/
	int getNextValue();
	/**
	Method will increment the value to build a house on the City by 5.
	*/
	void setNextvalue();
	/**
	Method to obtain the list of all cities connected to this City
	@return A vector of Cities
	*/
	std::vector<City> getConnectedTo();
	/**
	Add a city connection
	@param a The city to be connected with
	@param b The value of the connection
	*/
	void setConnectedTo(City a, int b);
	/**
	Get the list of values of connection with other cities
	@return A vector of int values
	*/
	std::vector<int> getConnectionValue();
	/**
	Set the value of a connection with a city
	Index is the same as vector connectedTo
	@param c The value of the connection
	*/
	void setConnectionValue(int c);
private:
	std::string name; 	///<The name of the City
	int nextValue;		///<The value to build a house on the City
	std::vector<City> connectedTo;		///<A Vector of Cities with which the city is connected to
	std::vector<int> connectionValue;	///<A Vector of Values for the connection with a city
};
