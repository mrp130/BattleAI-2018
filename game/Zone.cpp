#include "Zone.h"

#include "EmptyZone.h"
#include "Base.h"
#include "Unit.h"


void Zone::addAdjacencies(Zone * z)
{
	adjacencies.push_back(z);
}

bool Zone::isInAdjacencies(Zone * z)
{
	for (auto it = adjacencies.begin(); it != adjacencies.end(); ++it) {
		if ((*it) == z) {
			return true;
		}
	}
	return false;
}

void Zone::resolveZone()
{
	if (items.size() <= 2) return;
	while (items.size() > 1) {
		GameItem* item = items.back();
		if (item->getClassName() == "Base" || item->getClassName() == "Unit") {
			((TeamItem*)item)->getTeam()->deleteItem((TeamItem*)item);
		}
		items.pop_back();
	}
}

Zone::Zone() {
	items.push_back(new EmptyZone(this));
}

Zone::Zone(GameItem* item)
{
	items.push_back(new EmptyZone(this));
	items.push_back(item);
}

Zone::~Zone()
{
	for (auto it = items.begin(); it != items.end(); ++it) {
		delete *it;
	}
}

std::vector<Zone*> Zone::getAdjacencies()
{
	return adjacencies;
}

GameItem * Zone::getItem(char team)
{
	if (items.size() == 0) {
		items.push_back(new EmptyZone(this));
	}
	if (team == ' ' || items.size() == 1) {
		return items.back();
	}

	for (auto it = items.begin(); it != items.end(); ++it) {
		if (toupper((*it)->getMapChar()) == team) return *it;
	}

	return items.back();
}

GameItem * Zone::takeItem(char team)
{
	GameItem* item = NULL;
	if (team == ' ') item = items.back();
	else {
		for (int i = 0; i < (int) items.size(); i++) {
			if (toupper(items.at(i)->getMapChar()) == team) {
				item = items.at(i);
				break;
			}
		}
	}
	if (item == NULL) return NULL;

	item->setZone(NULL);
	items.erase(find(items.begin(), items.end(), item));
	
	if (items.size() == 0) {
		items.push_back(new EmptyZone(this));
	}
	
	return item;
}

std::vector<GameItem*> Zone::getItems()
{
	return items;
}

void Zone::addItem(GameItem* item)
{
	if (item == NULL) return;
	this->items.push_back(item);
	item->setZone(this);
}
