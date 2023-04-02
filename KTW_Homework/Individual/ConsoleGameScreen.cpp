#include <iostream>

#include "Position.h"
#include "ConsoleGameScreen.h"

ConsoleGameScreen ConsoleGameScreen::MainScreen;

ConsoleGameScreen::ConsoleGameScreen()
{

}

Position ConsoleGameScreen::GetScreenSize()
{
	return { ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenRenderSomething(const Position& _Pos, char _Ch)
{
	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t i = 0; i < ScreenYSize; i++)
	{
		for (size_t j = 0; j < ScreenXSize; j++)
		{
			ArrScreen[i][j] = Floor;
		}
	}
}

void ConsoleGameScreen::ScreenRender() const
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

bool ConsoleGameScreen::IsScreenOver(Position& _Pos)
{
	if(_Pos.X < 0)
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