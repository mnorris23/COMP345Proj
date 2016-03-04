#pragma once


/**
This class describes a Power Plant card
*/
class PowerPlant {
public:
	/**
	Default constructor. Not supposed to be used.
	*/
	PowerPlant();
	/**
	Default destructor
	*/
	~PowerPlant();
	/**
	The main constructor for a Power Plant
	@param val The value of the Power Plant
	@param consume The aumount of resources it consumes
	@param rtype The type of resources it consumes
	@param numCities The number of Cities it can power
	*/
	PowerPlant(int val, int consume, char rtype, int numCities);
	/**
	Method to obtain the value of a Power Plant
	@return The value of the power plant
	*/
	int getValue();
	/**
	Method to set the value of a Power Plant
	@param a The value of the power plant
	*/
	void setValue(int a);
	/**
	Method to obtain the type of resource the power plant consumes
	@return A char representing the type of resource(s)
	*/
	char getResourceType();
	/**
	Method to set the type of resources of a power plant
	@param c A char representing the type of resource(s)
	*/
	void setResourceType(char c);
	/**
	Method to get the number of cities the power plant is able to provide with energy each turn
	@return The number of cities
	*/
	int getNumberOfCities();
	/**
	Method to set the number of cities the power plant can provide in electricity
	@param num The number of cities
	*/
	void setNumberOfCities(int num);
private:
	int value; 				///<The value of the power plant
	char type;				///<The type of resources the power plant consumes
	int consumption;		///<The amount of resources the power plant consumes
	int numberOfResources;	///<The number of resources it currently has
	int numberOfCities;		///<The number of cities it can provide in energy
};