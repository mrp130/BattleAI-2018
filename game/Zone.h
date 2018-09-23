#pragma once

#include <vector>

#include "GameItem.h"

class GameItem;

class Zone
{
private:
	std::vector<Zone*> adjacencies;
	std::vector<GameItem*> items;
public:
	void addAdjacencies(Zone* z);
	bool isInAdjacencies(Zone* z);

	void resolveZone();

	Zone();
	Zone(GameItem* item);
	~Zone();

	std::vector<Zone*> getAdjacencies();
	GameItem* getItem(char team = ' ');
	GameItem* takeItem(char team = ' ');
	std::vector<GameItem*> getItems();
	void addItem(GameItem* item);
};