//
//  main.cpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#include "Game.hpp"
#include "Player.hpp"
#include "Utility.hpp"
#include <iostream>

int main()
{
    unsigned seed=0;
    srand(seed);

    bool continueGame=true;

    while (continueGame)
    {
        continueGame = printMenu();
    }
    return 0;

}
