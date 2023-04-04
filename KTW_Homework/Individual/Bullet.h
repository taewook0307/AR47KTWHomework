#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	static const int BulletCount = 10;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	static void BulletAllUpdate();

	static void BulletAllOff();

	static void BulletAllRender();

	void UpdatePos()
	{
		if (true == IsUpadate())
		{
			--Pos.Y;
		}
	}

protected:

private:
	static Bullet ArrBullet[BulletCount];

	Bullet();
};

