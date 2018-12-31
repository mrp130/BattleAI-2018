#include "Map.h"

#include <iostream>
#include "Mine.h"
#include "Wall.h"
#include "EmptyZone.h"
#include "../strategy/ManualInput.h"
#include "Base.h"
#include "Unit.h"

void Map::printMaterial()
{
	using namespace std;

	for (auto it = teams.begin(); it != teams.end(); ++it) {
		(*it)->printMaterial();
	}
	cout << endl;
}

void Map::printMap()
{
	using namespace std;

	cout << "  ";
	for (int i = 0; i < 5; i++) cout << (char)('A' + i);
	cout << endl << endl;

	char map[5][5];
	this->getMap(map);
	for (int x = 0; x < 5; x++) {
		cout << (x + 1) << " ";
		for (int y = 0; y < 5; y++) {
			cout << map[x][y];
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Map::resolveZone()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			zone[x][y]->resolveZone();
		}
	}
}

bool Map::isInBorder(int x, int y)
{
	if (x < 0) return false;
	if (x > 4) return false;
	if (y < 0) return false;
	if (y > 4) return false;
	return true;
}

bool Map::isInBorder(Coor c)
{
	return this->isInBorder(c.getX(), c.getY());
}

void Map::initMap(char zone[5][5]) {
	getOrCreateTeam('A');
	getOrCreateTeam('B');
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			Zone* z = new Zone();
			GameItem* item = this->createByChar(zone[x][y], z);
			z->addItem(item);
			this->zone[x][y] = z;
		}
	}
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			Zone* &z = this->zone[x][y];
			this->addAdjacencies(x, y, z);
		}
	}
}

void Map::getMap(char zone[5][5])
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			zone[x][y] = this->zone[x][y]->getItem()->getMapChar();
		}
	}
}

Map::Map(char zone[5][5])
{
	initMap(zone);

	Team* teamA = teams.at(0);
	Team* teamB = teams.at(1);

	teamA->setStrategy(new ManualInput(teamA->getSymbol()));
	teamB->setStrategy(new ManualInput(teamB->getSymbol()));
}

Map::Map(Map & obj)
{
	char zone[5][5];
	obj.getMap(zone);
	this->initMap(zone);
	for (int i = 0; i < (int) this->teams.size(); i++) {
		Team* t1 = this->teams.at(i);
		Team* t2 = obj.teams.at(i);
		t1->setWarehouse(new Warehouse(t1, t2->getMaterial()));
	}
}

Map::~Map() {
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			delete zone[x][y];
		}
	}
}

Zone* Map::getZone(Coor c)
{
	return zone[c.getX()][c.getY()];
}

std::vector<Team*> Map::getTeams()
{
	return teams;
}

GameItem * Map::createByChar(char c, Zone* zone)
{
	if (c == '-') return NULL;
	if (c == '#') return new Wall(zone);
	if (c == 'M') return new Mine(zone);
	if (c >= 'A' && c <= 'Z') {
		Team* team = getOrCreateTeam(c);
		Base *b = new Base(zone, team);
		team->addItem(b);
		return b;
	}
	if (c >= 'a' && c <= 'z') {
		Team* team = getOrCreateTeam(c);
		Unit *u = new Unit(zone, team);
		team->addItem(u);
		return u;
	}
	return NULL;
}

Team* Map::getOrCreateTeam(char c)
{
	c = toupper(c);
	for (auto it = teams.begin(); it != teams.end(); ++it) {
		if ((*it)->getSymbol() == c) {
			return *it;
		}
	}
	Team* team = new Team(c);
	teams.push_back(team);
	return team;
}

void Map::addAdjacencies(int x, int y, Zone * z)
{
	if (isInBorder(x - 1, y)) z->addAdjacencies(zone[x - 1][y]);
	if (isInBorder(x + 1, y)) z->addAdjacencies(zone[x + 1][y]);
	if (isInBorder(x, y - 1)) z->addAdjacencies(zone[x][y - 1]);
	if (isInBorder(x, y + 1)) z->addAdjacencies(zone[x][y + 1]);
}
