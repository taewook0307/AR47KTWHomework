#include <iostream>
#include <conio.h>
#include <Windows.h>

#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>

#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ShootingGame.h"

void ShootingGame::GameSetting()
{
	int2 ScreenSize = { 20, 10 };

	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	for (size_t i = 0; i < ShootingGame::AllMonsterCount; i++)
	{
		Monster* NewMonster = ConsoleObjectManager::CreateConsoleObject<Monster>(ObjectOrder::Monster);
		NewMonster->SetPos({ (int)i + 3, 2 });
	}
}

void ShootingGame::GameStart()
{
	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}