#include "StartGui.h"

using namespace std;


StartGUI::StartGUI() {
	mainWindow = new Fl_Window(1347, 881, "PowerGrid Board Game");
	mainWindow->user_data((void*)(this));
	mainWindow->begin();
	buff = new Fl_Text_Buffer();
	welcome = new Fl_Text_Display(518, 385, 310, 50);
	welcome->buffer(buff);
	welcome->color(FL_DARK3);

	buff->text("Select New/Load Game");

	load = new Fl_Button(518, 460, 175, 65, "Load");

	load->callback((Fl_Callback*)load_cb);

	newb = new Fl_Button(693, 460, 175, 65, "New");

	newb->callback((Fl_Callback*)newb_cb);

	

	//buff->text("PowerGrid Board Game\n Select # of players.");
	
	//twoplayers = new Fl_Button(586, 460, 175, 65, "2 Players");

	//twoplayers->callback((Fl_Callback*)twoplayers_cb);


	start = new Fl_Button(590, 505, 175, 65, "Start");
	load_file_button = new Fl_Button(590, 505, 175, 65, "Load");
	load_file = new Fl_Input(431, 462, 265, 43, "XML File Name (.xml)");
	first_player_name = new Fl_Input(431, 422, 265, 43, "First Player Name");
	second_player_name = new Fl_Input(431, 462, 265, 43, "Second player Name");
	first_player_color = new Fl_Choice(716,422,190,43);
	second_player_color = new Fl_Choice(716, 462, 190, 43);
	first_player_color->add("red");
	first_player_color->add("green");
	first_player_color->add("yellow"); 
	first_player_color->add("blue");
	first_player_color->add("pink");
	first_player_color->add("orange");
	first_player_color->value(0);
	second_player_color->add("red");
	second_player_color->add("green");
	second_player_color->add("yellow");
	second_player_color->add("blue");
	second_player_color->add("pink");
	second_player_color->add("orange");
	second_player_color->value(0);

	start->hide();
	first_player_name->hide();
	second_player_name->hide();
	first_player_color->hide();
	second_player_color->hide();
	load_file->hide();
	load_file_button->hide();

	start->callback((Fl_Callback*)start_cb);

	load_file_button->callback((Fl_Callback*)load_file_button_cb);

	playerinfo = new PlayerObserver();

	//map = new MapObserver();

	resources = new ResourcesMarketObserver();

	powerplant = new PowerPlantObserver();

	summary = new SummaryCardObserver();

	Map brazil;
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file("map.xml");  // loading the map into document

	//load_file_button->hide();

	if (result) { // checking if the document was parsed properly
		cout << "XML [" << "map.xml" << "] parsed without errors. \n";
		brazil.createMap(document.child("powergrid")); // a new map object is created from the xml file

	}
	else {
		cout << "XML [" << "map.xml" << "] parsed with errors. \n";
	}

	map = new MapObserver(brazil);
	
	playerinfo->hide();
	
	resources->hide();
	powerplant->hide();
	summary->hide();
	map->hide();
	mainWindow->end();
	mainWindow->show();
}

StartGUI::~StartGUI() {

}

/*
void StartGUI::twoplayers_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->twoplayers_cb_i(w, v);
}
*/

void StartGUI::load_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->load_cb_i(w, v);
}


void StartGUI::newb_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->newb_cb_i(w, v);
}

void StartGUI::load_file_button_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->load_file_button_cb_i(w, v);
}
/*
void StartGUI::twoplayers_cb_i(Fl_Widget* , void* )
{
	welcome->hide();
	//twoplayers->hide();
	start->show();
	first_player_name->show();
	second_player_name->show();
	first_player_color->show();
	second_player_color->show();	
}
*/

void StartGUI::load_cb_i(Fl_Widget*, void*)
{
	welcome->hide();
	//twoplayers->hide();
	load->hide();
	newb->hide();
	load_file->show();
	load_file_button->show();
}

void StartGUI::newb_cb_i(Fl_Widget*, void*)
{
	welcome->hide();
	//twoplayers->hide();
	load->hide();
	newb->hide();
	start->show();
	first_player_name->show();
	second_player_name->show();
	first_player_color->show();
	second_player_color->show();
}

