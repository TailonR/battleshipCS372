#include "Player.h"
#include <chrono>

//This will be the computer
Player::Player()
{
	srand(time(NULL));
	Ship newShip(std::rand() % 1, std::rand() % 1); //change both "1" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip2(std::rand() % 1, std::rand() % 1); //change both "1" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip3(std::rand() % 1, std::rand() % 1); //change both "1" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip4(std::rand() % 1, std::rand() % 1); //change both "1" to the size of grid x-axis and the y-axis once we've decided what the size is
	Ship newShip5(std::rand() % 1, std::rand() % 1); //change both "1" to the size of grid x-axis and the y-axis once we've decided what the size is
	ships.push_back(newShip);
	ships.push_back(newShip2);
	ships.push_back(newShip3);
	ships.push_back(newShip4);
	ships.push_back(newShip5);
}

//This will be the user
Player::Player(std::string userName) : name(userName)
{}