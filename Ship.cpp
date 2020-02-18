#include "Ship.h"

Ship::Ship(int x, int y):_x(x), _y(y)
{}

int Ship::getX()
{
	return _x;
}

int Ship::getY()
{
	return _y;
}