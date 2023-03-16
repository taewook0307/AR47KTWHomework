#include <iostream>

int main()
{
    //대부분의 언어에서 참조의 의미
    //특정 메모리 영역의 위치를 가리킨다

    int Value0 = 10;
    int Value1 = 20;

    //포인터형
    //포인터는 언제든지 자신이 참조(가리킨다) 대상을 변경 가능
    int* Ptr = nullptr;
    Ptr = &Value0;
    Ptr = &Value1;

    //참조형
    //참조형은 선언할 때 무조건 누군가를 가리켜야 함
    int& Ref = Value0;

    //*Ptr : 포인터 연산자를 통해 해당 주소에 있는 값을 사용할 수 있음
    //Ref = *Ptr => 항상 포인터 연산자처럼 값을 끌어낼 수 있음
    //int& Ref = Value0; => Value0이라는 애를 Ref라고도 부른다는 의미
    //한번 초기화 시 참조한 메모리 영역을 바꿀 수 없음.

    Ref = Value1; // Value0 = Value1; 이라는 코드와 동일

    int Value = sizeof(Ref);
    int Check = sizeof(*Ptr);

    {
        //밑에 포인터와 레퍼런스의 코드는 같은 내용 단 포인터는 null값이 존재, 레퍼런스는 반드시 값이 필요
        int* Ptr = &Value0;
        *Ptr = Value1;

        int& Ref = Value0;
        Ref = Value1;
    }
}