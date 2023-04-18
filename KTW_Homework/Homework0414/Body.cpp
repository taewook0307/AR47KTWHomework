#include "Body.h"
#include "Head.h"
#include "GameEnum.h"

#include <vector>
#include <list>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

// 배열을 이용해서 맵의 빈공간을 찾아보관한 후 그 배열에서 랜덤을 돌림
// 수정

Body::Body() 
{
	RenderChar = 'F';

	SetPos(MapCheck());
}

Body::~Body() 
{
}

int2 Body::MapCheck()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	int FullSize = ScreenSize.X * ScreenSize.Y;

	std::vector<std::vector<bool>> Map;

	Map.resize(ScreenSize.Y);
	for (int i = 0; i < Map.size(); i++)
	{
		Map[i].resize(ScreenSize.X);
	}

	std::list<ConsoleGameObject*> HeadGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Head);
	for (ConsoleGameObject* HeadPtr : HeadGroup)
	{
		if (nullptr == HeadPtr)
		{
			continue;
		}
		int2 HeadPos = HeadPtr->GetPos();

		Map[HeadPos.Y][HeadPos.X] = true;
	}

	std::list<ConsoleGameObject*> BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);
	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}
		int2 BodyPos = BodyPtr->GetPos();

		Map[BodyPos.Y][BodyPos.X] = true;
	}

	std::vector<int2> MapBlank;

	MapBlank.reserve(FullSize);

	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
			if (false == Map[j][i])
			{
				MapBlank.push_back({ i, j });
			}
		}
	}

	int R = GameEngineRandom::MainRandom.RandomInt(0, MapBlank.size() - 1);

	return MapBlank[R];
}