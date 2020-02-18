#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Ship.h"
class Player
{
public:
	//The computer
	Player();

	//The user
	Player(std::string);
	int getShipX(int);
	int getShipY(int);
private:
	std::vector<Ship> ships;
	std::string name;
	
};



#endif // !PLAYER_H
