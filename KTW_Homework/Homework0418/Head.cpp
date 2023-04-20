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
	RenderChar = L'★';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*> BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();

		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("Body가 아닌 다른 객체가 들어왔습니다.");
				return;
			}

			Parts* PartLast = GetLast();
			PartLast->SetNext(BodyPart);
			ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
			return;
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
		/*IsBodyCheck();
		SetPos(GetPos() + Dir);
		NextMove();*/
		return;
	}

	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		SetDir(int2::Left);
		RenderChar = L'◀';
		break;
	case 'd':
	case 'D':
		SetDir(int2::Right);
		RenderChar = L'▶';
		break;
	case 'w':
	case 'W':
		SetDir(int2::Up);
		RenderChar = L'▲';
		break;
	case 's':
	case 'S':
		SetDir(int2::Down);
		RenderChar = L'▼';
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}
	SetPos(GetPos() + GetDir());
	IsBodyCheck();
	NextMove();

	// 스크린 밖으로 나갈 경우 게임 오버
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
}
