#include "Coor.h"



int Coor::getX()
{
	return x;
}

int Coor::getY()
{
	return y;
}

void Coor::setX(int x)
{
	this->x = x;
}

void Coor::setY(int y)
{
	this->y = y;
}

Coor::Coor(int x, int y) : x(x), y(y) {}
Coor::~Coor() {}
