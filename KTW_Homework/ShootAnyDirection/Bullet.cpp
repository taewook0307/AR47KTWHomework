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

void Bullet::SetBulletShape(char _Value)
{
	if (true == Fire && GetBulletDirection() == 'L')
	{
		BulletShape = '<';
	}

	if (true == Fire && GetBulletDirection() == 'R')
	{
		BulletShape = '>';
	}

	if (true == Fire && GetBulletDirection() == 'U')
	{
		BulletShape = '^';
	}

	if (true == Fire && GetBulletDirection() == 'D')
	{
		BulletShape = 'v';
	}
}

void Bullet::Render()
{
	SetBulletShape(GetBulletDirection());

	if (true == Fire)
	{
		Screen::GetMainScreen().SetScreenCharacter(Pos, GetBulletShape());
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