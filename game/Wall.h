#pragma once
#include "GameItem.h"

#include "Zone.h"

class Wall : public GameItem
{
public:
	char getMapChar();
	std::string getClassName();
	Wall(Zone* zone);
	~Wall();
};

