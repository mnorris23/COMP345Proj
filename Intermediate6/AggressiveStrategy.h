#pragma once
#include "Strategy.h"

class Aggressive : public Strategy {
public:
	Aggressive(Player *p1);
	void execute(Player*);
};
