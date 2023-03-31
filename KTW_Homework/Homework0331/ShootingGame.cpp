#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{
	Bullet* BulletArr = Bullet::GetArrBullet();

	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	int Left = 0;
	int Right = 0;

	// 가장 왼쪽에 있는 몬스터의 순번을 가져오기 위한 for문
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		if (true == ArrMonster[i].IsUpdate())
		{
			Left = i;
			break;
		}
	}

	// 가장 오른쪽에 있는 몬스터의 순번을 가져오기 위한 for문
	for (size_t i = ArrMonsterCount - 1; i >= 0; i--)
	{
		if (true == ArrMonster[i].IsUpdate())
		{
			Right = i;
			break;
		}
	}

	// 가장 왼쪽에 있는 몬스터가 이동하는 좌표가 스크린 밖인지 확인하는 변수
	bool LeftCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver({ ArrMonster[Left].GetPos().X + ArrMonster[Left].GetDir() , ArrMonster[Left].GetPos().Y }) == false;

	// 가장 오른쪽에 있는 몬스터가 이동하는 좌표가 스크린 밖인지 확인하는 변수
	bool RightCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver({ ArrMonster[Right].GetPos().X + ArrMonster[Right].GetDir() , ArrMonster[Right].GetPos().Y }) == false;

	// 왼쪽, 오른쪽에 있는 몬스터가 둘 다 스크린 밖으로 이동하지 않을 경우
	if (LeftCheck && RightCheck)
	{
		// 존재하는 몬스터의 X좌표에 +1 or -1 을 더하는 for문
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			if (ArrMonster[i].IsUpdate())
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X + ArrMonster[i].GetDir() , ArrMonster[i].GetPos().Y });
			}
		}
	}

	// 왼쪽에 있는 몬스터가 스크린 가장 왼쪽에 위치했을 경우
	else if (LeftCheck == false)
	{
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			// 모든 Monster의 Dir 값을 1이면 -1로 -1이면 1로 변경하는 함수
			ArrMonster[i].SetDir();

			// 모든 Monster의 Y좌표에 1을 더하는 함수
			if (ArrMonster[i].IsUpdate())
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X, ArrMonster[i].GetPos().Y + 1 });
			}
		}
	}

	// 오른쪽에 있는 몬스터가 스크린 가장 오른쪽에 위치했을 경우
	else if (RightCheck == false)
	{
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			// 모든 Monster의 Dir 값을 1이면 -1로 -1이면 1로 변경하는 함수
			ArrMonster[i].SetDir();

			// 모든 Monster의 Y좌표에 1을 더하는 함수
			if (ArrMonster[i].IsUpdate())
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X, ArrMonster[i].GetPos().Y + 1 });
			}
		}
	}

	else
	{
		return;
	}
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}