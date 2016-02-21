#ifndef POWERGRID_H
#define POWERGRID_H

#include <string>

class City {
public:
	City();
	City(std::string name);
	~City();
	void setName(std::string name);
	std::string getName();
	int getNextValue();
	void setNextvalue();
	City* getConnectedTo();
	void setConnectedTo(City* a, int b);
	int getConnectionValue();
	void setConnectionValue(int c);
private:
	std::string name;
	int nextValue;
	City* connectedTo[8];
	int connectionValue[8];
	int numberOfConnection;
};

class PowerPlant {
public:
	PowerPlant();
	~PowerPlant();
	PowerPlant(int val, int consume, char rtype, int numCities);
	int getValue();
	void setValue(int a);
	char getResourceType();
	void setResourceType(char c);
	int getNumberOfCities();
	void setNumberOfCities(int num);
private:
	int value;
	char type;
	int consumption;
	int numberOfResources;
	int numberOfCities;
};

class Player {
public:
	Player();
	~Player();
	Player(char c);
	char getColor();
	void setColor(char c);
	std::string getName();
	void setName(std::string name);
	City* getCity();
	void setCity(City* e);
	int getMoney();
	void setMoney(int a);
	PowerPlant* getPowerPlants();
	void setPowerPlant(PowerPlant* plant);
	int getNumberOfCities();
	void setNumberOfCities();
	int getNumberOfPowerPlant();
	void setNumberOfPowerPlant();
private:
	char color;
	std::string name;
	City* cities [24];
	int money;
	PowerPlant* power_plant [3];
	int numberOfCities;
	int numberOfPowerPlant;
};

class SummaryCard {
public:
	SummaryCard();
	~SummaryCard();
	const char* firstPhase();
	const char* secondPhase();
	const char* thirdPhase();
	const char* fourthPhase();
	const char* fifthPhase();
	std::string payment(Player &player);
//private:
	//int payment_table [21];
};

Player* createPlayer();

#endif