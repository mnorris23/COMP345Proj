#pragma once
#include "Strategy.h"

class Random : public Strategy {
public:
	Random(Player *p1);
	void execute(Player*);
};