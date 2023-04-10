#include "Bomb.h"
#include <GameEngineConsole/ConsoleGameScreen.h>

Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (0 >= --BoomCount)
	{
		Off();
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();

	if (6 >= BoomCount)
	{
		int2 Pos = GetPos();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X + 1, Pos.Y }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X - 1, Pos.Y }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y + 1 }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y - 1 }, '@');
	}

	if (2 >= BoomCount)
	{
		int2 Pos = GetPos();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X + 2, Pos.Y }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X - 2, Pos.Y }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y + 2 }, '@');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y - 2 }, '@');
	}
}