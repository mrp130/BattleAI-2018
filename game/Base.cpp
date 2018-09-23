#include "Base.h"

int Base::produceMaterial()
{
	return 2 + canMine() * 2;
}

char Base::getMapChar() {
	return this->getTeam()->getSymbol();
}

std::string Base::getClassName()
{
	return "Base";
}

Base::Base(Zone* zone, Team* team) : TeamItem(zone, team) {}
Base::~Base() {}
