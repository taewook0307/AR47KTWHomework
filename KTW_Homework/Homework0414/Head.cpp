#include "Head.h"
#include "GameEnum.h"
#include "Body.h"

#include <conio.h>
#include <vector>
#include <list>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

bool Head::IsPlay = true;

Head::Head() 
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
	VectorPos.resize(9);
}

Head::~Head() 
{
}

void Head::FullScreenBody()
{
	int ScreenSizeX = ConsoleGameScreen::GetMainScreen().GetScreenSize().X;
	int ScreenSizeY = ConsoleGameScreen::GetMainScreen().GetScreenSize().Y;

	int ScreenSize = ScreenSizeX * ScreenSizeY;

	if ((BodyCount + 1) == ScreenSize)
	{
		system("cls");
		printf_s("Game Clear");
	}
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	std::list<ConsoleGameObject*>::iterator Start = BodyGroup.begin();
	std::list<ConsoleGameObject*>::iterator End = BodyGroup.end();

	for (; Start != End; ++Start)
	{
		ConsoleGameObject* BodyPtr = *Start;

		int2 BodyPos = BodyPtr->GetPos();
		
		if (GetPos() == BodyPos)
		{
			BodyPtr->Update();
			ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
			++BodyCount;
			return;
		}
	}
	return;
}

void Head::NewBodyCreate()
{
	int2 Prev = VectorPos[0];
	int2 Prev2;
	VectorPos[0] = GetPos();

	for (int i = 1; i < BodyCount; i++)
	{
		Prev2 = VectorPos[i];
		VectorPos[i] = Prev;
		Prev = Prev2;
	}

	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	int i = 0;

	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (i < BodyCount)
		{
			BodyPtr->SetPos(VectorPos[i]);
			++i;
		}
	}
}

void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		IsBodyCheck();
		NewBodyCreate();
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		IsBodyCheck();
		NewBodyCreate();
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		IsBodyCheck();
		NewBodyCreate();
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		IsBodyCheck();
		NewBodyCreate();
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
}
