#include <conio.h>
#include <Windows.h>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(500);

		return;
	}

	char Ch = _getch();

	int2 Pos2 = { 0, 0 };

	Pos2.SetPos(Pos.X, Pos.Y);

	switch (Ch)
	{
	case 'a':
	case 'A':
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver({ Pos2.X - 1, Pos2.Y }))
		{
			Pos.X -= 1;
		}
		break;

	case 'd':
	case 'D':
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver({ Pos2.X + 1, Pos2.Y }))
		{
			Pos.X += 1;
		}
		break;

	case 'w':
	case 'W':
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver({ Pos2.X, Pos2.Y - 1 }))
		{
			Pos.Y -= 1;
		}
		break;

	case 's':
	case 'S':
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver({ Pos2.X, Pos2.Y + 1 }))
		{
			Pos.Y += 1;
		}
		break;

	case 'f':
	case 'F':
		if (FireCount < Bullet::BulletCount)
		{
			ShootCheck();
			ShootCount();
		}
		break;

	default:
		break;
	}
}

void Player::ShootCheck()
{
	BulletPtr[FireCount].SetPos(Pos);
	BulletPtr[FireCount].On();
}
