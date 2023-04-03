#include <iostream>

class FightUnit
{
public:
	int GetAtt()
	{
		return Att;
	}

private:
	int Att = 10;
	int Hp = 100;
};

class Monster : public FightUnit
{

};

class BossMonster : public Monster
{

};

class Player : public FightUnit
{
public:
	int GetPlayerAtt()
	{
		return GetAtt() + Lv + Equip;
	}


private:
	int Lv = 1;
	int Equip = 1; // 장비
};

// 다형성을 표현하는 문법 virtual
// 보통 상속과 함께합니다.
// 다형성 != 상속

// 내 게임에 있는 존재들끼리 싸울때 사용하는 함수
void FightScene(FightUnit* _Player, FightUnit* _Monster)
{

}
//
//void FightScene(Player* _Player, Player* _Monster)
//{
//
//}
//
//void FightScene(Player* _Player, Npc* _Monster)
//{
//
//}
//
//void FightScene(Player* _Player, Boss* _Monster)
//{
//
//}
//


int main()
{
	Player NewPlayer;

	int A = NewPlayer.GetAtt();

	//int Value = sizeof(Test);

	//Test Arr[10];

	//Test* Ptr;

	//Ptr += 1;
}