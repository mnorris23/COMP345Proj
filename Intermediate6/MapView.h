#pragma once

#include "Observer.h"
#include "Map.h"

class MapView : public Observer {

	Map* map;

public:
	MapView();
	MapView(Map*);
	~MapView();
	void Update();
	void printMap();
};