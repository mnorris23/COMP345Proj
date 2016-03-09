#include "PowerPlantObserver.h"

vector<PowerPlant> buildPowerplants();

PowerPlantObserver::PowerPlantObserver() {
	powerplant = new Fl_Group(885, 0, 460, 245, "PowerPlantMarket");
	powerplant->begin();
	powerplant->box(FL_ROUNDED_FRAME);
	powerplant->color(FL_GRAY0);
	powerplant->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	powerplant->end(); // Fl_Group* market

	//vector<PowerPlant> pPlant = buildPowerplants();
}

PowerPlantObserver::~PowerPlantObserver() {

}

void PowerPlantObserver::hide() {
	powerplant->hide();
}

void PowerPlantObserver::show() {
	powerplant->show();
}

vector<PowerPlant> buildPowerplants() {

	vector<PowerPlant> powerplants;


	// These are no being used just filler objects
	powerplants[0] = PowerPlant(0, 0, 0, 0);
	powerplants[1] = PowerPlant(0, 0, 0, 0);
	powerplants[2] = PowerPlant(0, 0, 0, 0);
	powerplants[41] = PowerPlant(0, 0, 0, 0);
	powerplants[43] = PowerPlant(0, 0, 0, 0);
	powerplants[45] = PowerPlant(0, 0, 0, 0);
	powerplants[47] = PowerPlant(0, 0, 0, 0);
	powerplants[48] = PowerPlant(0, 0, 0, 0);
	powerplants[49] = PowerPlant(0, 0, 0, 0);

	//Powerplant(int value, int maxCitiesPowered, int resCost, int resType) 
	// -1 for resType represents eco powerplants
	powerplants[3] = PowerPlant(3, 1, 2, 1);
	powerplants[4] = PowerPlant(4, 1, 2, 0);
	powerplants[5] = PowerPlant(5, 1, 2, 4);
	powerplants[6] = PowerPlant(6, 1, 1, 2);

	powerplants[7] = PowerPlant(7, 2, 3, 1);
	powerplants[8] = PowerPlant(8, 2, 3, 0);
	powerplants[9] = PowerPlant(9, 1, 1, 1);
	powerplants[10] = PowerPlant(10, 2, 2, 0);

	powerplants[11] = PowerPlant(11, 2, 1, 3);
	powerplants[12] = PowerPlant(12, 2, 2, 4);
	powerplants[13] = PowerPlant(13, 1, 0, -1);
	powerplants[14] = PowerPlant(14, 2, 2, 2);

	powerplants[15] = PowerPlant(15, 3, 2, 0);
	powerplants[16] = PowerPlant(16, 3, 2, 1);
	powerplants[17] = PowerPlant(17, 2, 1, 3);
	powerplants[18] = PowerPlant(18, 2, 0, -1);

	powerplants[19] = PowerPlant(19, 3, 2, 2);
	powerplants[20] = PowerPlant(20, 5, 3, 0);
	powerplants[21] = PowerPlant(21, 4, 2, 4);
	powerplants[22] = PowerPlant(22, 2, 0, -1);

	powerplants[23] = PowerPlant(23, 3, 1, 3);
	powerplants[24] = PowerPlant(24, 4, 2, 2);
	powerplants[25] = PowerPlant(25, 5, 2, 0);
	powerplants[26] = PowerPlant(26, 5, 2, 1);

	powerplants[27] = PowerPlant(27, 3, 0, -1);
	powerplants[28] = PowerPlant(28, 4, 1, 3);
	powerplants[29] = PowerPlant(29, 4, 1, 4);
	powerplants[30] = PowerPlant(30, 6, 3, 2);

	powerplants[31] = PowerPlant(31, 6, 3, 0);
	powerplants[32] = PowerPlant(32, 6, 3, 1);
	powerplants[33] = PowerPlant(33, 4, 0, -1);
	powerplants[34] = PowerPlant(34, 5, 1, 3);

	powerplants[35] = PowerPlant(35, 5, 1, 1);
	powerplants[36] = PowerPlant(36, 7, 3, 0);
	powerplants[37] = PowerPlant(37, 4, 0, -1);
	powerplants[38] = PowerPlant(38, 7, 3, 2);

	powerplants[39] = PowerPlant(39, 6, 1, 3);
	powerplants[40] = PowerPlant(40, 6, 2, 1);

	powerplants[42] = PowerPlant(42, 6, 2, 0);

	powerplants[44] = PowerPlant(44, 5, 0, -1);

	powerplants[46] = PowerPlant(46, 7, 3, 4);
	powerplants[50] = PowerPlant(50, 6, 0, -1);

	return powerplants;
}