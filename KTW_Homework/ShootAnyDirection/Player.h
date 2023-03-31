#pragma once
#include "Position.h"

class Screen;
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

	inline void SetPlayerDirection(char _Value)
	{
		PlayerDirection = _Value;
	}

	inline char GetPlayerDirection() const
	{
		return PlayerDirection;
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

	char PlayerDirection = 'U';
};
