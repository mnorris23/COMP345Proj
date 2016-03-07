#pragma once

#include <string>


class PPlant {

private:
	std::string fuelType; // the fuel the plant requires
	const int lowestBid; // lowest acceptable bid for the plant
	const int fuelConsumption; // fuel units consumed per round
	const int maxFuelSupply; // maximum number of fuel units that can be stored in the plant
	const int powersNumbCities; // number of cities powered
	int amountOfFuel; // the amount of fuel units currently stored in the plant

public:
	PPlant() : lowestBid(0), fuelConsumption(0), maxFuelSupply(0), powersNumbCities(0) { 
		fuelType = "";
		amountOfFuel = 0;
	}
	PPlant(std::string ft, int lb, int fc, int pnc) :lowestBid(lb), fuelConsumption(fc), maxFuelSupply(fc * 2), powersNumbCities(pnc) { // constructor
		fuelType = ft;
		amountOfFuel = 0;
	}
	std::string getFuelType() { return fuelType; } // accessor for the fuelType
	int getLowestBid() const { return lowestBid; } // accessor for the lowestBid
	int getFuelConsumption() const { return fuelConsumption; } // accessor for the fuelConsumption
	int getMaxFuelSupply() const { return maxFuelSupply; } // accessor for the maxFuelSupply
	int getPowersNumbCities() const { return powersNumbCities; } // accessor for the powersNumbCities
	int getAmountOfFuel() { return amountOfFuel; } // accessor for the amountOfFuel
	void setAmountOfFuel(int af) { amountOfFuel = af;} // mutator for the amountOfFuel

};