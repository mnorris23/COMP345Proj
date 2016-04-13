#include "PowerPlantMarket.h"

using namespace std;


PowerPlantMarket::PowerPlantMarket() {

}

PowerPlantMarket::PowerPlantMarket(pugi::xml_node doc) {
	createPowerPlantMarket(doc);
}

//Delete the 2d array of powerplant
PowerPlantMarket::~PowerPlantMarket() {
	delete [] market[0];
	delete [] market[1];
	delete [] market;
	delete [] marketStep3;
}

//Retrieve a powerplant from the power plant market. Row 0 is the present market
//Row 1 is the future market
PowerPlantMarket::PowerPlant PowerPlantMarket::getPowerPlant(int row, int column) {
	return market[row][column];
}

//Retrieve a powerplant from the power plant market during step 3
PowerPlantMarket::PowerPlant PowerPlantMarket::getPowerPlant(int index) {
	return *marketStep3[index];
}

/**
* Method to update the market that takes the position of the power plant to be removed,
* then takes the first power plant in the deck, add it to the market, rearrange it and notify
* the powerplant market observer.
*/
bool PowerPlantMarket::updateMarket(int row, int column, bool erased) {
	
	bool step3 = false;
	if (!erased) {
		deck.push_back(market[row][column]);
	}
	if (row == 0) {
		//rearranging present market
		for (int i = column; i < 3; i++){
			market[0][i] = market[0][i + 1];
		}
		market[0][3] = market[1][0];

		//rearranging future market
		for (int i = 0; i < 3; i++){
			market[1][i] = market[1][i + 1];
		}
		//draw first powerplant from the deck
		market[1][3] = deck[0];
		deck.erase(deck.begin());
		if (market[1][3].GetValue() == 0) {
			step3 = true;
		}
	}
	else {
		//rearranging future market
		for (int i = column; i < 3; i++){
			market[1][i] = market[1][i + 1];
		}
		//draw first powerplant from the deck
		market[1][3] = deck[0];
		deck.erase(deck.begin());
		if (market[1][3].GetValue() == 0) {
			step3 = true;
		}
	}

	reorderMarket();
	
	Notify();

	return step3;
}

void PowerPlantMarket::createMarketStep3() {
	int j = 0;
	for (int i = 1; i < 3; i++){
		j++;
		if (market[1][i].GetValue() == 0) {
			j--;
		}
		marketStep3[j-1] = &market[0][i];
	}
	j = 0;
	for (int i = 0; i < 3; i++){
		if (market[1][i].GetValue() == 0) {
			j--;
		}
		else {
			marketStep3[j - 1] = &market[1][i];
		}
		j++;
	}
}

void PowerPlantMarket::updateMarketStep3(int index) {

	for (int i = index; i < 6; i++) {
		marketStep3[i] = marketStep3[i + 1];
	}

	marketStep3[5] = &deck[0];
	deck.erase(deck.begin());

	Notify(true);
}

/*
Method that parse the xml file for all the powerplants. The first four represent the present market, 
the next four the future market. The plant #13 follows and is place on top of the deck. The rest 
of power plants are shuffle into the deck.
*/
void PowerPlantMarket::createPowerPlantMarket(pugi::xml_node doc) {
	pugi::xml_node pplantsNode = doc.child("availablePowerPlants");


	for (pugi::xml_node currentPplant = pplantsNode.child("powerPlant"); currentPplant; currentPplant = currentPplant.next_sibling()) {
		string type = currentPplant.child("type").child_value();
		int value = stoi(currentPplant.child("cost").child_value());
		int resCost = stoi(currentPplant.child("burns").child_value());
		int maxCitiesPowered = stoi(currentPplant.child("powers").child_value());
		int resType;
		if (type.compare("coal") == 0) resType = 0;
		else if (type.compare("oil") == 0) resType = 1;
		else if (type.compare("garbage") == 0) resType = 2;
		else if (type.compare("uranium") == 0) resType = 3;
		else if (type.compare("hybrid") == 0) resType = 4;
		else resType = -1;

		powerplants.push_back(PowerPlant(value, maxCitiesPowered, resCost, resType));
	}

	buildMarkets();

	initDeck();

}

/*
Method that instantiate a 2d array for the present market and future market
*/
void PowerPlantMarket::buildMarkets(){

	market = new PowerPlant*[2];
	market[0] = new PowerPlant[4];
	market[1] = new PowerPlant[4];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			market[i][j] = powerplants[0];
			powerplants.erase(powerplants.begin());
		}
	}
}


/*
Method to initialize the deck of power plants. First on top is the power plant #13,
followed by all the power plants left in random order.
*/
void PowerPlantMarket::initDeck(){
	deck.push_back(powerplants[0]);
	powerplants.erase(powerplants.begin());
	int size = powerplants.size();
	for (int i = 0; i < size; i++) {
		int v1 = rand() % (powerplants.size());
		deck.push_back(powerplants[v1]);
		powerplants.erase(powerplants.begin() + v1);
	}
}

