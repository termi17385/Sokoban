#include "vector2.h"

void vector2::initialiseVectors()
{
	Vector2 dir{};

	// up
	dir.x = -1;
	dir.y = 0;

	up = dir;

	// down
	dir.x = 1;
	dir.y = 0;

	down = dir;

	// left
	dir.x = 0;
	dir.y = -1;

	left = dir;

	// right
	dir.x = 0;
	dir.y = 1;

	right = dir;
}

vector2::Vector2 vector2::vectorAddition(Vector2 a, Vector2 b)
{
	Vector2 newVector{};
	newVector.x = a.x + b.x;
	newVector.y = a.y + b.y;
	return newVector;
}