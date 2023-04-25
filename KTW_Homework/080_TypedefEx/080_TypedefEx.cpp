#include <iostream>

typedef int INT, * TEST;

// c의 문법을 거의 다 그대로 c++에서 사용 가능
// c++은 c를 포함한다 X

// c와 c++의 구조체의 차이
// c의 구조체는 멤버함수를 넣을 수 없음

struct __tagPlayer
{
    int Hp = 100;
    int Att = 10;
};

typedef struct __tagPlayer Player;

// c99에서는 struct가 생략이 불가능
// 생략이 불가능한 것을 생략하여 쓰고 싶어서 typedef를 이용

typedef struct __tagMonster         // 선언과 동시에 typedef로 변환
{
    int HP = 20;
    int Att = 5;
} Monster, *Enermy;

int main()
{
    INT a = 0;          // int형
    TEST Ptr = &a;      // int*형
}