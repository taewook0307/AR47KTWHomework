#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"
#include <conio.h>
#include <Windows.h>

Player::Player()
{

}

bool Player::Fire = false;

void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5√ ∞£ ∏ÿ√·¥Ÿ.
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;

	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;

	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;

	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;

	case 'x':
	case 'X':
		Fire = true;
		Bullet::GetMainBullet().SetPos({ Pos.X + 1, Pos.Y });
		Bullet::BulletFire();
		break;

	default:
		break;
	}

	Sleep(InterFrame);
}
