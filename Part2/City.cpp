#include "powergrid.h"

City::City() {
	nextValue = 10;
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
