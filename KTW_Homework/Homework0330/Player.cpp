#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

Player::Player()
{

}

void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5초간 멈춘다.
		Sleep(InterFrame);
		// 일부러 멈추게 만들겁니다.
		// continue; 반복문 내부에서만 사용가능
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
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}

void Player::CheckShoot()
{
	BulletPtr[ShootCount].SetPos(Pos);
	BulletPtr[ShootCount].FireOn();
}