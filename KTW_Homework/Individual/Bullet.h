#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	static const int BulletCount = 10;

	static Bullet& GetArrBullet()
	{
		return *ArrBullet;
	}

	static void AllSecting();

	static void AllRender();

protected:

private:
	static Bullet ArrBullet[BulletCount];

	Bullet();

	void BulletUpdate();
};