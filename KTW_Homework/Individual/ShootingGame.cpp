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
		ArrBullet[0].Render();
		ArrBullet[0].PosUpdate();
		GameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Act(ArrBullet);
	}
}