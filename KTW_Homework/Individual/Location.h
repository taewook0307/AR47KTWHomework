#pragma once
class Location
{
public:
	int X = 0;
	int Y = 0;

	Location()
	{

	}

	Location(int _X, int _Y)
		: X(_X)
		, Y(_Y)
	{

	}

	inline Location Half()
	{
		return { X / 2 , Y / 2 };
	}
};

