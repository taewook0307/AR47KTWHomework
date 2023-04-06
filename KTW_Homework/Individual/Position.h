#pragma once
class Position
{
public:
	int X = 0;
	int Y = 0;

	Position()
	{

	}

	Position(int _X, int _Y)
		: X(_X)
		, Y(_Y)
	{

	}

	inline Position Half()
	{
		return { X / 2 , Y / 2 };
	}
};
