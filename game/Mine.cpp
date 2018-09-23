#include "Mine.h"

char Mine::getMapChar() {
	return 'M';
}

std::string Mine::getClassName()
{
	return "Mine";
}

Mine::Mine(Zone* zone) : GameItem(zone) {}


Mine::~Mine()
{
}
