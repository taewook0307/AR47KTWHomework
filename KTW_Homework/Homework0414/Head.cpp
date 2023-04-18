#include "Head.h"
#include "GameEnum.h"
#include "Body.h"

#include <conio.h>
#include <vector>
#include <list>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include <GameEngineBase/GameEngineDebug.h>

bool Head::IsPlay = true;

Head::Head() 
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();

		if (BodyPos == GetPos())
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("바디 그룹 쪽에 바디가 아닌 객체가 들어왔습니다.");
				return;
			}

			Parts* Last = GetLast();

			Last->SetNext(BodyPart);
			ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
		}
	}
	return;
}

void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		/*SetPos(GetPos() + Dir);
		IsBodyCheck();
		NextMove();*/
		return;
	}

	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	IsBodyCheck();
	NextMove();

	// 스크린 밖으로 나갈 경우 게임 오버
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
}
