#include "powergrid.h"
#include <sstream>
using namespace std;


SummaryCard::SummaryCard() {
	int payment_table [21] = {10,22,33,44,54,64,73,82,90,98,105,112,118,124,129,134,138,142,145,148,150};
}

SummaryCard::~SummaryCard() {
	
}

const char* SummaryCard::firstPhase() {
	const char* str = "Player Order - Most Cities, then highest powerplant value.";
	return str;
}

const char* SummaryCard::secondPhase() {
	const char* str = "Plant Auction - Forward Player Order, Players chooses one: "
	"A. Choose market plant for auction and places bid"
	"Clockwise players bid or pass. If pass, can't bid on this plant "
	"B. PASS - Player can't bid entire phase."
	"Player's turn again if didn't win."
	"Max 1 purchase per player."
	"Max 3 plants. Discard one and transfer resources"
	"None purchased: Discard lowest value plant, draw, rearrange."
	"First Round: Player must purchase one plant.";	
	return str;
}

const char* SummaryCard::thirdPhase() {
	const char* str = "Buy Resources - Reverse Player Order\n"
	"Buy any quantity of any resources up to max capacity of plant\n"
	"Rearrange resources anytime.";
	return str;
}

const char* SummaryCard::fourthPhase() {
	const char* str = "Building - Reverse player order\n"
	"First round, place anywhere\n"
	"Buy house, pay connection cost + lowest city cost.\n"
	"Skip over city by paying connections.\n"
	"Max # house/cities = # step.\n"
	"Update score track.\n"
	"Discard plant from market if highest score >= plant value.";
	return str;
}


const char* SummaryCard::fifthPhase() {
	const char* str = "Bureaucreacy - Forward Player Order\n"
	"1. Earn money: Spend resources, collect cash according to table.\n"
	"2. Resupply resources: Most expensive first.\n"
	"3. Update plant market: Step 1 and 2, highest market plant goes to bottom of deck.\n"
	"Step 3, discard lowest plant.";
	return str;
}

string SummaryCard::payment(Player &player) {
	string player_name = player.getName();
	int numOfCities = player.getNumberOfCities();
	int temp = payment_table[numOfCities];
	ostringstream cash;
	cash << temp;
	std::ostringstream oss;
	oss << player_name << " will receive " << cash.str() << " next turn.";
	string str = oss.str();
	return str;
}
