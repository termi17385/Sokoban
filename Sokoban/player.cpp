#include "player.h"
#include "board.h"
#include <iostream>

vector2::Vector2 player::getMoveDirection(char _key)
{
	vector2::Vector2 dir{};
	vector2 v;
	v.initialiseVectors();

	switch (_key)
	{
		case 'w':
			dir = v.up;
			break;
		case 'a':
			dir = v.left;
			break;
		case 's':
			dir = v.down;
			break;
		case 'd':
			dir = v.right;
			break;
	}

	return dir;
}

void player::move(vector2::Vector2 _position, board _b)
{
	char key;
	currentPosition = _position;

	std::cout << "\nEnter a key to move the player (w,a,s or d): ";
	std::cin >> key;

	vector2::Vector2 moveDirection = getMoveDirection(key);
	_b.processMovement(moveDirection, currentPosition);
	std::cout << "\n";
}