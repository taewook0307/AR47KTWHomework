#include <iostream>
#include "Screen.h"
#include "Player.h"
#include "Bullet.h"
#include "ShootingGame.h"

void ShootingGame::GameProgress()
{
	// �Ѿ��� ������ ������ ���弼��.

	Player NewPlayer = Player();

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	int2 ScreenSize = Screen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		Screen::GetMainScreen().ScreenClear();

		NewPlayer.Render();
		Bullet::AllRender();

		Screen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}