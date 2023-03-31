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
		// 0.5�ʰ� �����.
		Sleep(InterFrame);
		// �Ϻη� ���߰� ����̴ϴ�.
		// continue; �ݺ��� ���ο����� ��밡��
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
		if (ShootCount < Bullet::ArrBulletCount)		// �ڽ��� �� �Ѿ��� ���� ��ü �Ѿ� ������ �������
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
	BulletPtr[GetShootCount()].SetPos(Pos);
	BulletPtr[GetShootCount()].FireOn(GetPlayerDirection());
}