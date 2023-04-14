#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Bomb.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
	{
		NextPos = Pos;
		NextPos.X -= 1;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		if (false == ScreenOverCheck)
		{
			Pos.X -= 1;
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos = Pos;
		NextPos.X += 1;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		if (false == ScreenOverCheck)
		{
			Pos.X += 1;
		}
		break;
	}
	case 'w':
	case 'W':
	{
		NextPos = Pos;
		NextPos.Y -= 1;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		if (false == ScreenOverCheck)
		{
			Pos.Y -= 1;
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPos = Pos;
		NextPos.Y += 1;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		if (false == ScreenOverCheck)
		{
			Pos.Y += 1;
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}
