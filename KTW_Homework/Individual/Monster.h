#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class Monster : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

	Monster();

	void Update() override;

	
protected:

private:
	int Dir = 1;

	void ChangeDir()
	{
		Dir *= -1;
	}
};

