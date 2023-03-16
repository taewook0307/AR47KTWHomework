#include <iostream>

int main()
{
    // 반복문 중 while을 사용

    // while (메모리영역, 조건문)
    // {
    //      실행코드
    // }

    // while(내부에는 ,를 통해서 여러가지 조건을 넣을 수 있음)
    // 무조건 가장 오른쪽에 있는 ,의 메모리 영역의 값만을 조건으로 취급

    // while (특정 메모리 영역이 참인가 거짓인가)
    {
        int Value = 5;

        while (printf_s("조건문\n"), Value)
        {
            --Value;
            printf_s("실행코드\n");
        }
    }

    {
        //실행코드가 먼저 실행
        int Value = 5;

        do
        {
            --Value;
            printf_s("실행코드\n");
        } while (printf_s("조건문\n"), true);
    }
    //실행코드가 무조건 한 번은 실행되어야 한다면 do while문을 이용
}