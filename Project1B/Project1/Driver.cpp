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

	Powerplant p1(19, 3, 2, 2);
	Powerplant pp2(20, 5, 3, 0);

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
//Initializes all the powerplants
void buildPowerplants(){
	//Two powerplants
	Powerplant powerplants[42];
	
	//Powerplant(int value, int maxCitiesPowered, int resCost, int resType) 
	
	powerplants[0] = Powerplant(3, 1, 2, 1);
	powerplants[1] = Powerplant(4, 1, 2, 0);
	powerplants[2] = Powerplant(5, 1, 2, 4);
	powerplants[3] = Powerplant(6, 1, 1, 2);

	powerplants[4] = Powerplant(7, 2, 3, 1);
	powerplants[5] = Powerplant(8, 2, 3, 0);
	powerplants[6] = Powerplant(9, 1, 1, 1);
	powerplants[7] = Powerplant(10, 2, 2, 0);

	powerplants[8] = Powerplant(11, 2, 1, 3);
	powerplants[9] = Powerplant(12, 2, 2, 4);
	powerplants[10] = Powerplant(13, 1, 0, -1);
	powerplants[11] = Powerplant(14, 2, 2, 2);

	powerplants[12] = Powerplant(15, 3, 2, 0);
	powerplants[13] = Powerplant(16, 3, 2, 1);
	powerplants[14] = Powerplant(17, 2, 1, 3);
	powerplants[15] = Powerplant(18, 2, 0, -1);

	powerplants[16] = Powerplant(19, 3, 2, 2);
	powerplants[17] = Powerplant(20, 5, 3, 0);
	powerplants[18] = Powerplant(21, 4, 2, 4);
	powerplants[19] = Powerplant(22, 2, 0, -1);

	powerplants[20] = Powerplant(23, 3, 1, 3);
	powerplants[21] = Powerplant(24, 4, 2, 2);
	powerplants[22] = Powerplant(25, 5, 2, 0);
	powerplants[23] = Powerplant(26, 5, 2, 1);

	powerplants[24] = Powerplant(27, 3, 0, -1);
	powerplants[25] = Powerplant(28, 4, 1, 3);
	powerplants[26] = Powerplant(29, 4, 1, 4);
	powerplants[27] = Powerplant(30, 6, 3, 2);

	powerplants[28] = Powerplant(31, 6, 3, 0);
	powerplants[29] = Powerplant(32, 6, 3, 1);
	powerplants[30] = Powerplant(33, 4, 0, -1);
	powerplants[31] = Powerplant(34, 5, 1, 3);
	
	powerplants[32] = Powerplant(35, 5, 1, 1);
	powerplants[33] = Powerplant(36, 7, 3, 0);
	powerplants[34] = Powerplant(37, 4, 0, -1);
	powerplants[35] = Powerplant(38, 7, 3, 2);
	
	powerplants[36] = Powerplant(39, 6, 1, 3);
	powerplants[37] = Powerplant(40, 6, 2, 1);
	powerplants[38] = Powerplant(42, 6, 2, 0);
	powerplants[39] = Powerplant(44, 5, 0, -1);
	
	powerplants[40] = Powerplant(46, 7, 3, 4);
	powerplants[41] = Powerplant(50, 6, 0, -1);

}