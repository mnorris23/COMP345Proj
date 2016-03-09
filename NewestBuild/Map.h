#pragma once

#include "Player.h"
#include "pugixml.hpp"

#include <string>
#include <vector>
#include <iostream>

class Map {

	class Connection;
	class City;
	std::vector<City> cities;
	static int numbOfVertices;
	std::vector<Player*> playerOrder;


	class City {
		std::string cityName; // the city name
		std::string color; // the color of the region that the city is in
		int cityNumb;
		double x, y; // x and y coordinates of te city
		std::vector<Connection> adjCities; // the connecting cities
		int numbOfAdjCities; // number of adjacent cities
		Player* occupants[3]; // array of pointers to Player objects of players that have a house in this city, 0 corresponding to the first occupant, 3 to the last one

	public:
		City() {} // default constructor
		City(std::string, std::string, double, double);

		// accessors
		std::string getCityName() { return cityName; }
		std::string getColor() { return color; }
		int getCityNumb() { return cityNumb; }
		double getX() { return x; }
		double getY() { return y; }
		int getNumbOfAdjCities() { return numbOfAdjCities; }
		std::vector<Connection> getAdjCities() { return adjCities; }

		// mutators
		void setColor(std::string co) { color = co; }
		void setX(double xCoord) { x = xCoord; }
		void setY(double yCoord) { y = yCoord; }

		void addConnectingCity(int c, City* v) { // add a connecting city to the vector adjCities which takes in a cost and a pointer to the connecting city
			Connection con(c, v);
			adjCities.push_back(con);
			++numbOfAdjCities;
			//std::cout << "\t\tConnection added!\n";
		}
	};

	class Connection {
		int cost; // the cost of the connection
		City* city; // pointer to the connecting City

	public:
		Connection() {} // default constructor
		Connection(int c, City *ci) { // constructor that takes in an int for the cost of the connection and a pointer to the connecting city
			cost = c;
			city = ci;
		}
		int getCost() const { return cost; } // accessor for int cost
		City* getCity() const { return city; } // accessor for the pointer to the Vertex vect
	};

public:

	Map() {};
	void createMap(pugi::xml_node);
	void printMap();
	void saveMap(std::vector<Player>, pugi::xml_node);
	int shortestDistance(std::string, std::string);
	void DijkstraComputePaths(City, std::vector<int>&, std::vector<int>&);
};