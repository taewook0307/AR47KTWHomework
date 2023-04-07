#pragma once

#include <GameEngineConsole/ConsoleGameObject.h>

class Bullet : public ConsoleGameObject
{
public:
	Bullet()
	{
		RenderChar = '^';
	}
	void PosUpdate();

private:
};

