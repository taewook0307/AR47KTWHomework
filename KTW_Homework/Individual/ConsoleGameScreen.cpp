#include <iostream>

#include "ConsoleGameScreen.h"

ConsoleGameScreen ConsoleGameScreen::MainScreen;

ConsoleGameScreen::ConsoleGameScreen()
{

}

ConsoleGameScreen& ConsoleGameScreen::GetMainScreen()
{
	return MainScreen;
}

void ConsoleGameScreen::Clear()
{
	for (size_t i = 0; i < ScreenYSize; i++)
	{
		for (size_t j = 0; j < ScreenXSize; j++)
		{
			ArrScreen[i][j] = Floor;
		}
	}
}

void ConsoleGameScreen::Render()
{
	for (size_t i = 0; i < ScreenYSize; i++)
	{
		for (size_t j = 0; j < ScreenXSize; j++)
		{
			printf_s("%c", ArrScreen[i][j]);
		}
		printf_s("\n");
	}
}

void ConsoleGameScreen::ScreenRenderSomething(int2 _Pos, char _Ch)
{
	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

bool ConsoleGameScreen::IsScreenOver(int2 _Pos)
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