void StartGUI::start_cb(Fl_Widget* w, void* v) {
	((StartGUI*)(w->parent()->user_data()))->start_cb_i(w, v);
}

void StartGUI::start_cb_i(Fl_Widget* w, void* v) {
	waitToStart();
}


void StartGUI::load_file_button_cb_i(Fl_Widget* w, void* v) {
	loadToStart();
}

string StartGUI::getFileName() {
	return load_file->value();
}

int StartGUI::getStartButtonValue() {
	return start->value();
}

string StartGUI::getFirstPlayerName() {
	return first_player_name->value();
}

string StartGUI::getSecondPlayerName() {
	return second_player_name->value();
}

int StartGUI::getFirstPlayerColor() {
	return first_player_color->value();
}

int StartGUI::getSecondPlayerColor() {
	return second_player_color->value();
}

void StartGUI::waitToStart() {
	Player player1;
	Player player2;
	PlayerVector playerlist(2);
	player1 = Player(getFirstPlayerName(), getFirstPlayerColor());
	player2 = Player(getSecondPlayerName(), getSecondPlayerColor());
	playerlist.setPlayer(player1, 0);
	playerlist.setPlayer(player2, 1);
	/*
	Map brazil;
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file("map.xml");  // loading the map into document

	//load_file_button->hide();

	if (result) { // checking if the document was parsed properly
		cout << "XML [" << "map.xml" << "] parsed without errors. \n";
		brazil.createMap(document.child("powergrid")); // a new map object is created from the xml file

	}
	else {
		cout << "XML [" << "map.xml" << "] parsed with errors. \n";
	}

	map = new MapObserver(brazil);
	*/
	start->hide();
	first_player_name->hide();
	second_player_name->hide();
	first_player_color->hide();
	second_player_color->hide();

	playerinfo->displayPlayerInformation(playerlist);

	playerinfo->show();
	map->show();
	resources->show();
	powerplant->show();
	summary->show();
}

vector<int> createResourceMarket(pugi::xml_node doc) { // function parses the resource market info from the xml
	pugi::xml_node resourceMarketNode = doc.child("resourceMarket");
	vector<int> resourceMarket; // coal, oil, garbage, uranium
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	resourceMarket.push_back(0);
	for (pugi::xml_node currentBox = resourceMarketNode.child("box"); currentBox; currentBox = currentBox.next_sibling()) {
		pugi::xml_node holding = currentBox.child("holds");
		int coal = stoi(holding.child("coal").child_value());
		int oil = stoi(holding.child("oil").child_value());
		int garbage = stoi(holding.child("garbage").child_value());
		int uranium = stoi(holding.child("uranium").child_value());
		resourceMarket[0] = resourceMarket[0] + coal;
		resourceMarket[1] = resourceMarket[1] + oil;
		resourceMarket[2] = resourceMarket[2] + garbage;
		resourceMarket[3] = resourceMarket[3] + uranium;
	}
	return resourceMarket;
}

