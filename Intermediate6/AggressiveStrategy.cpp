#include "AggressiveStrategy.h"

Aggressive::Aggressive(Player *p1) {

	execute(p1);

}


void Aggressive::execute(Player *p1) {
	Map m;
	//aggressive: always choose a power plant for action if the player own a city that has one adjacent opponent city with less powered houses

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

	cout << "\n\tDetermining the number of houses to power based on an aggressive strategy:\n" << endl;

	for (int j = 0; j < p1->getNumberOfPowerPlants(); j++) {

		int amount = 0;
		int oppH = 0;
		int myH = 0;

		if (citiesToPower == 0)
			break;

		if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost()) {

			cout << "PowerPlant " << p1->GetPowerplant(j)->GetValue() << " will power: ";

			//determine number of houses to power, aggressive
			//aggressive: always choose a power plant for action if the player own a city that has one adjacent opponent city with less powered houses

			//for each city with one or more powered houses, 
			//put another house unless there is an adjacent city with more oppponent powered houses

			for (vector<Map::City>::iterator i = m.cities.begin(); i < m.cities.end(); i++) {  //random traversal so houses purchased are not all on same city
				for (int k = 0; k < 3; k++)
					if (p1 == (*i).getOccupants(k))
						myH++;			//number of houses owned by player in this city
				for (vector<Map::Connection>::iterator j = ((*i).getAdjCities()).begin(); j < ((*i).getAdjCities()).end(); j++)			//chnaged to () . end()
					for (int k = 0; k<3; k++)
						if ((*(*j).getCity()).getOccupants(k) != NULL)
							if (p1 != (*(*j).getCity()).getOccupants(k))
								oppH++;		//number of houses owned by an opponent in this city
				if (myH>oppH)			//aggressive, if player owns more than another player in an adjacent city
					if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost())
						for (int k = 0; k < 3; k++)
							if ((*i).getOccupants(k) == NULL) {
								(*i).addOccupant(p1);		//purchase house, create occupancy
								amount++;
							}
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