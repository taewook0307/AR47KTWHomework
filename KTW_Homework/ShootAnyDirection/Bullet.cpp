#include "Bullet.h"
#include "Screen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];


void Bullet::AllRender()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}

void Bullet::AllUpdate()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire && GetBulletDirection() == 'L')
	{
		Screen::GetMainScreen().SetScreenCharacter(Pos, '<');
	}

	if (true == Fire && GetBulletDirection() == 'R')
	{
		Screen::GetMainScreen().SetScreenCharacter(Pos, '>');
	}

	if (true == Fire && GetBulletDirection() == 'U')
	{
		Screen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}

	if (true == Fire && GetBulletDirection() == 'D')
	{
		Screen::GetMainScreen().SetScreenCharacter(Pos, 'v');
	}
}

void Bullet::Update()
{
	if (true == Fire && GetBulletDirection() == 'L')
	{
		--Pos.X;
	}

	if (true == Fire && GetBulletDirection() == 'R')
	{
		++Pos.X;
	}

	if (true == Fire && GetBulletDirection() == 'U')
	{
		--Pos.Y;
	}

	if (true == Fire && GetBulletDirection() == 'D')
	{
		++Pos.Y;
	}
}