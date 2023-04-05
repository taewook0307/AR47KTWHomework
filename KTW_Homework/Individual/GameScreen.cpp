#include <iostream>

#include "GameScreen.h"

GameScreen GameScreen::MainScreen;

GameScreen::GameScreen()
{

}

void GameScreen::ScreenSetting()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Screen[y][x] = Floor;
		}
	}
}

void GameScreen::ScreenPrint()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Screen[y][x]);
		}
		printf_s("\n");
	}
}

bool GameScreen::ScreenOver(Location _Pos)
{
	if (_Pos.X < 0)
	{
		return true;
	}

	if (_Pos.Y < 0)
	{
		return true;
	}

	if (_Pos.X >= ScreenXSize)
	{
		return true;
	}

	if (_Pos.Y >= ScreenYSize)
	{
		return true;
	}

	return false;
}

void GameScreen::ScreenRenderAnything(Location _Pos, char _Ch)
{
	Screen[_Pos.Y][_Pos.X] = _Ch;
}