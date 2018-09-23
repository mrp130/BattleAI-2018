#include "Unit.h"

int Unit::produceMaterial()
{
	return 1 * canMine();
}

char Unit::getMapChar() {
	return this->getTeam()->getSymbol() + 'a' - 'A';
}

std::string Unit::getClassName()
{
	return "Unit";
}

Unit::Unit(Zone* zone, Team* team) : TeamItem(zone, team) {}
Unit::~Unit() {}
