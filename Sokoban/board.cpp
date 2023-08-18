#include "board.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "vector2.h";
#include "gameManager.h"

using namespace std;
int currentLevel[ROWS][COLS];

vector2::Vector2 playerPosition, nextPosition, boxNextPosition, lastPosition;

vector2::Vector2 board::generateBoard(int _level[ROWS][COLS], bool _ruleValidation)
{
    int goalCount;
    goalCount = 0;

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

            if ((type)_level[x][y] == BoxOnGoal) goalCount++;
            if(!_ruleValidation) cout << setw(2) << getPiece(_level[x][y]);
        }

        if (!_ruleValidation) cout << "\n";
    }

    gameManager::setGoalAmount(goalCount, true);
    return p;
}

void board::loadLevel(int _level[ROWS][COLS])
{
    int goalCount;
    goalCount = 0;

    for (int x = 0; x < COLS; x++)
    {
        for (int y = 0; y < ROWS; y++)
        {
            if ((type)_level[x][y] == Goal) goalCount++;
            currentLevel[x][y] = _level[x][y];
        }
    }
    gameManager::setGoalAmount(goalCount, false);
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

void board::playerMovement(vector2::Vector2 _nextPosition, vector2::Vector2 _lastPosition)
{
    currentLevel[_nextPosition.x][_nextPosition.y] = (int)Player;
    currentLevel[_lastPosition.x][_lastPosition.y] = (int)Empty;
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

    // player can move if there is no wall front, and if they arent pushing a box into another box
    if (tileTypeNext != Wall)
    {
        if (tileTypeNext == Box)
        {
            if (tileTypeBoxNext != Box && tileTypeBoxNext != Wall && tileTypeBoxNext != BoxOnGoal)
            {
                currentLevel[lastPosition.x][lastPosition.y] = tileTypeCurrent == PlayerOnGoal ? (int)Goal : (int)Empty;
                currentLevel[nextPosition.x][nextPosition.y] = (int)Player;
                
                if (tileTypeBoxNext == Goal) currentLevel[boxNextPosition.x][boxNextPosition.y] = (int)BoxOnGoal;
                else currentLevel[boxNextPosition.x][boxNextPosition.y] = (int)Box;
            }
        }

        else if (tileTypeNext == Goal || tileTypeNext == BoxOnGoal)
        {
            if ((tileTypeNext == BoxOnGoal && tileTypeBoxNext != Wall))
            {
                currentLevel[lastPosition.x][lastPosition.y] = (int)Empty;
                currentLevel[nextPosition.x][nextPosition.y] = (int)PlayerOnGoal;
                if(tileTypeNext == BoxOnGoal) currentLevel[boxNextPosition.x][boxNextPosition.y] = (int)Box;
            }
        }

        else
        {
            if (tileTypeCurrent == PlayerOnGoal)
            {
                currentLevel[lastPosition.x][lastPosition.y] = (int)Goal;
                currentLevel[nextPosition.x][nextPosition.y] = (int)Player;
            }
            else playerMovement(nextPosition, lastPosition);
        }
    }
    return false;
}

vector2::Vector2 board::displayBoard(bool _validate)
{
    return generateBoard(currentLevel, _validate);
}