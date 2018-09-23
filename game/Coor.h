#pragma once
class Coor
{
private:
	int x;
	int y;
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Coor(int x = -1, int y = -1);
	~Coor();
};

