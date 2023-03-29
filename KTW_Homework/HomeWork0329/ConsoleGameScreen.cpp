#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;

ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = Floor;
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}

	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenAnything(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;
}