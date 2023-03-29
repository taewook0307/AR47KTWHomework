#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	inline static Bullet& GetMainBullet()
	{
		return MainBullet;
	}

	inline void SetPos(int2 _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	static void BulletFire();

private:
	static Bullet MainBullet;
	Bullet();
	static int2 Pos;
};

