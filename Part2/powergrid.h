#ifndef POWERGRID_H
#define POWERGRID_H

class City {
public:
	City();
	int getNextValue();
	void setNextvalue();
	City* getConnectedTo();
	void setConnectedTo(City* a, int b);
	int getConnectionValue();
	void setConnectionValue(int c);
private:
	int nextValue;
	City* connectedTo[8];
	int connectionValue[8];
	int numberOfConnection;
};

class PowerPlant {
public:
	PowerPlant();
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
	Player(char c);
	char getColor();
	void setColor(char c);
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
	City* cities [24];
	int money;
	PowerPlant* power_plant [3];
	int numberOfCities;
	int numberOfPowerPlant;
};

Player* createPlayer();

#endif