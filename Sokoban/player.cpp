#include "player.h"
#include "board.h"
#include <iostream>
#include "gameManager.h"

vector2::Vector2 player::getMoveDirection(char _key)
{
	vector2::Vector2 dir{};
	vector2 v;
	v.initialiseVectors();

	switch (_key)
	{
		case 'W':
		case 'w':
			dir = v.up;
			break;

		case 'A':
		case 'a':
			dir = v.left;
			break;

		case 'S':
		case 's':
			dir = v.down;
			break;

		case 'D':
		case 'd':
			dir = v.right;
			break;

		case 'R':
		case 'r':
			gameManager::restartGame();
			break;
	}

	return dir;
}

void player::move(vector2::Vector2 _position, board _b)
{
	char key{};
	currentPosition = _position;

	std::cout << "\nEnter a key to move the player (w,a,s or d): ";
	std::cin >> key;

	vector2::Vector2 moveDirection = getMoveDirection(key);

	if (!gameManager::restart)
	{
		_b.processMovement(moveDirection, currentPosition);
		std::cout << "\n";
	}
}