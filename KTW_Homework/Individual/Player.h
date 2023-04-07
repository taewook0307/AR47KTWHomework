#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class GameObject;
class Bullet;
class Player : public ConsoleGameObject
{
public:
	Player()
	{
		RenderChar = '*';
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

