#include "Ship.h"
#include <iostream>

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

void Ship::reduceHits()
{
	_numHits--;
}

int Ship::getHitsLeft()
{
	return _numHits;
}

std::string Ship::sunkenBattleShip()
{
	if (getHitsLeft() == 0)
	{
		return "You've sunk my battleship";
	}
	else
	{
		return "nope";
	}
}
bool Ship::amIHit(std::pair<int, int> target)
{
	if (((getX() == std::get<0>(target)) && (getY() == std::get<1>(target))))
	{
		reduceHits();
		return true;
	}

	return false;
}

