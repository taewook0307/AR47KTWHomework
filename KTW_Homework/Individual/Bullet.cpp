#include "ConsoleGameScreen.h"
#include "Bullet.h"

Bullet Bullet::ArrBullet[BulletCount] = {};

Bullet::Bullet()
{
	Ch = '^';
}

void Bullet::BulletAllOff()
{
	for (size_t i = 0; i < BulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void Bullet::BulletAllRender()
{
	for (size_t i = 0; i < BulletCount; i++)
	{
		if (ArrBullet[i].IsUpadate() == false)
		{
			continue;
		}
		else if (ArrBullet[i].IsUpadate() == true)
		{
			ConsoleGameScreen::GetMainScreen().ScreenRenderSomething(ArrBullet[i].Pos, ArrBullet[i].Ch);
		}
	}
}

void Bullet::BulletAllUpdate()
{
	for (size_t i = 0; i < BulletCount; i++)
	{
		if (ArrBullet[i].IsUpadate() == false)
		{
			continue;
		}
		ArrBullet[i].UpdatePos();
	}
}