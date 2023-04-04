#include <iostream>

// 다형성을 표현하는 문법 virtual
// 보통 상속과 함께합니다.
// 다형성 != 상속

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

class Test
{

};

class Test2
{
public:
	virtual void Req()
	{

	}
};

int main()
{
	Player NewPlayer;

	int A = NewPlayer.GetAtt();

	int Value = sizeof(Test);			// Value = 1
	// 빈 클래스의 크기는 1
	
	//Test Arr[10];

	//Test* Ptr;

	//Ptr += 1;

	int Value2 = sizeof(Test2);			// Value = 8
	// virtual 함수를 가지고 있는 class의 크기는 8 : virtual 함수를 사용하면 해당 함수를 함수포인터의 배열로 만들고 함수포인터의 포인터로 저장

	int a = 0;
}