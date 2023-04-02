#pragma once
class Position
{
public:
	int X;
	int Y;

	Position Half()
	{
		return { X / 2, Y / 2 };
	}

	Position()
		: X(0)
		, Y(0)
	{

	}

	Position(int _X, int _Y)
		: X(_X)
		, Y(_Y)
	{

	}
};

