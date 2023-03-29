#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	static bool GetFire()
	{
		return Fire;
	}

	void Input();
protected:

private:
	static const int InterFrame = 200;

	static bool Fire;

	int2 Pos = int2(0, 0);
};
