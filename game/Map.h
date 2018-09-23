#pragma once

#include <vector>

#include "Zone.h"
#include "EmptyZone.h"
#include "Coor.h"
#include "Team.h"

class Team;

class Map
{
private:
	Zone *zone[5][5];
	std::vector<Team*> teams;
public:
	void printMaterial();
	void printMap();
	void resolveZone();
	
	bool isInBorder(int x, int y);
	bool isInBorder(Coor c);

	void initMap(char zone[5][5]);
	void getMap(char zone[5][5]);
	Map(char zone[5][5]);
	Map(Map & obj);
	~Map();

	Zone* getZone(Coor c);
	std::vector<Team*> getTeams();
private:
	GameItem* createByChar(char c, Zone* zone);
	Team* getOrCreateTeam(char c);
	void addAdjacencies(int x, int y, Zone* z);
};

