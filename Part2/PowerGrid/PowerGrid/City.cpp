#include "powergrid.h"
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

vector<City> City::getConnectedTo() {
	return connectedTo;
}

void City::setConnectedTo(City a, int b) {
	connectedTo.push_back(a);
	setConnectionValue(b);
}

vector<int> City::getConnectionValue() {
	return connectionValue;
}

void City::setConnectionValue(int b) {
	connectionValue.push_back(b);
}
