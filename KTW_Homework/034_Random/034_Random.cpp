#include <iostream>
#include <conio.h>

int Seed = 0;

//기준값을 변경시켜주는 함수
void SeedChange(int _Seed)
{
    Seed = _Seed;
}

// 랜덤한 수를 뽑아주는 함수
int Randomint()
{
    // 수학 공식을 통해서
    // 뭔가 랜덤해보이는 수를 뽑아내는 것
    return ++Seed;
}

int main()
{
    // SeedChange(30);

    // 기준값을 바꾸는 함수
    //srand(0);   보통은 시간

    // int Value = 0;
    // srand((int)&Value);

    __int64 Time = time(0);     // 초시간을 줌 <= 기준시(utc타임)부터 현재까지 지난 초시간을 줌
    srand(Time);
    //시간은 보통 8byte 정수로 줌

    int Value = 29;

    while (true)
    {
        printf_s("%d\n", rand() % Value);
        // 키가 눌릴 때까지 프로그램을 정지시킨다.
        _getch();
    }
}