#include "Warehouse.h"

#include "Unit.h"
#include "Base.h"

int Warehouse::getMaterial()
{
	return material;
}

void Warehouse::addMaterial(int material)
{
	this->material += material;
}

TeamItem * Warehouse::createUnit(Zone* zone)
{
	if (this->material < 4) return NULL;

	this->material -= 4;

	TeamItem* item = new Unit(zone, team);
	zone->addItem(item);
	team->addItem(item);

	return item;
}

TeamItem * Warehouse::createBase(Zone * zone)
{
	if (this->material < 10) return NULL;

	std::vector<GameItem* > items = zone->getItems();

	GameItem* unit = zone->takeItem(team->getSymbol());
	if (unit == NULL) return NULL;

	this->material -= 10;
	team->deleteItem((TeamItem*) unit);
	TeamItem* item = new Base(zone, team);
	team->addItem(item);
	zone->addItem(item);

	return item;
}

Warehouse::Warehouse(Team* team, int material) : team(team) { 
	this->material = material; 
}
Warehouse::~Warehouse() {}
