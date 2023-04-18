#include "Body.h"
#include "Head.h"
#include "GameEnum.h"

#include <vector>
#include <list>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

// �迭�� �̿��ؼ� ���� ������� ã�ƺ����� �� �� �迭���� ������ ����
// ����

Body::Body() 
{
	RenderChar = 'F';

	SetPos(MapCheck());
}

Body::~Body() 
{
}

void Body::Update()
{
	if (nullptr != GetPrev())
	{
		RenderChar = '~';
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
