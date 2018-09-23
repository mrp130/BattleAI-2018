#pragma once

#include <vector>

#include "Map.h"
#include "Coor.h"

class Game
{
private:
	Map* map;
	int turn;
public:
	void run();
	void initMap(char map[5][5]);
	void print();

	Game();
	~Game();
private:
	void produceMaterial();
	void moves(std::vector< std::pair <Team*, std::string> > moves);
	bool move(Team* team, Coor from, Coor to);
	bool isValidMove(Team* team, Zone* curr, Zone* finish, std::vector<Zone*>& visited);
	void convertMoveString(std::string move, Coor& from, Coor& to);
};

