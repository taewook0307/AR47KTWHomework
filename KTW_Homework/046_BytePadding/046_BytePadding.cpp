#include <iostream>

//short 2바이트 정수형

class Player
{
public:                 // 주소값 확인(padding byte) : 숙제
    int Hp;
    short Value;
    __int64 Value0;

    // BytePadding 현상
    // 8byte 이하 가장 큰 바이트의 자료형을 찾는다
    // 위에 경우에는 8
    // 먼저 8바이트를 할당
    // 딱 맞거나 들어갈 수 있으면 그대로 픽스
};

int main()
{
    int Size = sizeof(Player);

    printf_s("%d", Size);
}