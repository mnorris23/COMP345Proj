#pragma once
#include <vector>
#include <list>
#include "Observer.h"

class ASubject
{
	//Lets keep a track of all the players we have observing
	std::vector<Observer*> olist;

public:
    void Attach(Observer *o);
    void Detach(Observer *o);
    void Notify(); 
    ASubject();
    ~ASubject();
};
