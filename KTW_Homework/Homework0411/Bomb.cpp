#include "Bomb.h"

#include <GameEngineConsole/ConsoleGameScreen.h>

Bomb::Bomb()
{
	RenderChar = L'��';
}

Bomb::~Bomb()
{
}

void Bomb::Init(int _BombPower)
{
	MaxExpPower = _BombPower;
	CurExpPower = 0;
}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (CurExpPower == MaxExpPower)
	{
		Death();
	}

	if (0 >= --BoomCount)
	{
		++CurExpPower;
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();

	for (int i = 0; i < CurExpPower; i++)
	{
		RenderChar = L'��';
		int2 Left = GetPos() + int2::Left * i;
		int2 Right = GetPos() + int2::Right * i;
		int2 Up = GetPos() + int2::Up * i;
		int2 Down = GetPos() + int2::Down * i;

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Left, L'��');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Right, L'��');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Up, L'��');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Down, L'��');
	}
}