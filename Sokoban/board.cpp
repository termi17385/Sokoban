#include "board.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "vector2.h";

using namespace std;
int currentLevel[ROWS][COLS];

vector2::Vector2 playerPosition, nextPosition, boxNextPosition, lastPosition;

vector2::Vector2 board::generateBoard(int _level[ROWS][COLS])
{
    vector2::Vector2 p{};
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

void board::loadLevel(int _level[ROWS][COLS])
{
    for (int x = 0; x < COLS; x++)
    {
        for (int y = 0; y < ROWS; y++)
        {
            currentLevel[x][y] = _level[x][y];
        }
    }
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
    case BoxOnGoal:
        return '@';
    case Player:
        return 'P';
    case PlayerOnGoal:
        return 'P';
    default:
        return 'E';
    }

    return 'E';
}

bool board::processMovement(vector2::Vector2 _position, vector2::Vector2 _currentPosition)
{
    lastPosition = _currentPosition;
    nextPosition = lastPosition;

    nextPosition.x += _position.x;
    nextPosition.y += _position.y;
    boxNextPosition = nextPosition;

    boxNextPosition.x += _position.x;
    boxNextPosition.y += _position.y;

    type tileTypeNext = (type)currentLevel[nextPosition.x][nextPosition.y];
    type tileTypeBoxNext = (type)currentLevel[boxNextPosition.x][boxNextPosition.y];
    type tileTypeCurrent = (type)currentLevel[lastPosition.x][lastPosition.y];

    if (tileTypeNext != Wall)
    {
        // We have a box infront of us, we should push it
        // but it cannot move if there is a wall infront

        // Handles Box Logic
        if ((tileTypeNext == Box || tileTypeNext == BoxOnGoal) && tileTypeBoxNext != Wall)
        {
            if (tileTypeBoxNext == Goal) currentLevel[boxNextPosition.x][boxNextPosition.y] = (int)BoxOnGoal;
            else currentLevel[boxNextPosition.x][boxNextPosition.y] = (int)Box;

            if(tileTypeNext == BoxOnGoal || tileTypeNext == Goal) currentLevel[nextPosition.x][nextPosition.y] = (int)PlayerOnGoal;
            else currentLevel[nextPosition.x][nextPosition.y] = (int)Player;
            
            if(tileTypeCurrent == BoxOnGoal || tileTypeCurrent == PlayerOnGoal) currentLevel[lastPosition.x][lastPosition.y] = (int)Goal;
            else currentLevel[lastPosition.x][lastPosition.y] = (int)Empty;
        }
        else if (tileTypeNext != Box)
        {
            if (tileTypeNext == BoxOnGoal || tileTypeNext == Goal) currentLevel[nextPosition.x][nextPosition.y] = (int)PlayerOnGoal;
            else currentLevel[nextPosition.x][nextPosition.y] = (int)Player;

            if (tileTypeCurrent == BoxOnGoal || tileTypeCurrent == PlayerOnGoal) currentLevel[lastPosition.x][lastPosition.y] = (int)Goal;
            else currentLevel[lastPosition.x][lastPosition.y] = (int)Empty;
        }

        return true;
    }
    else return false;
}

vector2::Vector2 board::displayBoard()
{
    return generateBoard(currentLevel);
}