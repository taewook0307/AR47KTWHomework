#pragma once

#include <GameEngineConsole/ConsoleGameMath.h>

class GameObject
{
public:
	inline void SetPos(int2 _Pos)
	{
		Pos.X = _Pos.X;
		Pos.Y = _Pos.Y;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline void On()
	{
		UpdateValue = true;
	}

	inline void Off()
	{
		UpdateValue = false;
	}

	inline bool GetUpdate() const
	{
		return UpdateValue;
	}

	void Render();

protected:
	int2 Pos;
	char Ch = ' ';

private:
	bool UpdateValue = true;
};

