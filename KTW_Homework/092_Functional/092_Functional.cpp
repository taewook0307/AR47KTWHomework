// 092_Functional.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

// 함수 포인터를 이용할 때
// 1. 전역도 받을 수 있고
// 2. 맴버도 받을 수 있고 <= 클래스 제한 없이
// 3. 인자의 제한도 없이 모든 함수를 함수포인터로 받을 수 있기를 원함
// 추가로 넣어준 인자가 삭제되지 않았으면 함수의 스택이 파괴되어서 인자가 사라지는 경우가 없기를 원함
// 위의 내용을 전부다 받을 수 있는 클래스 : functional

class Button
{
public:
	void(*ClickEventPtr)() = nullptr;

	// 상속
	virtual void Click()
	{
		if (nullptr != ClickEventPtr)
		{
			ClickEventPtr();
		}
	}
};

class Player
{
public:
	static Player* MainPlayer;

	Player()
	{
		MainPlayer = this;
	}

public:
	// 맴버
	void Attack()
	{
		std::cout << "플레이어가 공격합니다" << std::endl;
	}

	// 인자가 있는 함수
	void CriAttack(float* _CriPercent)
	{
		std::cout << "플레이어가 치명타 공격을 합니다." << std::endl;
	}

	void TestAttack(int _Test)
	{
		std::cout << "테스트 용 함수입니다." << std::endl;
	}

	// 인자가 2개인 함수
	void TestAttack2(int _Test, int _Test0)
	{
		std::cout << "테스트 용 함수입니다." << std::endl;
	}

};

Player* Player::MainPlayer = nullptr;

// 전역
void PlayerAttack()
{
	Player::MainPlayer->Attack();
}

int main()
{
	Player NewPlayer;

	Button PlayerAtt;

	PlayerAtt.ClickEventPtr = PlayerAttack;

	PlayerAtt.Click();

	// 전역함수
	{
		std::function<void()> Func;
		Func = std::bind(PlayerAttack);
		Func();
	}

	// 맴버함수
	{
		std::function<void()> Func;
		Func = std::bind(&Player::Attack, &NewPlayer);
		Func();
	}

	float Value = 50.0f;

	// 인자는 같이 넣어주면 상관없이 호출 가능.
	{
		// 인자의 처리와 상관없이  bind가 가능
		std::function<void()> Func;
		Func = std::bind(&Player::CriAttack, &NewPlayer, &Value);
		Value = 30.0f;
		Func();
	}

	// 인자를 강요할 경우
	{
		std::function<void(int)> Func;
		// 인자를 강요하고 싶을 경우 placeholders를 통해 인자를 무조건 넣어야 함을 유저에게 알림
		Func = std::bind(&Player::TestAttack, &NewPlayer, std::placeholders::_1);
		Func(10);
	}

	// 인자 2개를 강요할 경우
	{
		std::function<void(int, int)> Func;
		Func = std::bind(&Player::TestAttack2, &NewPlayer, std::placeholders::_1, std::placeholders::_2);
		Func(10, 20);
	}
}