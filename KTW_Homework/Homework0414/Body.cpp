#include "Body.h"
#include "Head.h"
#include "GameEnum.h"

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

// �Լ��� �Ķ���Ͱ� �÷��̾��� ��ġ�� ���� ��� true
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

// �ڽ��� ��ġ�� �÷��̾��� ��ġ�� ���� ��� true
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
