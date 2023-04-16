#include "Body.h"
#include "Head.h"
#include "GameEnum.h"

#include <list>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

Body::Body() 
{
	RenderChar = 'F';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);

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

bool Body::SameHeadPos()
{
	std::list<ConsoleGameObject*>& HeadGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Head);

	for (ConsoleGameObject* HeadPtr : HeadGroup)
	{
		int2 HeadPos = HeadPtr->GetPos();

		if (HeadPos == GetPos())
		{
			return true;
		}
	}
	return false;
}

bool Body::CheckPos()
{
	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		int2 BodyPos = BodyPtr->GetPos();

		if (BodyPos == GetPos())
		{
			return true;
		}
	}

	return false;
}
