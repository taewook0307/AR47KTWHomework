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
	RenderChar = L'◇';

	SetPos(MapCheck());
}

Body::~Body() 
{
}

void Body::Update()
{
	if (nullptr != GetPrev())
	{
		int2 MyPos = GetPos();
		int2 MyPrevPos = GetPrevPos();

		// 현재 위치에서 전 위치를 빼서 방향 확인
		int2 DirPos = MyPos - MyPrevPos;
		SetDir(DirPos);

		// 방향에 따라 다른 모양을 대입
		if (GetDir() == int2::Left)
		{
			RenderChar = L'◀';
		}
		else if (GetDir() == int2::Right)
		{
			RenderChar = L'▶';
		}
		else if (GetDir() == int2::Up)
		{
			RenderChar = L'▲';
		}
		else if (GetDir() == int2::Down)
		{
			RenderChar = L'▼';
		}
		else
		{
			RenderChar = L'◇';
		}
	}
}

int2 Body::MapCheck()
{
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	std::vector<std::vector<bool>> MapPos;

	MapPos.resize(ScreenSize.Y);

	for (int i = 0; i < MapPos.size(); i++)
	{
		MapPos[i].resize(ScreenSize.X);
	}

	std::list<ConsoleGameObject*> HeadGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Head);

	for (ConsoleGameObject* HeadPtr : HeadGroup)
	{
		Parts* HeadPart = dynamic_cast<Parts*>(HeadPtr);

		if (nullptr == HeadPart)
		{
			break;
		}

		while (nullptr != HeadPart)
		{
			int2 HeadPos = HeadPart->GetPos();

			MapPos[HeadPos.Y][HeadPos.X] = true;

			HeadPart = HeadPart->GetNext();
		}
	}

	std::vector<int2> MapBlank;

	for (int i = 0; i < MapPos.size(); i++)
	{
		for (int j = 0; j < MapPos[i].size(); j++)
		{
			if (false == MapPos[i][j])
			{
				MapBlank.reserve(MapBlank.size() + 1);

				MapBlank.push_back({ j, i });
			}
		}
	}

	int RandomNumber = GameEngineRandom::MainRandom.RandomInt(0, MapBlank.size() - 1);

	int2 NewPos = MapBlank[RandomNumber];

	return NewPos;
}
