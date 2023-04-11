#include <iostream>
#include <conio.h>
#include <Windows.h>

#include <GameEngineConsole/ConsoleGameScreen.h>

#include "Player.h"
#include "Bullet.h"
#include "ShootingGame.h"

Player ShootingGame::NewPlayer;
Bullet ShootingGame::ArrBullet[BulletCount];

void ShootingGame::GameSetting()
{
	ConsoleGameScreen::GetMainScreen().SetScreenSize(int2 { 21, 11 });
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	ShootingGame::NewPlayer.SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

	for (size_t i = 0; i < BulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void ShootingGame::GameStart()
{
	NewPlayer.Render();
	ConsoleGameScreen::GetMainScreen().ScreenPrint();

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		NewPlayer.Render();
		for (size_t i = 0; i < BulletCount; i++)
		{
			if (true == ArrBullet[i].IsUpdate())
			{
				ArrBullet[i].Render();
			}
		}
		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		if (0 == _kbhit())
		{
			Sleep(300);
		}

		NewPlayer.Act(ArrBullet);
		ArrBullet[NewPlayer.GetShootCount() - 1].PosUpdate();
		for (size_t i = 0; i < BulletCount; i++)
		{
			if (true == ArrBullet[i].IsUpdate())
			{
				ArrBullet[i].PosUpdate();
			}
		}
	}
}