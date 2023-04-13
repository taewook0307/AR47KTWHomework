#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

	Player();

	void Update() override;
protected:

private:
	int ShootBulletCount = 0;
};

