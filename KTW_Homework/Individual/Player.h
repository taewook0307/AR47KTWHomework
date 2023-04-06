#pragma once

#include "GameObject.h"

class GameObject;
class Bullet;
class Player : public GameObject
{
public:
	Player()
	{
		Ch = '*';
	}

	inline int GetShootCount() const
	{
		return ShootCount;
	}

	void Act(Bullet* _Bullet);
protected:

private:
	int ShootCount = 0;

	inline void PlayerShoot()
	{
		++ShootCount;
	}
};

