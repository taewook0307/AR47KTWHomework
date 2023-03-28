#include <iostream>

// 구현 문법
// 선언과 함수체를 같이 놓는 문법

// 함수 선언
void Function()
// 함수체
{

}

// 함수 선언만 따로 가능


// 함수 선언부
// 함수 선언부를 따로 놓는 이유
// 함수끼리 서로 실행을 해야할 경우 선언부가 따로 있으면 일단 무조건 호출하고 컴파일 해줌 => 구현부가 나중에 있을 것이라 믿기 때문에
// 구현부 X => '확인할 수 없는 외부 기호' 오류 발생
void Function0();
void Function1();

// 같은 전역 함수 선언부가 여러 개여도 컴파일러가 알아서 1개로 만듬
void Function2();

// 클래스는 문법 상 선언과 구현이 내부에서 혼재되어 있을 수도 있고 아닐 수도 있음
// 클래스 자체는 2개 선언 불가
class Player
{
private:
    int Hp;

public:
    // 클래스 내부의 함수는 별개로 선언만 놔둘 수 있음
    void Damage();

    // 클래스 내부의 함수를 선언과 동시에 구현까지 한 상태에서 별도로 구현을 만들지 못함
    void StatusRender()
    {

    }
};

// 멤버함수의 fUllName은 무조건 클래스명::함수이름
void Player::Damage()
{

}

// 선언과 동시에 구현을 했기에 불가능
/*
void Player::StatusRender()
{

}
*/

int main()
{
    Function0();
}

void Function0()
{
    printf_s("Function0 실행\n");
    Function2();
}

void Function1()
{
    printf_s("Function1 실행\n");
    Function0();
}

void Function2()
{
    printf_s("Function2 실행\n");
    Function0();
}