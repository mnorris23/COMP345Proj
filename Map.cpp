#include "Map.h"
#include "pugixml.hpp"

#include <fstream>
#include <iostream>
#include <set>
#include <utility> // for pair
#include <iterator>
#include <list>
#include <queue>
#include <functional>

using namespace std;

int Map::numbOfVertices = 0;



Map::City::City(std::string cn, std::string co, double xCoord, double yCoord) { // constructor that takes in a string for cityName, a string for color and two doubles for the coordinates
	cityName = cn;
	color = co;
	x = xCoord;
	y = yCoord;
	numbOfAdjCities = 0;
	cityNumb = numbOfVertices++; // each city gets a corresponding number assigned to it
}

void Map::createMap(pugi::xml_node doc) { 

	pugi::xml_node map = doc.child("map");
	pugi::xml_node region = map.child("region");

	for (pugi::xml_node currentRegion = region; currentRegion; currentRegion = currentRegion.next_sibling()) { // looping through all the regions on the map
		string regionColor = currentRegion.child("color").child_value(); // parsing out the region color

		for (pugi::xml_node currentCity = currentRegion.child("city"); currentCity; currentCity = currentCity.next_sibling()) { // looping through all the cities of a region
			string cityName = currentCity.child("name").child_value(); // parsing out the city name
			double x = stod(currentCity.child("coordinates").child("x").child_value()); // parsing out the x coordinate
			double y = stod(currentCity.child("coordinates").child("y").child_value()); // parsing out the y coordinate
			City city(cityName, regionColor, x, y); // a new city is created
			cities.push_back(city); // the city is added to the cities vector
		}
	}

	int i = 0;
	for (pugi::xml_node currentRegion = region; currentRegion; currentRegion = currentRegion.next_sibling()) { // looping through all the regions on the map
		
		pugi::xml_node currentCity;
		for (currentCity = currentRegion.child("city"), i; currentCity; currentCity = currentCity.next_sibling(), ++i) { // looping through all the cities of a region
			string cityName = currentCity.child("name").child_value(); // parsing out the city name

			City &c = cities[i]; // storing a reference of the current city
			for (pugi::xml_node currentConnection = currentCity.child("adjacentCities").child("connection"); currentConnection; currentConnection = currentConnection.next_sibling()) { // looping through all the adjacent cities of the current city
				string connectionName = currentConnection.child("to").child_value(); // parsing out the adjacent city name
				int cost = stoi(currentConnection.child("cost").child_value()); // parsing out the cost between the 2 cities

				for (vector<City>::iterator it = cities.begin(); it != cities.end(); ++it) { // using an iterator to loop through all the cities
					if (((*it).getCityName()).compare(connectionName) == 0) { // finding a match to the city name
						City& conCity = *it;
						c.addConnectingCity(cost, &conCity); // adding a connecting city with a pointer
						break;
					}
							
				}
			}

		}
	}	
}


void Map::printMap() { // prints out all the contents of the map, cities and their connections
	for (vector<City>::iterator it = cities.begin(); it != cities.end(); ++it) {
		City &current = *it;
		cout << "The city " << current.getCityName() <<" (" << current.getCityNumb() << ") is located at (" << current.getX() << ", " << it->getY() << ") and has " << current.getNumbOfAdjCities() << " adjacent cities:\n" << endl;
		vector<Connection> currentConnections = current.getAdjCities();
		for (vector<Connection>::iterator it2 = currentConnections.begin(); it2 != currentConnections.end(); ++it2) { 
			Connection currentConnection = *it2;
			City* adjCity = currentConnection.getCity();
			cout << "\tIt would cost " << (*it2).getCost() << " elektros to get to " << (*adjCity).getCityName() << ".\n";
		} 
	}
}

