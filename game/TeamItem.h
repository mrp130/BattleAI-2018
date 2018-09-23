#pragma once

#include "Team.h"
#include "Zone.h"
#include "GameItem.h"

class Team;

class TeamItem : public GameItem 
{
protected:
	Team* team;
public:
	virtual int produceMaterial() = 0;

	TeamItem(Zone* zone, Team* team);
	virtual ~TeamItem() = 0;

	Team* getTeam();
protected:
	virtual int canMine();
};

