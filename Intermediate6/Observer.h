#pragma once

class Observer  {
public:
	~Observer();
	virtual void Update() {};
protected:
	Observer();
};