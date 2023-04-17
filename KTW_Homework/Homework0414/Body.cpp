#include "Body.h"
#include "Head.h"
#include "GameEnum.h"

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

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

	while (true)
	{
		if (false == SameAnotherBodyPos({ X, Y }) && false == SameHeadPos({ X, Y }))
		{
			break;
		}
		else
		{
			X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
			Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
		}
	}

	SetPos({ X, Y });
}

Body::~Body() 
{
}

void Body::Update()
{
	if (true == SameHeadPos())
	{
		RenderChar = '~';
	}

	ConsoleGameObject::Update();
}

void Body::Render()
{
	ConsoleGameObject::Render();
}

// 함수의 파라미터가 플레이어의 위치와 같을 경우 true
bool Body::SameHeadPos(int2 _Pos)
{
	std::list<ConsoleGameObject*>& HeadGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Head);

	for (ConsoleGameObject* HeadPtr : HeadGroup)
	{
		if (HeadPtr == nullptr)
		{
			continue;
		}

		int2 HeadPos = HeadPtr->GetPos();

		if (HeadPos == _Pos)
		{
			return true;
		}
	}
	return false;
}

// 자신의 위치가 플레이어의 위치와 같을 경우 true
bool Body::SameHeadPos()
{
	return SameHeadPos(GetPos());
}



bool Body::SameAnotherBodyPos(int2 _Pos)
{
	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (BodyPtr == nullptr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();

		if (BodyPos == _Pos)
		{
			return true;
		}
	}

	return false;
}
