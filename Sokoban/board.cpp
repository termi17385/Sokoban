#include "board.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int LEVEL_ONE[ROWS][COLS] = 
{
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 2, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 3, 0,-1},
    {-1, 0, 0, 1, 0, 2, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 1, 0, 0, 0, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

vector2 playerPosition, nextPosition, lastPosition;

vector2 board::generateBoard(int _level[ROWS][COLS])
{
    vector2 p;
    for (int x = 0; x < COLS; x++)
    {
        for (int y = 0; y < ROWS; y++)
        {
            int i = getPiece(_level[x][y]);
            if (i == 'P')
            {
                p.x = x;
                p.y = y;
            }
            cout << setw(2) << getPiece(_level[x][y]);
        }

        cout << "\n";
    }
    return p;
}

char board::getPiece(int _pieceId)
{
    type pieceType = (type)_pieceId;
    switch (pieceType)
    {
    case Wall:
        return '#';
    case Empty:
        return '.';
    case Goal:
        return 'x';
    case Box:
        return '@';
    case Player:
        return 'P';
    default:
        return 'E';
    }

    return 'E';
}

bool board::moveUp()
{
    // First we check to make sure there isnt a wall above us
    // if we can move we then position the player to space,
    // then remove the prievous position

    lastPosition = playerPosition;
    nextPosition = lastPosition;
    nextPosition.x -= 1;

    if ((type)LEVEL_ONE[nextPosition.x][nextPosition.x] != Wall)
    {
        LEVEL_ONE[nextPosition.x][nextPosition.y] = (int)Player;
        LEVEL_ONE[lastPosition.x][lastPosition.y] = (int)Empty;
        return true;
    }
    else return false;
}

void board::displayBoard()
{
    playerPosition = generateBoard(LEVEL_ONE);
    bool canMove;
    do
    {
        cout << "\n\n";
        canMove = moveUp();
        if(canMove) playerPosition = generateBoard(LEVEL_ONE);
    } 
    while (canMove);
}