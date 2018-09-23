#include "Team.h"

#include <iostream>
#include <typeinfo>

std::string Team::move(Map * map)
{
	std::cout << "Team " << getSymbol() << " moving ..." << std::endl;
	if (strategy == NULL) return "";
	return strategy->move(map);
}

void Team::produceMaterial()
{
	warehouse->addMaterial(countProduceMaterial());
}

int Team::countProduceMaterial()
{
	int material = 0;
	for (auto item = items.begin(); item != items.end(); ++item) {
		material += (*item)->produceMaterial();
	}
	return material;
}

void Team::printMaterial()
{
	using namespace std;
	cout << symbol << " material: " << warehouse->getMaterial() << " (+" << countProduceMaterial() << ")" << endl;
}

int Team::countUnit()
{
	int unit = 0;
	for (auto item = items.begin(); item != items.end(); ++item) {
		if ((*item)->getClassName() == "Unit") ++unit;
	}
	return unit;
}

int Team::countBase()
{
	int base = 0;
	for (auto item = items.begin(); item != items.end(); ++item) {
		if((*item)->getClassName() == "Base") ++base;
	}
	return base;
}

Team::Team(char symbol) : symbol(symbol) {
	this->strategy = NULL;
	this->warehouse = new Warehouse(this);
}
Team::~Team() {}

std::vector<TeamItem*> Team::getItems()
{
	return items;
}

void Team::addItem(TeamItem * item)
{
	this->items.push_back(item);
}

void Team::deleteItem(TeamItem * item)
{
	using namespace std;
	items.erase(find(items.begin(), items.end(), item));
}

char Team::getSymbol()
{
	return symbol;
}

void Team::setWarehouse(Warehouse * warehouse)
{
	this->warehouse = warehouse;
}

int Team::getMaterial()
{
	return warehouse->getMaterial();
}

Warehouse * Team::getWarehouse()
{
	return warehouse;
}

void Team::setStrategy(MoveStrategy * strategy)
{
	if (this->strategy != NULL) delete this->strategy;
	this->strategy = strategy;
}
