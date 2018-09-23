#pragma once

#include "TeamItem.h"
#include "Team.h"
#include "Zone.h"

class Team;
class TeamItem;

class Warehouse
{
private:
	int material;
	Team* team;
public:
	int getMaterial();
	void addMaterial(int material);
	TeamItem* createUnit(Zone* zone);
	TeamItem* createBase(Zone* zone);
	Warehouse(Team* team, int material = 5);
	~Warehouse();
};

