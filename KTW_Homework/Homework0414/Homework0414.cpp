#include <iostream>
#include <conio.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Player.h"
#include "Bomb.h"
#include "GameEnum.h"

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

