//
//  Board.hpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "Ship.hpp"
#include "Constants.h"
#include <vector>

class Board
{
    private:
        char gameBoard[BOARD_Size][BOARD_Size];
        std::vector<Ship> shipVec;

    public:
        Board();
        Board(const Board &oldBoard);
        Board& operator=(const Board &right);
        ~Board() {return;}; // standard destructor - no dynamically memory
        int getNumHits();
        void printPrivateBoard();
        void printPublicBoard();
        char getSpaceValue(int x, int y);
        bool recordHit(int x, int y);
        bool shipPlacements(int shipNum, int x, int y, bool isHorizontal);
        void saveOrRemoveSunkenShip(Ship &);

};
#endif
