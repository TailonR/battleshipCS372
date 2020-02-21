//
//  Ship.hpp
//  BattleShip3
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <string>
class Ship
{
    private:
        char* shipSquares;
        int shipSize;
        int xpos, ypos; //upper left corner of ship
        bool isSunk;
        bool isHorizontal;
        std::string name;


    public:
        Ship(); //default constructor
        Ship(int size,  std::string n); //user defined ship
        Ship(int size, std::string n, int x, int y, bool s, bool h);
        Ship(const Ship &oldShip); //copy constructor
        Ship& operator=(const Ship &right); // copy assignment operator
        ~Ship(); //destructor
        int getSize() const;
        int getX() const;
        int getY() const;
        bool isShipSunk() const;
        bool isShipHorizontal() const;
        std::string getName() const;
        void setPosition(int x, int y, bool h);
        void printShip();
        bool recordHit(int hitLocX, int hitLocY);
};
#endif /* Ship_hpp */
