#include "MapView.h"

#include <iostream>

using namespace std;

MapView::MapView() { };

MapView::MapView(Map* m) {
	map = m;
	map->Attach(this);
}

MapView::~MapView() {
	map->Detach(this);
}

void MapView::Update() {
	printMap();
}

void MapView::printMap() { // displays all info about the current status of the map
	cout << "\n-------------------------------------------------------------------------------";
	cout << "\n\t\tMap of Brazil\n";
	for (vector<Map::City>::iterator it = map->cities.begin(); it != map->cities.end(); ++it) {
		Map::City current = *it;
		cout << "\nThe city " << current.getCityName() << " (" << current.getCityNumb() << ") is located at (" << current.getX() << ", " << it->getY() << ") in the " << current.getColor() << " region and has " << it->getNumbOfOccupants() << " houses in it.\n";
		if (current.getNumbOfOccupants() > 0) {
			Player* p = current.getOccupants();
			for (int i = 0; i < current.getNumbOfOccupants(); i++) {
				p = p + i;
				cout << "Occupant " << i + 1 << " is " << (*p).getName() << ".\n";
			}
		}
		cout << "It is connected to " << current.getNumbOfAdjCities() << " adjacent cities:\n" << endl;
		vector<Map::Connection> currentConnections = current.getAdjCities();
		for (vector<Map::Connection>::iterator it2 = currentConnections.begin(); it2 != currentConnections.end(); ++it2) {
			Map::Connection currentConnection = *it2;
			Map::City* adjCity = currentConnection.getCity();
			cout << "\tIt would cost " << (*it2).getCost() << " elektros to get to " << (*adjCity).getCityName() << ".\n";
		}
	}
	cout << "-------------------------------------------------------------------------------";
}
