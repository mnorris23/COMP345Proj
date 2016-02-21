#include "powergrid.h"
//#include <string>
using namespace std;

City::City() {
	nextValue = 10;
	name = "unknown";
}

City::City(string aname) {
	nextValue = 10;
	name = aname;
}

City::~City() {
	
}

void City::setName(string aname) {
	name = aname;
}

string City::getName() {
	return name;
}

int City::getNextValue() {
	return nextValue;
}

void City::setNextvalue() {
	nextValue = nextValue + 5;
}

City* City::getConnectedTo() {
	return connectedTo[0];
}

void City::setConnectedTo(City* a, int b) {
	connectedTo[numberOfConnection] = a;
	setConnectionValue(b);
	numberOfConnection++;
}

int City::getConnectionValue() {
	return connectionValue[0];
}

void City::setConnectionValue(int b) {
	connectionValue[numberOfConnection] = b;
}
