#include "Wall.h"

char Wall::getMapChar() {
	return '#';
}

std::string Wall::getClassName()
{
	return "Wall";
}

Wall::Wall(Zone* zone) : GameItem(zone) {}

Wall::~Wall() {}
