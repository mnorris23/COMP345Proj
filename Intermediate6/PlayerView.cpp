
#include "PlayerView.h" 
#include "Player.h" 
#include <iostream>
using namespace std;


PlayerView::PlayerView(){
};
PlayerView::PlayerView(Player* s){
  //Upon instantiation, attaches itself
  //to a Player
  _subject = s;
  _subject->Attach(this);
};
PlayerView::~PlayerView(){
  //Upon destruction, detaches itself
  //from its Player
  _subject->Detach(this);
};
void PlayerView::Update(){
  //Called by Notify() when state of Subject changes
  display();
};
void PlayerView::display(){

  //adjust for player info
	//1) area 2) list of cities owned 3) list of power plants owned 
	//4) different possession (e.g. houses, money, etc.)

  std::string area = _subject->getColor();
  std::string name = _subject->getName();
  int money = _subject->getMoney();
  int houses = _subject->getNumberOfHouses();
  int plants = _subject->getNumberOfPowerPlants();
  int max = _subject->getMaxValuePowerplant();

  //House house[24] = _subject->_houses;			//need to populate new arrays
  //PowerPlant powerplant[3] =_subject->_powerplants;
  
  
  //output from here not driver
  
};