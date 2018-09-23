#pragma once

#include "Zone.h"

class Zone;

class GameItem
{
protected:
	Zone* zone;
public:
	virtual char getMapChar() = 0;
	virtual std::string getClassName() = 0;
	GameItem(Zone* zone);
	virtual ~GameItem() = 0;

	void setZone(Zone* zone);
};

inline GameItem::GameItem(Zone* zone) { this->zone = zone; }
inline GameItem::~GameItem() {}

inline void GameItem::setZone(Zone * zone)
{
	this->zone = zone;
}
