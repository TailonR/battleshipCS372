//
//  Constants.h
//  BattleShipR
//
//  Created by Shihhsien Wu on 2/19/20.
//  Copyright © 2020 Shihhsien Wu. All rights reserved.
//
#include <string>
#ifndef Constants_h
#define Constants_h
// Game Constants
const int SHIP_NUM = 5;
const int BOARD_Size = 10;
const int BOARD_SPACES = 100;
const int SHIP_SIZE[SHIP_NUM] = {5, 4, 3, 3, 2};
const int TOTAL_SHIP_SPACES = 17;
const std::string SHIP_NAMES[SHIP_NUM] =
            {"Carrier","Battleship","Cruiser","Submarine","Destroyer"};

// board value constants
const char isHIT = 'X';
const char isMISS = 'O';
const char isWATER = ' ';
const char isSAFE = '_';
const char isUNKNOWN = ' ';

// to convert char to board position
const int LETTER_CHAR_OFFSET=65;
const int NUMBER_CHAR_OFFSET=48;

// consts for input validation
const int ASCII_INT_MIN=48;
const int ASCII_INT_MAX=57;

#endif /* Constants_h */
