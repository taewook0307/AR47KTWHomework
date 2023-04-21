#include "Item.h"
#include "GameEnum.h"

#include <list>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

Item::Item()
{
	RenderChar = L'◈';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

	SetPos({ X, Y });
}

Item::~Item()
{
}

void Item::Update()
{
	ConsoleGameObject::Render();
}