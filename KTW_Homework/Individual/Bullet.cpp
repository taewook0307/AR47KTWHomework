#include <GameEngineConsole/ConsoleGameScreen.h>
#include "Bullet.h"

void Bullet::PosUpdate()
{
	if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(Pos))
	{
		--Pos.Y;
	}
	return;
}