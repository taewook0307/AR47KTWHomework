#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <GameEngineConsole/ConsoleGameMath.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Bomb.h"
#include "GameEnum.h"

bool Player::IsGameUpdate = true;

Player::Player()
{
	RenderChar = '*';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

}

bool Player::IsBomb(int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BombGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	for (ConsoleGameObject* Ptr : BombGroup)
	{
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BombPos = Ptr->GetPos();

		bool DeathCheck = Ptr->IsDeath();
		
		if (true == DeathCheck)
		{
			continue;
		}
		else
		{
			bool PosCheck = BombPos == _NextPos;
			if (true == PosCheck)
			{
				return true;
			}
			else
			{
				continue;
			}
		}
	}
	return false;
}

void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
	{
		NextPos = Pos + int2::Left;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool BombPosCheck = IsBomb(NextPos);
		if (false == ScreenOverCheck && false == BombPosCheck)
		{
			Pos.X -= 1;
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos = Pos + int2::Right;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool BombPosCheck = IsBomb(NextPos);
		if (false == ScreenOverCheck && false == BombPosCheck)
		{
			Pos.X += 1;
		}
		break;
	}
	case 'w':
	case 'W':
	{
		NextPos = Pos + int2::Up;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool BombPosCheck = IsBomb(NextPos);
		if (false == ScreenOverCheck && false == BombPosCheck)
		{
			Pos.Y -= 1;
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPos = Pos + int2::Down;
		bool ScreenOverCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos);
		bool BombPosCheck = IsBomb(NextPos);
		if (false == ScreenOverCheck && false == BombPosCheck)
		{
			Pos.Y += 1;
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}
}
