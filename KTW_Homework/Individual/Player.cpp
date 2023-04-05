#include <conio.h>
#include <iostream>

#include <Windows.h>

#include "GameScreen.h"
#include "Player.h"
#include "Bullet.h"

void Player::Render()
{
	GameScreen::GetMainScreen().ScreenRenderAnything(Pos, Ch);
}

void Player::Act(Bullet* _Bullet)
{
	if (0 == _kbhit())
	{
		Sleep(200);

		return;
	}

	char InputKey = _getch();

	Location NextPos;

	switch (InputKey)
	{
	case 'a':
	case 'A':
		NextPos = { Pos.X - 1, Pos.Y };
		if (false == GameScreen::GetMainScreen().ScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = { Pos.X + 1, Pos.Y };
		if (false == GameScreen::GetMainScreen().ScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = { Pos.X, Pos.Y - 1 };
		if (false == GameScreen::GetMainScreen().ScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = { Pos.X, Pos.Y + 1 };
		if (false == GameScreen::GetMainScreen().ScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		_Bullet[0].On();
		_Bullet[0].SetPos(Pos);
		break;
	default:
		break;
	}
}