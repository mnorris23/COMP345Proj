#pragma once
#include "IObserver.h"

class Observer : IObserver {
public:
	~Observer();
	virtual void Update();
protected:
	Observer();
};