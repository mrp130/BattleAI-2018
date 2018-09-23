#pragma once
#include "GameItem.h"

#include "Zone.h"

class EmptyZone : public GameItem
{
public:
	char getMapChar();
	std::string getClassName();
	EmptyZone(Zone* zone);
	~EmptyZone();
};

