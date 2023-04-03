#pragma once

#include "ConsoleGameMath.h"

class Player
{
public:
	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(int2 _Pos)
	{
		Pos.X = _Pos.X;
		Pos.Y = _Pos.Y;
	}

	char GetCh() const
	{
		return PlayerCh;
	}

	void Input();
protected:

private:
	int2 Pos;
	char PlayerCh = '*';
};

