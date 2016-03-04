#include "SummaryCard.h"

using namespace std;


const unsigned int Payment::payment_table[21] = { 10,22,33,44,54,64,73,82,90,98,105,112,118,124,129,134,138,142,145,148,150 };

SummaryCard::SummaryCard() {

}

SummaryCard::~SummaryCard() {

}

const char* SummaryCard::firstPhase() {
	const char* str = "First Phase: \nPlayer Order - Most Cities, then highest powerplant value.\n\n";
	return str;
}

const char* SummaryCard::secondPhase() {
	const char* str = "Second Phase: \nPlant Auction - Forward Player Order, Players chooses one: \n"
		"A. Choose market plant for auction and places bid\n"
		"Clockwise players bid or pass. If pass, can't bid on this plant \n"
		"B. PASS - Player can't bid entire phase.\n"
		"Player's turn again if didn't win.\n"
		"Max 1 purchase per player.\n"
		"Max 3 plants. Discard one and transfer resources\n"
		"None purchased: Discard lowest value plant, draw, rearrange.\n"
		"First Round: Player must purchase one plant.\n\n";
	return str;
}

const char* SummaryCard::thirdPhase() {
	const char* str = "ThirdPhase: \nBuy Resources - Reverse Player Order\n"
		"Buy any quantity of any resources up to max capacity of plant\n"
		"Rearrange resources anytime.\n\n";
	return str;
}

const char* SummaryCard::fourthPhase() {
	const char* str = "Fourth Phase: \nBuilding - Reverse player order\n"
		"First round, place anywhere\n"
		"Buy house, pay connection cost + lowest city cost.\n"
		"Skip over city by paying connections.\n"
		"Max # house/cities = # step.\n"
		"Update score track.\n"
		"Discard plant from market if highest score >= plant value.\n\n";
	return str;
}


const char* SummaryCard::fifthPhase() {
	const char* str = "Fifth Phase: \nBureaucreacy - Forward Player Order\n"
		"1. Earn money: Spend resources, collect cash according to table.\n"
		"2. Resupply resources: Most expensive first.\n"
		"3. Update plant market: Step 1 and 2, highest market plant goes to bottom of deck.\n"
		"Step 3, discard lowest plant.\n\n";
	return str;
}

string  SummaryCard::allPhases() {
	ostringstream summary;
	summary << firstPhase() << secondPhase() << thirdPhase() << fourthPhase() << fifthPhase() << endl;
	string str = summary.str();
	return str;
}

string SummaryCard::payment(Player player) {
	string player_name = player.getName();
	ostringstream cash;
	cash << player_name << " will receive " << Payment::payment_table[player.getNumberOfCities()] << " next turn.";
	string str = cash.str();
	return str;
}
