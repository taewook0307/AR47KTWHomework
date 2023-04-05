#pragma once

#include "Location.h"

class Bullet;
class Player
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

	void Render();

	void Act(Bullet* _Bullet);
protected:

private:
	Location Pos;
	const char Ch = '*';
};