/*
Reorder present and future market in ascending order.
*/
void PowerPlantMarket::reorderMarket() {
	PowerPlant temp;

	PowerPlant array[8];

	//transfer 2d array in a single array for sorting
	for (int i = 0; i < 4; i++) {
		array[i] = market[0][i];
		array[i + 4] = market[1][i];
	}

	//reorder present and future market in ascending order
	for (int i = 0; i < 8; i++) {
		for (int j = 7; j > i; j--) {
			if (array[j].GetValue() < array[j - 1].GetValue()) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}

	//transfer array back into 2d array
	for (int i = 0; i < 4; i++) {
		market[0][i] =array[i];
		market[1][i] =array[i+4];
	}
}

/*
In phase 5, remove the biggest valued powerplant from the market
and replace it by the first one on top of the deck. Then reorder
the market if necessary.
*/
void PowerPlantMarket::removeBiggestValued() {

	deck.push_back(market[1][3]);

	market[1][3] = deck[0];

	deck.erase(deck.begin());

	reorderMarket();

	Notify();

}

PowerPlantMarket::PowerPlant::PowerPlant() : _value(0), _maxCitiesPowered(0), _resCost(0), _resType(0) {
	initValues();
}

PowerPlantMarket::PowerPlant::PowerPlant(int value, int maxCitiesPowered, int resCost, int resType) :
	_value(value), _maxCitiesPowered(maxCitiesPowered), _resCost(resCost), _resType(resType) {
	initValues();
}

int PowerPlantMarket::PowerPlant::GetValue() {
	return _value;
}

int PowerPlantMarket::PowerPlant::GetMaxCitiesPowered() {
	return _maxCitiesPowered;
}

int PowerPlantMarket::PowerPlant::GetResCost() {
	return _resCost;
}

int PowerPlantMarket::PowerPlant::GetResType() {
	return _resType;
}

int PowerPlantMarket::PowerPlant::GetAmountStored() {
	int total =0;
	for (int i = 0; i < 4; i++) {
		total += _resStored[i];
	}
	return total;
}

int PowerPlantMarket::PowerPlant::GetAmountStored(int index) {
	return _resStored[index];
}


/*
Resource* PowerPlantMarket::PowerPlant::GetResStoredAt(int index) {
	return &_resStored[index];
}
*/


int  PowerPlantMarket::PowerPlant::GetStorageSpace() {
	return _resCost * 2 - GetAmountStored();
}

void PowerPlantMarket::PowerPlant::initValues() {
	//initializes cities powered
	_citiesPowered = 0;
	for (int i = 0; i < 4; i++) {
		_resStored[i] = 0;
	}
}


bool PowerPlantMarket::PowerPlant::AddCities(int cities) {
	//verifies that the amount of cities being powered doesn't exceed the maximum
	if (_citiesPowered + cities > _maxCitiesPowered)
		return false;
	_citiesPowered += cities; //adds the specified amount of new cities to those being powered
	return true;
}

bool PowerPlantMarket::PowerPlant::RemoveCities(int cities) {
	//verifies that the value of _citiesPowered doesn't go below 0 (which would be impossible).
	if (_citiesPowered - cities < 0)
		return false;
	_citiesPowered -= cities; //removes specified amount of cities from those being powered
	return true;
}

int PowerPlantMarket::PowerPlant::GetCurrentCitiesPowered() {
	return _citiesPowered;
}

bool PowerPlantMarket::PowerPlant::StoreResource(int type, int amount) {
	//verifies that the amount of resources stored doesn't exceed the maximum
	if (GetAmountStored() + amount > _resCost * 2)
		return false;
	//verifies if the type of resource being stored is accepted
	if (_resType != type) {
		if (_resType == 4 && (type == 0 || type == 1)) {}
		else return false;
	}
	_resStored[type] += amount;//adds the resources
	return true;
}

bool PowerPlantMarket::PowerPlant::RemoveResource(int type, int amount) {

	//Removes the resource at specified index and returns it.
	if (_resStored[type] > amount) {
		_resStored[type] -= amount;
		return true;
	}
	else {
		return false;
	}
}



int PowerPlantMarket::PowerPlant::ConsumeResources() {

	if (_resStored[_resType] < _resCost)//verifies that there are enough resources to be consumed
		return 0;//if not return empty vector
	_resStored[_resType] -= _resCost;
	return _resCost;
}

int PowerPlantMarket::PowerPlant::ConsumeResources(int type, int amountToConsume) {
	
	
	if (_resStored[type] < amountToConsume) {//verifies that there are enough resources to be consumed
		return 0;
	}

	_resStored[_resType] -= _resCost;
	return amountToConsume;
}






