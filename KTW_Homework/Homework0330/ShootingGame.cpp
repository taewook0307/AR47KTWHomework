#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"
#include "ShootingGame.h"

void ShootingGame::GameProgress()
{
	// 총알이 여러발 나가게 만드세요.

	Player NewPlayer = Player();

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}