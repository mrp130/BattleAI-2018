#pragma once

#include <string>

#include "../game/Map.h"

class Map;

class MoveStrategy
{
protected:
	char team;
public:
	virtual std::string move(Map * map) = 0;

	MoveStrategy(char team);
	virtual ~MoveStrategy() = 0;
};

inline MoveStrategy::MoveStrategy(char team) : team(team) {}
inline MoveStrategy::~MoveStrategy() {}

