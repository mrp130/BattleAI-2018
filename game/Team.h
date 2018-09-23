#pragma once

#include "../strategy/MoveStrategy.h"
#include "Map.h"
#include "Warehouse.h"
#include "TeamItem.h"

#include <vector>
#include <string>

class Map;
class Warehouse;
class TeamItem;
class MoveStrategy;

class Team
{
private:
	MoveStrategy* strategy;
	Warehouse* warehouse;
	char symbol;
	std::vector<TeamItem*> items;
public:
	std::string move(Map* map);
	void produceMaterial();
	int countProduceMaterial();
	void printMaterial();
	int countUnit();
	int countBase();
	
	Team(char symbol);
	~Team();

	std::vector<TeamItem*> getItems();
	void addItem(TeamItem* item);
	void deleteItem(TeamItem* item);
	char getSymbol();
	void setWarehouse(Warehouse* warehouse);
	int getMaterial();
	Warehouse* getWarehouse();
	void setStrategy(MoveStrategy* strategy);
};

