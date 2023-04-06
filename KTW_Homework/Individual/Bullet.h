#pragma once

#include "Location.h"

class Bullet
{
public:
	inline void SetPos(Location _Pos)
	{
		Pos.X = _Pos.X;
		Pos.Y = _Pos.Y;
	}

	inline Location GetPos() const
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

	inline void PosUpdate()
	{
		if (false == GameScreen::GetMainScreen().ScreenOver(Pos))
		{
			--Pos.Y;
		}
		return;
	}

	void Render();

private:
	Location Pos;
	const char Ch = '^';
	bool UpdateValue = false;
};

