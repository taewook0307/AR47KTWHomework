#pragma once

#include "ConsoleGameMath.h"
#include "GameObject.h"

class Bullet;
class Player : public GameObject
{
public:
	Player()
	{
		Ch = '*';
	}

	void SetBulletPtr(Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

	Bullet* GetBulletPtr() const
	{
		return BulletPtr;
	}

	void Input();

	void ShootCheck();

protected:

private:
	inline void ShootCount()
	{
		++FireCount;
	}

	Bullet* BulletPtr;
	int FireCount = 0;
};

