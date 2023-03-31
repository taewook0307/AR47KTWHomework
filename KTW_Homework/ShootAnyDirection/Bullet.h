#pragma once
#include "Screen.h"
#include "ShootingGame.h"

class Player;
class Screen;
class Bullet
{
public:
	static const int ArrBulletCount = 10;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	static void AllRender();
	static void AllUpdate();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline char GetBulletDirection()
	{
		return BulletDirection;
	}

	inline bool IsFire() const
	{
		return Fire;
	}

	inline void FireOn(char _Value)
	{
		Fire = true;
		BulletDirection = _Value;
	}

	inline char GetBulletShape() const
	{
		return BulletShape;
	}

	void SetBulletShape(char _Value);

	void Render();

	void Update();
protected:

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	int2 Pos = int2(0, 0);

	char BulletDirection = 'U';
	
	char BulletShape = 'U';
};

