#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

int main()
{
	Player NewPlayer = Player();
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenAnything(NewPlayer.GetPos(), '*');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
	}
}