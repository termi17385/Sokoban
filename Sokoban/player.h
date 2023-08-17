#pragma once
#include "vector2.h"
#include "board.h"

class player
{
private:
	vector2::Vector2 currentPosition;
	vector2::Vector2 getMoveDirection(char);

public:
	void move(vector2::Vector2 _position, board _b);
};