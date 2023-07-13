// 093_Ramda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

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
void RamdaFunction(int _Value)
{
	std::cout << "람다 함수 입니다" << std::endl;
};

int main()
{
	// Ramda
	// functional에서 함수포인터에 넣어주는 함수를 선언하지 않고 사용하는 곳에서 바로 함수를 만드는 문법

	Player NewPlayer;

	{
		std::function<void(int)> Func
			= [](int _Value)
		{
			std::cout << "람다 함수 입니다" << std::endl;
		};

		Func(10);
	}

	{
		// 1000번지
		Player* NewPlayerPtr = &NewPlayer;
		int A = 2000;

		std::function<void(int)> Func
			= [= /*const Player* NewPlayerPtr = NewPlayerPtr*/](int _Value)
		{
			// 2000번지
			NewPlayerPtr->Attack();

			// NewPlayerPtr = nullptr;

			A;
			// std::cout << "람다 함수 입니다" << std::endl;
		};

		Func(10);
	}
}