#include "powergrid.h"


PowerPlant::PowerPlant() {
	value = 5;
	type = 'n';
	consumption = 2;
	numberOfResources = 0;
	numberOfCities = 1;
}

PowerPlant::PowerPlant(int val, int consume, char rtype, int numCities) {
	value = val;
	type = rtype;
	consumption = consume;
	numberOfResources = 0;
	numberOfCities = numCities;
}

int PowerPlant::getValue() {
	return value;
}

void PowerPlant::setValue(int val) {
	value = val;
}

char PowerPlant::getResourceType() {
	return type;
}

void PowerPlant::setResourceType(char rtype) {
	type = rtype;
}

int PowerPlant::getNumberOfCities() {
	return numberOfCities;
}

void PowerPlant::setNumberOfCities(int num) {
	numberOfCities = num;
}

