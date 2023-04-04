#pragma once

#include "ConsoleGameMath.h"

class GameObject
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
		return Ch;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	bool IsUpadate() const
	{
		return UpdateValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsDeath() const
	{
		return DeathValue;
	}

protected:
	int2 Pos;
	char Ch = '0';
private:
	bool UpdateValue = true;
	bool DeathValue = false;
};

