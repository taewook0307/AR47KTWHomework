#include <iostream>

// 플레이어 제작
// 행동

// C++에서 클래스는 모든 것을 만들 수 있는 문법
class Player
{
    // Class에는 속성, 행동이 존재
    
    // 속성
    // 내부에서 변수를 선언하는 것으로 표현 가능
    // 멤버 변수
    int Hp;
    int Att;

    // 행동
    // 멤버 함수
    void StatusRender()
    {

    }

    void Damage(const int& _Damage)
    {

    }
};
// 이것도 사용자 정의 자료형 중 하나

/*
자료형
기본자료형 : int, bool, ...
사용자 정의 자료형 : #define, class, struct, ... => 모든 것을 표현
*/

int main()
{
    // 개념을 생각하고 객체를 만듬
    // class로 정의 내리고 NewPlayer를 만듬
    // NewPlayer가 객체
    Player NewPlayer0 = Player();    // class를 이용해서 Player 하나를 만든 것
    Player NewPlayer1 = Player();
    Player NewPlayer2 = Player();

    // 플레이어
    // 공격력
    // 체력
}

/* 플레이어는 이러이러한 존재야
class Player
{
    int Hp;
    int Att;

    void StatusRender()
    {

    }

    void Damage(const int& _Damage)
    {

    }
};
*/