#include <GameEngineConsole/ConsoleGameScreen.h>
#include "Bullet.h"

void Bullet::Update()
{
	bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(Pos);
	if (false == ScreenOverCheck)
	{
		--Pos.Y;
	}
	return;
}