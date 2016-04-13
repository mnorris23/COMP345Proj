#include "ASubject.h"
#include <algorithm>

using namespace std;

ASubject::ASubject(){
	std::vector<Observer*> olist;
}

ASubject::~ASubject(){
	//delete olist;
}

void ASubject::Attach(Observer *o)
{
	olist.push_back(o);
}

void ASubject::Detach(Observer *o)
{	
	olist.erase(std::remove(olist.begin(), olist.end(), o), olist.end());	
}

void ASubject::Notify()     //pass vars
{
	for(vector<Observer*>::const_iterator iter = olist.begin(); iter != olist.end(); ++iter)
	{
		if(*iter != 0)
		{
			(*iter)->Update();   //pass vars
		}
	}
}
