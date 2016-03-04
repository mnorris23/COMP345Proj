#include "PlayerVector.h"

using namespace std;

PlayerVector::PlayerVector() : arrayPlayer(2) {

}

PlayerVector::PlayerVector(int size) : arrayPlayer(size) {
}

PlayerVector::~PlayerVector() {

}

Player PlayerVector::getPlayer(int index) {
	return arrayPlayer[index];
}

void PlayerVector::setPlayer(Player p, int i) {
	arrayPlayer[i] = p;
}

