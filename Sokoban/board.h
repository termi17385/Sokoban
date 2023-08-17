#pragma once

const int ROWS = 10;
const int COLS = 10;

#include <string>

class vector2
{
public:
    int x = 0;
    int y = 0;
};

class board
{
private:
    vector2 generateBoard(int _level[ROWS][COLS]);
    char getPiece(int _pieceId);
    bool moveUp();
public:
    enum type : int
    {
        Wall   = -1,
        Empty  =  0,
        Goal   =  1,
        Box    =  2,
        Player =  3
    };
    
    void displayBoard();

    
};