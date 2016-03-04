#include "Driver.h"

#include <iostream>;

using namespace std;

void Driver::run() {

	//The resource market
	ResourceMarket market(24, 15, 6, 2);
	//Two players
	Player player1(50, "RED");
	Player player2(50, "BLUE");

	//Two houses
	House house1;
	House house2;

	house1.location = "Montreal";
	house2.location = "Quebec";

	//Two powerplants
	Powerplant pp1(19, 3, 2, 2);
	Powerplant pp2(20, 5, 3, 0);

	//Players 1 and 2 add a house at 0 cost (just for demonstration purposes)
	player1.AddHouse(house1, 0);
	player2.AddHouse(house2, 0);

	//Players 1 and 2 add a powerplant at 0 cost (just for demonstration purposes)
	player1.AddPowerplant(pp1, 0);
	player2.AddPowerplant(pp2, 0);

	//player 1 is trying to add 1 unit of garbage from the market to his first powerplant
	player1.AddResources(0, market.BuyResource(2, 1));

	//player 2 is trying to add 4 units of coal from the market to his first powerplant
	player2.AddResources(0, market.BuyResource(0, 4));

	//Displaying the state of the players
	player1.DisplayPlayer();

	cout << "\nOther Player\n" << endl;

	player2.DisplayPlayer();

	cout << "\nThe Resource Market\n" << endl;
	//Displaying the market
	market.DisplayMarket();

	int i;
	cin >> i;

}
//The main method just 
int main() {
	Driver d;
	d.run();
}
