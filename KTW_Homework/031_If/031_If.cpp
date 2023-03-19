#include <iostream>

int ReturnValue()
{
    return 10;
}

int main()
{
    // if(메모리 영역)
    // {
    //      실행코드
    // }
    // 메모리 영역이 참이면 실행코드가 실행
    // 거짓이면 실행코드가 실행되지 않음

    int Value = 10;

    if (Value)
    {
        printf_s("실행코드");

        int a = 0;
    }

    // 이렇게 사용도 가능하긴 함
    // if (int Value0 = ReturnValue())
    // {
    //     printf_s("실행코드");
       
    //     int a = 0;
    // }

    // 값을 확인하는 습관이 중요
    // int Value0 = ReturnValue();
    // 
    // if (Value0)
    // {
    //     printf_s("실행코드");

    //     int a = 0;
    // }

    // 한줄치기 하지 말기(가독성 저하)
    // if (Value)
    //     printf_s("실행");

    if (Value)
    {
        printf_s("구분 지어주는게 주의");
    }

    // else if
    // else if는 하나만 실행
    if (0)
    {
        printf_s("0");
    }
    else if (1)
    {
        printf_s("1\n");
    }
    else if (2)
    {
        printf_s("2\n");
    }
    // else
    // 위에 있는 모든 if문이 다 실패하면 실행
    else
    {
        printf_s("else");
    }
}
