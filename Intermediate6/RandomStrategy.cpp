
#include "RandomStrategy.h"

Random::Random(Player *p1) {

	execute(p1);

}


void Random::execute(Player *p1) {
	Map m;
	//random: randomly choose between powering houses or not, then if powering, choose a random valid target house
	int random1 = rand() % 10 + 1;
	int random2 = rand() % 10 + 1;

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

	cout << "\n\tDetermining the number of houses to power based on a random strategy:\n" << endl;

	for (int j = 0; j < p1->getNumberOfPowerPlants(); j++) {

		int amount = 0;
		bool surr = true;

		if (citiesToPower == 0)
			break;

		if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost()) {

			cout << "PowerPlant " << p1->GetPowerplant(j)->GetValue() << " will power: ";

			//determine number of houses to power, random
			//randomly choose between powering houses or not, then if powering, choose a random valid target house

			if (random1 % 2 == 0) {
				cout << amount;
				continue;		//random choice to use powerplant
			}


			for (vector<Map::City>::iterator i = m.cities.begin(); i < m.cities.end(); i++)  //random traversal so houses purchased are not all on same city
				for (vector<Map::Connection>::iterator h = (*i).getAdjCities().begin(); h < (*i).getAdjCities().end(); h++) {
					for (int k = 0; k < 3; k++)
						if ((*(*h).getCity()).getOccupants(k) == p1) {			//if adj city has a house owned by the player
							surr = true;
							break;
						}
					if (surr)
						if (p1->GetPowerplant(j)->GetAmountStored() >= p1->GetPowerplant(j)->GetResCost())
							for (int k = 0; k < 3; k++)
								if ((*i).getOccupants(k) == NULL)
									if (random2 % 2 == 0) {			//random choice to power adjacent house
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
}
