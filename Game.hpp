//
//  Game.hpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "Board.hpp"
#include "Player.hpp"

#include <stdio.h>
enum state {P1_WIN, P2_WIN, UNFINISHED};

class Game
{
    private:
        Player p1;
        Board p1Board;
        Player p2;
        Board p2Board;
    public:
        bool playGame();
        void startGame();
        void initializeBoard(Board &b);
        void initializeBoardAuto(Board &b, bool print=true);
        state gameCondition();
        void printGameState(Player p);
        void getNextMove(Board &b);
        void getNextMoveAuto(Board &b);
        std::string getSquare();
        void switchPlayers(std::string playerFrom, std::string playerTo);
};

#endif /* Game_hpp */
