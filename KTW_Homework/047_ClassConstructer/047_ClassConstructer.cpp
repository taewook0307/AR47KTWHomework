#include <iostream>

class Player
{
public:
    // 리터럴 초기화라고 부르는 초기화 방식 => 11이전에는 안 되던 방식, 안 쓰는 회사가 있을수도 있음
    int Hp = 100;
    int Att = 10;
    int Def = 10;
    int MaxHp = 500;
    int MaxAtt = 50;

    void TestFunction()
    {
    
    }

public:
    // 생성자의 조건
    // 무조건 클래스 이름과 완전히 동일
    // 리턴값이 없음 => 리턴값이 그 클래스의 객체이기 때문에
    // 객체 없이 호출가능 => 객체를 만들어내는 함수가 객체가 필요할 수 없기 때문에
    // 멤버이니셜라이저라는 문법을 사용
    // 멤버이니셜라이저가 최종 적용

    /* 멤버이니셜라이저
    Player()
        :Hp(30), Att(30), Def(30), MaxHp(30), MaxAtt(30)
    {

    }
    */

    // 리터럴 초기화, 멤버이니셜라이저 => 생성
    Player()
        : Hp(30)
        , Att(30)
        , Def(30)
        , MaxHp(30)
        , MaxAtt(30)
    {
        // 대입   => 생성과 대입은 차이
        Hp = 10;
    }

    Player(int Value0, int Value1)
    {

    }
};

void Test(const Player& _Player)
{

}

int main()
{
    // 내가 정의하지 않은 행동을 한다면 그건 컴파일러가 가능하게 한 것
    // 그리고 그건 내 눈에 생략된 것
    Player NewPlayer = Player();

    // 클래스의 멤버 함수는 무조건 객체가 필요
    // 이 제약에서 벗어난 함수 2종 => 그 중 하나는 생성자
    // 생성자 : 객체를 만들어내는 전역함수 <= 생성자는 기본적으로 함수로 인식

    NewPlayer.TestFunction();
    // Player::TestFunction();  <= 멤버 함수는 객체 없이 사용 불가능

    // 리스트 이니셜라이저 문법
    Player newPlayer = { 10, 20 };          // Player newPlayer = Player(10, 20);
}