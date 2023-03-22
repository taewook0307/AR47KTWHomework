#include <iostream>

// 어느 영역에도 속하지 않는 지역 : 전역

// 전역 안에 선언된 변수 : 전역변수
int GlobalValue = 0;

// 전역 안에 선언된 함수 : 전역함수
// Test 전역함수
void Test()
{

}

// 사용자 정의 자료형 내부의 공간 : 멤버공간
class Player
{
private:        // 명확하게 선언
    int Hp;     // 멤버 안에 선언된 변수 : 멤버 변수

public:
    void setHp(int _A)      // 멤버 안에 선언된 함수 : 멤버 함수
    {
        Hp = _A;        // 멤버 함수 내부는 지역
    }
};

// main 전역함수
int main()
{
    
}