vector<int> createResourceSupply(pugi::xml_node doc) { // function parses the resource supply info from the xml
	pugi::xml_node resourceSupplyNode = doc.child("resourceSupply");
	vector<int> resourceSupply; // coal, oil, garbage, uranium
	resourceSupply.push_back(stoi(resourceSupplyNode.child("coal").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("oil").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("garbage").child_value()));
	resourceSupply.push_back(stoi(resourceSupplyNode.child("uranium").child_value()));
	return resourceSupply;
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

vector<PowerPlant> availablePowerPlants(pugi::xml_node doc, vector<PowerPlant> allPplants) {
	pugi::xml_node availablePplants = doc.child("availablePowerPlants");
	vector<PowerPlant> pPlants;
	for (pugi::xml_node availablePplantsNode = availablePplants.child("player"); availablePplantsNode; availablePplantsNode = availablePplantsNode.next_sibling()) {
		int value = stoi(availablePplantsNode.child_value());
		for (vector<PowerPlant>::iterator it = allPplants.begin(); it != allPplants.end(); it++) {
			if ((*it).GetValue() == value)
				pPlants.push_back(*it);
		}
	}
	return pPlants;
}

vector<Player> loadPlayers(pugi::xml_node doc, vector<PowerPlant> pplants) {
	pugi::xml_node playersNode = doc.child("players");
	vector<Player> players;
	for (pugi::xml_node currentPlayerNode = playersNode.child("player"); currentPlayerNode; currentPlayerNode = currentPlayerNode.next_sibling()) {
		string pName = currentPlayerNode.child("name").child_value();
		int pColor = stoi(currentPlayerNode.child("color").child_value());
		int elektros = stoi(currentPlayerNode.child("elektros").child_value());
		Player player(pName, pColor, elektros);
		for (pugi::xml_node currentHouseNode = currentPlayerNode.child("houses").child("location"); currentHouseNode; currentHouseNode = currentHouseNode.next_sibling()) {
			string location = currentHouseNode.child_value();
			House h;
			h.location = location;
			player.AddHouse(h);
		}
		for (pugi::xml_node currentPPlantNode = currentPlayerNode.child("powerPlants").child("powerPlant"); currentPPlantNode; currentPPlantNode = currentPPlantNode.next_sibling()) {
			int value = stoi(currentPPlantNode.child("value").child_value());
			int resourceType = pplants[value].GetResType();
			PowerPlant pplant = pplants[value];
			vector<Resource> r;
			int resourceAmount = stoi(currentPPlantNode.child("resources").child_value());
			if (resourceAmount > 6) { // if there is more than 6 resources than the plant is a hybrid and is storing resources as a double digit
				int coalAmount = resourceAmount / 10; // first digit represnts the coal amount
				int oilAmount = resourceAmount % 10; // second digit represents the oil amount 
				for (int i = 1; i <= coalAmount; i++) {
					Resource resource;
					resource.type = 0; // coal
					r.push_back(resource);
				}
				for (int i = 1; i <= oilAmount; i++) {
					Resource resource;
					resource.type = 1; // oil
					r.push_back(resource);
				}
			}
			else { // not a hybrid
				for (int i = 1; i <= resourceAmount; i++) {
					Resource resource;
					resource.type = resourceType; // resource type the powerplant is holding
					r.push_back(resource);
				}
			}
			pplant.StoreResource(r);
		}
	}
	return players;
}

void StartGUI::loadToStart() {
	string fileName = getFileName();

	Map brazil;
	const char* gN = fileName.c_str();
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file(gN);  // loading the map into document

	//load_file_button->hide();

	if (result) { // checking if the document was parsed properly
		cout << "XML [" << "map.xml" << "] parsed without errors. \n";
		brazil.createMap(document.child("powergrid")); // a new map object is created from the xml file

	}
	else {
		cout << "XML [" << "map.xml" << "] parsed with errors. \n";
	}

	map = new MapObserver(brazil);
	
	//vector<PowerPlant> pPlants = buildPowerplants();
	//vector<Player> players = loadPlayers(document.child("powergrid"), pPlants); // loading player into and possessions from xml file into a vector of players

	//vector<int> rM = createResourceMarket(document.child("powergrid")); 
	//ResourceMarket resourceMarket(rM[0], rM[1], rM[2], rM[3]);

	//vector<int> resourceSupply = createResourceSupply(document.child("powergrid")); // creating the resource supply

	//vector<PowerPlant> availablePPlants = availablePowerPlants(document.child("powergrid"), pPlants); // creating a vector of avaliable power plants in deck
}

vector<Player> playerOrder(vector<Player> players) {
	
	Player temp;
	for (int i = 0; i < players.size(); i++) {
		for (int j = players.size() - 1; j > i; j--) {
			if (players[j].getNumberOfHouses() > players[j - 1].getNumberOfHouses()) {
				temp = players[j - 1];
				players[j - 1] = players[j];
				players[j] = temp;
			}
		}
	}

	for (int i = 0; i < players.size(); i++) {
		for (int j = players.size() - 1; j > i; j--) {
			if (players[j].getNumberOfHouses() == players[j - 1].getNumberOfHouses()) {
				if (players[j].getMaxValuePowerplant() > players[j - 1].getMaxValuePowerplant()) {
					temp = players[j - 1];
					players[j - 1] = players[j];
					players[j] = temp;
				}
			}
			
		}
	}
	return players;
}

