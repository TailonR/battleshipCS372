#ifndef SHIP_H
#define SHIP_H
#include <utility>
#include <string>
class Ship
{
public:
	Ship(int, int);
	int getX();
	int getY();
	bool amIHit(std::pair<int,int>);
	void reduceHits();
	int getHitsLeft();
	std::string sunkenBattleShip();
private:
	int _numHits = 2;
	int _x;
	int _y;
};

#endif // !SHIP_H
