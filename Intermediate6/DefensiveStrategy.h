#pragma once
#include "Strategy.h"

class Defensive : public Strategy {
public:
	Defensive(Player *p1);
	void execute(Player*);
};
