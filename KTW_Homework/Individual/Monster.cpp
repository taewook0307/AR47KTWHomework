#include <GameEngineConsole/ConsoleGameScreen.h>

#include "Monster.h"

bool Monster::IsGameUpdate = true;

Monster::Monster()
{
	RenderChar = 'M';
}

void Monster::Update()
{
	ConsoleGameObject::Update();

	int2 NextPos;

	if (Dir == 1)
	{
		NextPos = GetPos() + int2::Right;
	}
	else if (Dir == -1)
	{
		NextPos = GetPos() + int2::Left;
	}

	bool ScreenCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);

	if (false == ScreenCheck)
	{
		Pos.X += Dir;
	}
	else
	{
		ChangeDir();
	}
}