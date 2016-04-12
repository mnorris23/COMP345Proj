#pragma once

#include "Observer.h"
#include <list>
#include <string>

class Observable {
protected:
	std::list<Observer *> *observers;
public:
	Observable();
	~Observable();
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
	virtual void Notify(bool);
};