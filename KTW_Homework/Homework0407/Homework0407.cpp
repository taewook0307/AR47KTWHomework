#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include "Bomb.h"
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include <conio.h>

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
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

