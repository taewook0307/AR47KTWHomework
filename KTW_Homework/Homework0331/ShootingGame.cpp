#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
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

	// ���� ���ʿ� �ִ� ������ ������ �������� ���� for��
	for (size_t i = 0; i < ArrMonsterCount; i++)
	{
		if (true == ArrMonster[i].IsUpdate())
		{
			Left = i;
			break;
		}
	}

	// ���� �����ʿ� �ִ� ������ ������ �������� ���� for��
	for (size_t i = ArrMonsterCount - 1; i >= 0; i--)
	{
		if (true == ArrMonster[i].IsUpdate())
		{
			Right = i;
			break;
		}
	}

	// ���� ���ʿ� �ִ� ���Ͱ� �̵��ϴ� ��ǥ�� ��ũ�� ������ Ȯ���ϴ� ����
	bool LeftCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver({ ArrMonster[Left].GetPos().X + ArrMonster[Left].GetDir() , ArrMonster[Left].GetPos().Y }) == false;

	// ���� �����ʿ� �ִ� ���Ͱ� �̵��ϴ� ��ǥ�� ��ũ�� ������ Ȯ���ϴ� ����
	bool RightCheck = ConsoleGameScreen::GetMainScreen().IsScreenOver({ ArrMonster[Right].GetPos().X + ArrMonster[Right].GetDir() , ArrMonster[Right].GetPos().Y }) == false;

	// ����, �����ʿ� �ִ� ���Ͱ� �� �� ��ũ�� ������ �̵����� ���� ���
	if (LeftCheck && RightCheck)
	{
		// �����ϴ� ������ X��ǥ�� +1 or -1 �� ���ϴ� for��
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			if (ArrMonster[i].IsUpdate())
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X + ArrMonster[i].GetDir() , ArrMonster[i].GetPos().Y });
			}
		}
	}

	// ���ʿ� �ִ� ���Ͱ� ��ũ�� ���� ���ʿ� ��ġ���� ���
	else if (LeftCheck == false)
	{
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			// ��� Monster�� Dir ���� 1�̸� -1�� -1�̸� 1�� �����ϴ� �Լ�
			ArrMonster[i].SetDir();

			// ��� Monster�� Y��ǥ�� 1�� ���ϴ� �Լ�
			if (ArrMonster[i].IsUpdate())
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X, ArrMonster[i].GetPos().Y + 1 });
			}
		}
	}

	// �����ʿ� �ִ� ���Ͱ� ��ũ�� ���� �����ʿ� ��ġ���� ���
	else if (RightCheck == false)
	{
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			// ��� Monster�� Dir ���� 1�̸� -1�� -1�̸� 1�� �����ϴ� �Լ�
			ArrMonster[i].SetDir();

			// ��� Monster�� Y��ǥ�� 1�� ���ϴ� �Լ�
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

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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