void Map::saveMap(vector<Player> players, pugi::xml_node node) {
	int numbOfPlayers= players.size();
	
	pugi::xml_node player;
	for (int i = 0; i < numbOfPlayers - 2; i++) { // if there are more than 2 players, then the xml file is extended to be able to store those players' data
		player = node.child("players"); // adding xml elements to add player's info
		player.append_copy(player.first_child());
		player = node.child("playerOrder"); // adding xml elements to add the player order slot
		player.append_copy(player.first_child());
	}

	for (player = node.child("scoringTrack").child("position"); player; player = player.next_sibling()) { 
		for (int i = 0; i < numbOfPlayers - 2; i++) { // if there are more than 2 players, then the scoringTrack is extended to accomodate those players
			player.append_child(pugi::node_element).set_name("spot");
		}	
	}

	vector<Player>::iterator it;
	for (player = node.child("playerOrder").child("order"), it = players.begin(); it != players.end(); player = player.next_sibling(), ++it) { // adding player names to the player order section
			string playerName = (*it).getPname();
			const char* pN = playerName.c_str();
			player.append_child(pugi::node_pcdata).set_value(pN);
	}

	for (player = node.child("players").child("player"), it = players.begin(); it != players.end(); player = player.next_sibling(), ++it) { // adding player info into the players section
		string playerName = (*it).getPname();
		string playerColor = (*it).getColor();
		string elektros = to_string((*it).getElektros());
		
		//vector<House> house = (*it).getHouses();
		//int numberOfHouses = (*it).getNumbOfHouses();
		//for (pugi::xml_node houseNode = player.child("houses"); houseNode; houseNode = house

		const char* pN = playerName.c_str();
		const char* pC = playerColor.c_str();
		const char* el = elektros.c_str();
		player.child("name").append_child(pugi::node_pcdata).set_value(pN);
		player.child("color").append_child(pugi::node_pcdata).set_value(pC);
		player.child("elektros").append_child(pugi::node_pcdata).set_value(el);
	}

	for (player = node.child("scoringTrack").child("position").child("spot"), it = players.begin(); it != players.end(); player = player.next_sibling(), ++it) { // adding player names to the scoring track section
		string playerName = (*it).getPname();
		const char* pN = playerName.c_str();
		player.append_child(pugi::node_pcdata).set_value(pN);
	}
}

// takes 2 city names (from -> to)
int Map::shortestDistance(string fromCityName, string toCityName) {
	City c;
	int toCityNumb;
	for (vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
		if (fromCityName.compare((*it).getCityName()) == 0)
			c = *it;
		if (toCityName.compare((*it).getCityName()) == 0)
			toCityNumb = (*it).getCityNumb();
	}
	vector<int> min_cost;
	vector<int> previous;
	DijkstraComputePaths(c, min_cost, previous);
	return min_cost[toCityNumb];
}

typedef pair<int, int> cost_cityNumb_pair; // pair of the COST leading to a CITY_NUMBER

void Map::DijkstraComputePaths(City source, vector<int> &min_cost, vector<int> &previous) {
	
	
	int n = cities.size(); // number of cities
	min_cost.clear(); // clear because pass by reference 
	min_cost.resize(n, 99999999); // set all min_cost to a large number
	min_cost[source.getCityNumb()] = 0; // min_cost of starting city is 0
	previous.clear();
	previous.resize(n, -1); // set all previous city numbers to -1
	int cityNumber = source.getCityNumb();

	// creating a priority queue of pairs (cost, cityNumb)
	std::priority_queue<cost_cityNumb_pair, vector<cost_cityNumb_pair>, greater<cost_cityNumb_pair> > city_queue;
	city_queue.push( make_pair(min_cost[cityNumber], cityNumber) );

	while (!city_queue.empty()) {

		int dist = city_queue.top().first; //
		int u = city_queue.top().second;
		city_queue.pop(); // pop the pair

		
		/*if (dist > min_cost[u])
			continue;*/

		
		for (vector<City>::iterator it = cities.begin(); it != cities.end(); it++) { // finding the city Object with the same cityNumber as u
			if ((*it).getCityNumb() == u)
				source = *it;
		}

		// Visiting each connection exiting the source (u is the source cityNumb)
		const vector<Connection> &connections = source.getAdjCities(); 
		for (vector<Connection>::const_iterator iter = connections.begin(); iter != connections.end(); iter++) {
			
			Connection currentConnection = *iter;
			City* adjCity = currentConnection.getCity();
			int v = (*adjCity).getCityNumb(); // the connecting city number
			int weight = currentConnection.getCost(); // the connection cost (weight)

			int cost_through_u = dist + weight; // total cost going through the city u
			
			if (cost_through_u < min_cost[v]) { // if this cost through u is smaller than the current smallest cost to get to city v, then replace it
				min_cost[v] = cost_through_u;
				previous[v] = u; // update the previous city
				city_queue.push(make_pair(min_cost[v], v)); // push the pair inside the queue
			}
		}
	}
}
