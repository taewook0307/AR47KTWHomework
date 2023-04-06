#include <iostream>

#include "GameScreen.h"
#include "Player.h"
#include "Bullet.h"
#include "ShootingGame.h"

Player ShootingGame::NewPlayer;
Bullet ShootingGame::ArrBullet[BulletCount];

void ShootingGame::GameSetting()
{
	GameScreen::GetMainScreen().ScreenSetting();

	ShootingGame::NewPlayer.SetPos(GameScreen::GetMainScreen().GetScreenSize().Half());

	for (size_t i = 0; i < BulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void ShootingGame::GameStart()
{
	NewPlayer.Render();
	GameScreen::GetMainScreen().ScreenPrint();

	while (true)
	{
		system("cls");

		GameScreen::GetMainScreen().ScreenSetting();

		NewPlayer.Render();
		for (size_t i = 0; i < BulletCount; i++)
		{
			if (true == ArrBullet[i].GetUpdate())
			{
				ArrBullet[i].Render();
			}
		}
		GameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Act(ArrBullet);
		ArrBullet[NewPlayer.GetShootCount() - 1].PosUpdate();
		for (size_t i = 0; i < BulletCount; i++)
		{
			if (true == ArrBullet[i].GetUpdate())
			{
				ArrBullet[i].PosUpdate();
			}
		}
	}
}