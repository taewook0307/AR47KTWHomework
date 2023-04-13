#include <conio.h>
#include <iostream>
#include <Windows.h>

#include <GameEngineConsole/ConsoleGameScreen.h>

#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Player.h"
#include "Bullet.h"
#include "ShootingGame.h"

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
		Sleep(200);

		return;
	}

	char InputKey = _getch();

	int2 NextPos;

	switch (InputKey)
	{
	case 'a':
	case 'A':
		NextPos = Pos + int2::Left;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos + int2::Right;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos + int2::Up;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos + int2::Down;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
	{
		if (ShootBulletCount < 10)
		{
			Bullet* NewBullet = ConsoleObjectManager::CreateConsoleObject<Bullet>(ObjectOrder::Bullet);
			NewBullet->SetPos(Pos);
			++ShootBulletCount;
		}
		break;
	}
	case 'r':
	case 'R':
		ShootBulletCount = 0;
		break;
	default:
		break;
	}
}