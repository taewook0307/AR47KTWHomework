#include <iostream>
#include <conio.h>
#include <Windows.h>
// 숙제0 : 전방향 다 움직이게 만들기
// 숙제1 : 잔상 지우기
// 숙제2 : 화면 밖으로 못 나가게 하기

// 안해도 되는 숙제
// 숙제3 : 장애물 만들고 배치하기
// 숙제4 : f를 누르면 폭탄이 설치되고 눈에 보여야 함.
// 숙제5 : 일정시간이 지나고 폭탄이 터지면서

int main()
{
    const int ScreenYsize = 5;
    const int ScreenXsize = 5;

    char Arr[ScreenYsize][ScreenXsize] = { '0', };
    
    for (size_t y = 0; y < ScreenYsize; y++)
    {
        for (size_t x = 0; x < ScreenXsize; x++)
        {
            Arr[y][x] = 'a';
        }
    }

    for (size_t y = 0; y < ScreenYsize; y++)
    {
        for (size_t x = 0; x < ScreenXsize; x++)
        {
            printf_s("%c", Arr[y][x]);
        }
        printf_s("\n");
    }

    // 어떤 키를 눌렀는지 알려주는 함수
    char Ch = _getch();
}