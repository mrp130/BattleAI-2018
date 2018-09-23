
#pragma once
#include "TeamItem.h"

#include "Zone.h"
#include "Team.h"

class Unit : public TeamItem
{
public:
	int produceMaterial();

	char getMapChar();
	std::string getClassName();
	Unit(Zone* zone, Team* team);
	~Unit();
};

