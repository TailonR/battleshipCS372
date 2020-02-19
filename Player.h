#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <utility>
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
	std::string getName();
	void createShips();
	int getNumOfShips();
	bool playerfire(Player, std::pair<int,int>);
	bool isItAHit(std::pair<int,int>);
	bool haveISunkAShip();
private:
	std::vector<Ship> _ships;
	std::string _name;
	
};



#endif // !PLAYER_H
