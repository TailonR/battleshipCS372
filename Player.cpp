//
//  Player.cpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#include "Player.hpp"
//default constructor assigns values when no inputs supplied
Player::Player()
{
    name="";
    isAI = false;
    playerNumber = 1;
}

//constructor, takes strings for name, whether the player is automatic, number
Player::Player(std::string n, bool a, int num)
{
    name=n;
    isAI = a;
    playerNumber = num;
}

// copy constructor
Player::Player(const Player &oldPlayer)
{
    name=oldPlayer.name;
    isAI=oldPlayer.isAI;
    playerNumber=oldPlayer.playerNumber;

}

//copy assignment operator
Player& Player::operator=(const Player &obj)
{
    if (this != &obj)
    {
        name = obj.name;
        isAI = obj.isAI;
        playerNumber = obj.playerNumber;
    }

    return *this;
}

//getter functions (name, auto, number)
std::string Player::getName()
{
    return name;
}

bool Player::isPlayerAI()
{
    return isAI;
}

int Player::getPlayerNum()
{
    return playerNumber;
}

//setter functions (name, auto, number)
void Player::setName(std::string n)
{
    name=n;
    return;
}

void Player::setAuto(bool a)
{
    isAI=a;
    return;
}

void Player::setPlayerNum(int n)
{
    playerNumber=n;
    return;
}
