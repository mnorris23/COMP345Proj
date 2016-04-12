//Strategy.h
#include "Player.h"


class Strategy {
public:
	virtual void execute(Player *p1);
};

class Aggressive : public Strategy {
public:
	//Aggressive(Player *p1);
	void executeA(Player*);
};

class Defensive : public Strategy {
public:
	//Defensive(Player *p1);
	void executeD(Player*);
};

class Random : public Strategy {
public:
	//Random(Player *p1);
	void executeR(Player*);
};