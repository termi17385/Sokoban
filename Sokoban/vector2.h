#pragma once

class vector2
{
public:
	struct Vector2
	{
		int x;
		int y;
	};
	vector2::Vector2 up;	
	vector2::Vector2 down;	
	vector2::Vector2 left;	
	vector2::Vector2 right;	
	void initialiseVectors();
	/// <summary>
	/// Basic addition of 2 vectors returning a new vector.
	/// </summary>
	static Vector2 vectorAddition(Vector2 a, Vector2 b);
};

