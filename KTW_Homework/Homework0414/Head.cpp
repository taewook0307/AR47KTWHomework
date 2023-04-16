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
		
		// ������ ��ġ�� �÷��̾��� ��ġ�� ������ ���
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
	// Head�� ��ġ�� VectorPos[0]�� ����
	int2 Prev = VectorPos[0];
	int2 Prev2;
	VectorPos[0] = GetPos();

	// VectorPos �� ���� �ڷ� �� ĭ�� �̵���Ű�� for��
	for (int i = 1; i < BodyCount; i++)
	{
		Prev2 = VectorPos[i];
		VectorPos[i] = Prev;
		Prev = Prev2;
	}

	std::list<ConsoleGameObject*>& BodyGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Body);

	int x = 0;

	// VectorPos�� ������ Body�� Pos�� SetPos
	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (x < BodyCount)
		{
			BodyPtr->SetPos(VectorPos[x]);
			++x;
		}
	}
}

// �ڽ��� Body�� ������ �ڱ� �ڽ��� ���� ���� ��ũ���� ũ���� ���� ������� ����
void Head::CheckScreenFull()
{
	int2 Screen = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	int ScreenSize = Screen.X * Screen.Y;

	if ((BodyCount + 1) == ScreenSize)
	{
		IsPlay = false;
	}
}

// �ڽ��� ���� ��ġ�� �ε������� Ȯ���ϴ� �Լ�
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

	// �ڽ��� ���뿡 �ε��� ��� ���� ����
	if (true == CheckPos())
	{
		IsPlay = false;
		Death();
	}

	// ��ũ�� ������ ���� ��� ���� ����
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	CheckScreenFull();
}
