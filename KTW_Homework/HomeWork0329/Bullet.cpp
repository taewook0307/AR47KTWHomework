#include "Bullet.h"
#include "Player.h"
#include "ConsoleGameScreen.h"
#include <iostream>

Bullet Bullet::MainBullet;
int2 Bullet::Pos = { 0, 0 };

Bullet::Bullet()
{

}

void Bullet::BulletFire()
{
	if (Player::GetFire())
	{
		while (ConsoleGameScreen::GetMainScreen().IsScreenOver(Pos) == false)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenAnything(Pos, '-');

			system("cls");

			ConsoleGameScreen::GetMainScreen().ScreenPrint();

			int Time = time(0);

			if ((int)time(0) + 1 == Time + 1)
			{
				Pos.X += 1;
				ConsoleGameScreen::GetMainScreen().SetScreenAnything({ Pos.X - 1, Pos.Y }, ConsoleGameScreen::Floor);
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		return;
	}
}