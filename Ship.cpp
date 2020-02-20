//
//  Ship.cpp
//  BattleShipR
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//

#include "Ship.hpp"
#include "Constants.h"
#include <iostream>

using std::cout;

// one constructor initializes a ship if only size and name are spcified
Ship::Ship(int size, std::string n)
{
    shipSize=size;
    name = n;
    shipSquares=new char[shipSize];
    for (int i=0; i<shipSize; i++)
        shipSquares[i]=isSAFE; //initialize all ship squares to '_', no hit
    xpos=-1; //indicates that the ship has not been placed yet
    ypos=-1; //indicates that the ship has not been placed yet
    isSunk=false; //since ship is new, it is not yet sunk
    isHorizontal=true;
}

// ship can also be placed when it is initialized
Ship::Ship(int size, std::string n, int x, int y, bool s, bool h)
{
    shipSize=size;
    name = n;
    xpos=x;
    ypos=y;
    isSunk=s;
    isHorizontal=h;
    shipSquares=new char[shipSize];
    for (int i=0; i<shipSize; i++)
        shipSquares[i]=isSAFE; //initialize all ship squares to '_', no hit
}


// copy constructor
Ship::Ship(const Ship &oldShip)
{
    shipSize=oldShip.getSize();
    name = oldShip.getName();
    shipSquares=new char[shipSize];
    for (int i=0; i<shipSize; i++)
        shipSquares[i]=oldShip.shipSquares[i];
    xpos=oldShip.getX();
    ypos=oldShip.getY();
    isSunk=oldShip.isShipSunk();
    isHorizontal=oldShip.isShipHorizontal();
}

// copy assignment operator
Ship& Ship::operator=(const Ship &right)
{
    if (this!=&right)
    {
        shipSize=right.getSize();
        name = right.getName();
        xpos=right.getX();
        ypos=right.getY();
        isSunk=right.isShipSunk();
        isHorizontal=right.isShipHorizontal();

        if (shipSize>0) // delete old memory before new memory
            delete [] shipSquares;
        shipSquares = new char[shipSize];
        for (int i=0; i<shipSize; i++)
            shipSquares[i]=right.shipSquares[i];


    }
    return *this;

}

// destructor deletes dynamically allocated memory
Ship::~Ship()
{
    if (shipSize > 0)
        delete [] shipSquares;
}

// getter methods
int Ship::getSize() const
{
    return shipSize;
}

int Ship::getX() const
{
    return xpos;
}

int Ship::getY() const
{
    return ypos;
}

bool Ship::isShipSunk() const
{
    return isSunk;
}

bool Ship::isShipHorizontal() const
{
    return isHorizontal;
}

std::string Ship::getName() const
{
    return name;
}

// set position
void Ship::setPosition(int x, int y, bool h)
{
    xpos=x;
    ypos=y;
    isHorizontal=h;
    return;
}

// print ship to console for visualization (only used for debugging)
void Ship::printShip()
{
    for (int i=0; i<shipSize; i++)
        cout<<shipSquares[i]<<" ";
    cout<<"\n";
    return;
}


// function to record hit on ship, return false if no hit, true if hit
// Note: hitX = location on lettered axis, hitY = location on numbered axis
bool Ship::recordHits(int hitX, int hitY)
{
    //check to make sure that the hit is located on the ship, return if not
    if ((isHorizontal & (hitX<xpos || hitX>=xpos+shipSize
                                                        || hitY!=ypos))
        || (!isHorizontal & (hitY<ypos || hitY>=ypos+shipSize
                                                        || hitX!=xpos)))
        return false; //return false because it was not a hit
    else // if there is a hit, record it on the ship
    {
        if (isHorizontal)
            shipSquares[hitX-xpos]=isHIT;
        else
            shipSquares[hitY-ypos]=isHIT;
    }

    //determine whether the ship has been sunk
    //Stay false but if sunk goes true
    //Add hangman
    //may be changed
    isSunk=true;
    for (int i=0; i<shipSize; i++)
        if (shipSquares[i]==isSAFE)
            isSunk=false;

    return true;
}
