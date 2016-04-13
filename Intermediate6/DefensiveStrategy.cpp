#include "DefensiveStrategy.h"

Defensive::Defensive(Player *p1) {

	execute(p1);

}


void Defensive::execute(Player *p1) {
	Map m;
	//defensive: never power unless the player owned a city for which all adjacent houses are his/hers

	//display the amount of houses (cities)
	//display the amount that can be powered by each powerplant of the player
	//determine number of houses to power base don strategy

	int citiesToPower = p1->getNumberOfHouses();
	int amountOfCitiesPowered = 0;
	p1->displayPlayerInformation();

	cout << "\n-------------------------------------";
	cout << "\nPlayer " << p1->getName() << " has " << citiesToPower << " cities he needs to power." << endl;

	for (int j = 0; j < p1->getNumberOfPowerPlants(); j++) {
		if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost()) {
			cout << "PowerPlant " << p1->GetPowerplant(j)->GetValue() << " can power " << p1->GetPowerplant(j)->GetMaxCitiesPowered() << " cities." << endl;
			cout << "It has " << p1->GetPowerplant(j)->GetAmountStored() << " resources currently stored." << endl;
		}
		else {
			cout << "PowerPlant " << j << " cannot power any cities due to insufficiant resources." << endl;
			cout << "It has " << p1->GetPowerplant(j)->GetAmountStored() << " resources currently stored." << endl;
		}
	}

	cout << "\n\tDetermining the number of houses to power based on a defensive strategy:\n" << endl;

	for (int j = 0; j < p1->getNumberOfPowerPlants(); j++) {

		int amount = 0;
		bool surr = false;

		if (citiesToPower == 0)
			break;

		if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost()) {

			cout << "PowerPlant " << p1->GetPowerplant(j)->GetValue() << " will power: ";

			//determine number of houses to power, defensive
			//never power unless the player owns a city for which all adjacent houses are his/hers

			for (vector<Map::City>::iterator i = m.cities.begin(); i < m.cities.end(); i++) {  //random traversal so houses purchased are not all on same city
				for (vector<Map::Connection>::iterator q = (*i).getAdjCities().begin(); q < (*i).getAdjCities().end(); q++) {			//for adjCities get city then occupants
					for (int k = 0; k < 3; k++)
						if (((*(*q).getCity()).getOccupants(k)) == p1) {			//if adj city has a house owned by the player
							surr = true;
							break;
						}
						else {
							surr = false;
						}
				}
				if (surr)
					if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost())
						for (int k = 0; k < 3; k++)
							if ((*i).getOccupants(k) == NULL)
								(*i).addOccupant(p1);		//purchase house, create occupancy	
				amount++;
			}

			cout << amount;
			citiesToPower -= amount;
			amountOfCitiesPowered += amount;
			p1->GetPowerplant(j)->AddCities(amount);
			cout << "PowerPlant " << p1->GetPowerplant(j)->GetValue() << " will power " << amount << " cities." << endl;
		}
	}

	cout << "\n-------------------------------------";

}