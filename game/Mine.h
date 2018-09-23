#pragma once
#include "GameItem.h"

#include "Zone.h"

class Mine : public GameItem
{
public:
	char getMapChar();
	std::string getClassName();
	Mine(Zone* zone);
	~Mine();
};

