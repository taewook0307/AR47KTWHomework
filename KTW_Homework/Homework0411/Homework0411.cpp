#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Player.h"
#include "Item.h"
#include "Bomb.h"
#include "GameEnum.h"
#include <conio.h>

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	ConsoleObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

