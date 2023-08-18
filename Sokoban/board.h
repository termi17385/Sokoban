#include <string>
#include "vector2.h";

#pragma once

#pragma region Constants
const int ROWS = 10;
const int COLS = 10;
#pragma endregion

enum type : int
{
    PlayerOnGoal = -3,
    BoxOnGoal = -2,
    Wall = -1,
    
    Empty = 0,

    Goal = 1,
    Box = 2,
    Player = 3
};


class board
{
private:
    vector2::Vector2 generateBoard(int _level[ROWS][COLS], bool _ruleValidation = false);
    char getPiece(int _pieceId);
    void playerMovement(vector2::Vector2 _nextPosition, vector2::Vector2 _lastPosition);

public:
    vector2::Vector2 displayBoard(bool);
    bool processMovement(vector2::Vector2 _position, vector2::Vector2 _currentPosition);
    void loadLevel(int _level[ROWS][COLS]);
};