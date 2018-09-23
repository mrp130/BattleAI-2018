#pragma once
#include "TeamItem.h"
#include "Team.h"
#include "Zone.h"

class Base : public TeamItem
{
public:
	int produceMaterial();

	char getMapChar();
	std::string getClassName();
	Base(Zone* zone, Team* team);
	~Base();
};

