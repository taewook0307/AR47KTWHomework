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
	VectorPos.resize(30);
}

Head::~Head() 
{
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
		
		// 아이템 위치와 플레이어의 위치가 동일할 경우
		if (GetPos() == BodyPos)
		{
			BodyPtr->Update();
			BodyPlus();
			ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
		}
	}
	return;
}

void Head::NewBodyCreate()
{
	// Head의 위치를 VectorPos[0]에 저장
	int2 Prev = VectorPos[0];
	int2 Prev2;
	VectorPos[0] = GetPos();

	// VectorPos 내 값을 뒤로 한 칸씩 이동시키는 for문
	for (int i = 1; i < BodyCount; i++)
	{
		Prev2 = VectorPos[i];
		VectorPos[i] = Prev;
		Prev = Prev2;
	}

	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	int x = 0;

	// VectorPos의 값들을 Body의 Pos에 SetPos
	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (x < BodyCount)
		{
			BodyPtr->SetPos(VectorPos[x]);
			++x;
		}
	}
}

// 자신의 Body의 개수에 자기 자신을 더한 값이 스크린의 크기의 값과 같을경우 종료
void Head::CheckScreenFull()
{
	int2 Screen = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	int ScreenSize = Screen.X * Screen.Y;

	if ((BodyCount + 1) == ScreenSize)
	{
		IsPlay = false;
	}
}

// 자신의 몸통 위치에 부딪혔는지 확인하는 함수
bool Head::CheckPos()
{
	int2 HeadPos = GetPos();

	for (int i = 1; i < BodyCount; i++)
	{
		if (HeadPos == VectorPos[i])
		{
			return true;
		}
	}

	return false;
}

void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		IsBodyCheck();
		NewBodyCreate();
		SetPos(GetPos() + Dir);
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

	IsBodyCheck();
	NewBodyCreate();
	SetPos(GetPos() + Dir);

	// 자신의 몸통에 부딪힐 경우 게임 오버
	if (true == CheckPos())
	{
		IsPlay = false;
		Death();
	}

	// 스크린 밖으로 나갈 경우 게임 오버
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	CheckScreenFull();
}
