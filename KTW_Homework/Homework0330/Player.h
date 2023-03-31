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
	
	inline void CountShoot()
	{
		++ShootCount;
	}

	inline int GetShootCount() const
	{
		return ShootCount;
	}

	void Input();

	void Render();

	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}


	void CheckShoot();

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Bullet* BulletPtr;

	int ShootCount = 0;		// ÇÃ·¹ÀÌ¾î º»ÀÎÀÌ ÃÑÀ» ½ð È½¼ö
};

