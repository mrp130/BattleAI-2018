#pragma once

#include <string>

#include "../game/Map.h"

class Map;

class MoveStrategy
{
public:
	virtual std::string move(Map * map) = 0;

	MoveStrategy();
	virtual ~MoveStrategy() = 0;
};

inline MoveStrategy::MoveStrategy() {}
inline MoveStrategy::~MoveStrategy() {}

