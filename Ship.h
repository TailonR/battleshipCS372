#ifndef SHIP_H
#define SHIP_H

class Ship
{
public:
	Ship(int, int);
	int getX();
	int getY();
private:
	int _x;
	int _y;
};

#endif // !SHIP_H
