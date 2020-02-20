//
//  Player.hpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <string>
#include <stdio.h>
class Player
{
    private:
        std::string name;
        bool isAI;
        int playerNumber;
    public:
        Player();
        Player(std::string n, bool a, int num);
        Player(const Player &oldPlayer);
        Player& operator=(const Player &obj);
        ~Player() {return;};
        std::string getName();
        bool isPlayerAI();
        int getPlayerNum();
        void setName(std::string n);
        void setAuto(bool a);
        void setPlayerNum(int n);
};
#endif /* Player_hpp */
