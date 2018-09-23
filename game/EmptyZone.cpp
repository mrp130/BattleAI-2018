#include "EmptyZone.h"


char EmptyZone::getMapChar() {
	return '-';
}

std::string EmptyZone::getClassName()
{
	return "EmptyZone";
}

EmptyZone::EmptyZone(Zone* zone) : GameItem(zone) {}


EmptyZone::~EmptyZone()
{
}
