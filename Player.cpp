#include "Player.h"
#include <chrono>
#include <iostream>

//This will be the computer
Player::Player() : _name("NPC")
{
	//This code creates 5 ships that will be given random coordinate points
	//	then adds them to the vector of ships
	srand(time(NULL));
	Ship newShip(std::rand() % 10, std::rand() % 10); //change both "10" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip2(std::rand() % 10, std::rand() % 10); //change both "10" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip3(std::rand() % 10, std::rand() % 10); //change both "10" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip4(std::rand() % 10, std::rand() % 10); //change both "10" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip5(std::rand() % 10, std::rand() % 10); //change both "10" to the size of grid x-axis and the y-axis once we've decided what the size is
	_ships.push_back(newShip);
	_ships.push_back(newShip2);
	_ships.push_back(newShip3);
	_ships.push_back(newShip4);
	_ships.push_back(newShip5);
}

//This will be the user
Player::Player(std::string userName) : _name(userName)
{}

int Player::getShipX(int num)
{
	return _ships[num].getX();
}

int Player::getShipY(int num)
{
	return _ships[num].getY();
}

std::string Player::getName()
{
	return _name;
}

int Player::getNumOfShips()
{
	return _ships.size();
}
void Player::createShips()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter x-coordinate and y-coordinate of ship #" << (i+1) << std::endl;
		std::cin >> x;
		std::cin >> y;
		Ship newShip(x, y);
		_ships.push_back(newShip);
	}
}

bool Player::haveISunkAShip()
{

}

bool Player::playerfire(Player a, std::pair<int, int> target)
{
	return a.isItAHit(target);
}

bool Player::isItAHit(std::pair<int, int> target)
{
	for (auto v : _ships)
	{
		if (v.amIHit(target))
		{
			return true;
		}
	}

	return false;
}