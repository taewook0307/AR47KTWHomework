#pragma once

#include "Position.h"

class GameObject
{
public:
	inline void SetPos(Position _Pos)
	{
		Pos.X = _Pos.X;
		Pos.Y = _Pos.Y;
	}

	inline Position GetPos() const
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
	Position Pos;
	char Ch = ' ';

private:
	bool UpdateValue = true;
};

