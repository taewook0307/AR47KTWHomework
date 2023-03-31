#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Player.h"
#include "Screen.h"
#include "Bullet.h"

Player::Player()
{

}

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();
	
	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		SetPlayerDirection('L');
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == Screen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		SetPlayerDirection('R');
		NextPos = Pos;
		NextPos.X += 1;
		if (false == Screen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		SetPlayerDirection('U');
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == Screen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		SetPlayerDirection('D');
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == Screen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		if (ShootCount < Bullet::ArrBulletCount)		// 자신이 쏜 총알의 수가 전체 총알 수보다 작을경우
		{
			CheckShoot();
			CountShoot();
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	Screen::GetMainScreen().SetScreenCharacter(Pos, '*');
}

void Player::CheckShoot()
{
	BulletPtr[ShootCount].SetPos(Pos);
	BulletPtr[ShootCount].FireOn(GetPlayerDirection());
}