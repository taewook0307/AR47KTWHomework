#pragma once

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	inline int2()
	{

	}

	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

