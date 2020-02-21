//
//  Board.cpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#include "hangman.h"
#include "Board.hpp"
#include <iostream>
// Creates the Board
// and fills a vector with the standard ship objects
Board::Board()
{
    for (int i=0; i<BOARD_Size; i++)
        for (int j=0; j<BOARD_Size; j++)
            gameBoard[i][j]=isWATER;

    for (int i=0; i<SHIP_NUM; i++)
        shipVec.push_back(Ship(SHIP_SIZE[i], SHIP_NAMES[i]));
}

// copy constructor - copies old board square by square
Board::Board(const Board &oldBoard)
{
    for (int i=0; i<BOARD_Size; i++)
        for (int j=0; j<BOARD_Size; j++)
            gameBoard[i][j]=oldBoard.gameBoard[i][j];
    shipVec = oldBoard.shipVec;
}

// copy assignment operator - copies old board square by square
Board& Board::operator=(const Board &right)
{
    if (this!=&right)
    {
        for (int i=0; i<BOARD_Size; i++)
            for (int j=0; j<BOARD_Size; j++)
                gameBoard[i][j]=right.gameBoard[i][j];
        shipVec = right.shipVec;
    }

    return *this;

}

// return the number of hits on the board at the moment
int Board::getNumHits()
{
    int count=0;

    for (int i=0; i<BOARD_Size; i++)
        for (int j=0; j<BOARD_Size; j++)
            if (gameBoard[i][j]==isHIT)
                count++;

    return count;
}

// method to print the player version of the board
// (player can only see hits and misses)
void Board::printPrivateBoard()
{
    std::cout<<"  A B C D E F G H I J\n";
    for (int i=0; i<BOARD_Size; i++)
    {
        std::cout<<i<<" ";
        for (int j=0; j<BOARD_Size; j++)
        {
            if (gameBoard[i][j]==isHIT || gameBoard[i][j]==isMISS)
                std::cout<<gameBoard[i][j]<<" ";
            else // non-hit/miss entries
                std::cout<<isUNKNOWN<<" ";
        }
        std::cout<<std::endl;
    }
}

// method to print the board that the player can see completely
// (usually, the player's own board)
void Board::printPublicBoard()
{
    std::cout<<"  A B C D E F G H I J\n";
    for (int i=0; i<BOARD_Size; i++)
    {
        std::cout<<i<<" ";
        for (int j=0; j<BOARD_Size; j++)
        {
            std::cout<<gameBoard[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}

//return the value of a space
char Board::getSpaceValue(int x, int y)
{
    return gameBoard[y][x];
}

// record a hit on the board by attempting to record a hit on every ship
// if a ship is hit, change board position to hit and return true
// if no ship is hit, change board position to miss and return false
bool Board::recordHit(int x, int y)
{
    Ship temp;
    for (int i=0; i<SHIP_NUM; i++)
    {
        if (shipVec[i].recordHit(x, y))
        {
            gameBoard[y][x]=isHIT; //record the hit on the board
            //tell the user that they sunk a ship
            if (shipVec[i].isShipSunk())
            {
                std::cout<<"You sunk the "<<shipVec[i].getName()<<"!\n";////////////////////////////////////////////////////////////////
                saveOrRemoveSunkenShip(shipVec[i]);
            }
            

            return true;
        }
    }
    gameBoard[y][x]=isMISS;
    return false;
}

// function to place ship on board
bool Board::shipPlacements(int shipNum, int x, int y, bool isHorizontal)
{
    //if x or y is out of bounds, return false
    if (x>=BOARD_Size || y>=BOARD_Size)
        return false;

    //if ship has already been placed, return false
    if (shipVec[shipNum].getX()>=0 && shipVec[shipNum].getY()>=0)
        return false;

    //loop through the positions required for the ship
    for (int i=0; i<shipVec[shipNum].getSize(); i++)
    {
        //if any of the desired spaces are filled, return false
        if ((isHorizontal && gameBoard[y][x+i]!=isWATER) ||
                            (!isHorizontal && gameBoard[y+i][x]!=isWATER))
            return false;
        //if any of the desired spaces are out of bounds, return false
        if ((isHorizontal && (x+i)>=BOARD_Size) ||
                            (!isHorizontal && (y+i)>=BOARD_Size))
            return false;
    }

    //if the for loop finishes, and all the positions are empty,
    //1. place the Ship in the desired position on the board
    for (int i=0; i<shipVec[shipNum].getSize(); i++)
    {
        if (isHorizontal)
            gameBoard[y][x+i]=isSAFE;
        else
            gameBoard[y+i][x]=isSAFE;
    }

    //2. set the x/y parameters for the Ship object
    shipVec[shipNum].setPosition(x, y, isHorizontal);

    //... and return true
    return true;
}

void Board::saveOrRemoveSunkenShip(Ship & mark)
{
    if (!hangman::playhangman(mark, *this))
    {
        shipVec.erase(shipVec.begin()+4);
        std::cout << "You have lost hangman" << std::endl;
        std::cout << "You have " << shipVec.size() << " ships" << std::endl;
    }
    else
    {
        std::cout << "You have won hangman" << std::endl;
        std::cout << "You have " << shipVec.size() << " ships" << std::endl;
    }
}
