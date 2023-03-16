#include <iostream>

int main()
{
    int Value = 10;

    int* Ptr = &Value;

    //자료형* <= 포인터 문법
    const int* Ptr0 = &Value;

    //Value를 const로 선언하지 않았더라도
    //포인터 변수 Ptr0의 자료형을 const int로 했기 때문에
    //*Ptr0 = 20;   <= 코드는 실행 불가능 : Value의 값을 포인터 연산자를 이용해서 변경할 수 없음.

    //둘은 동일 (코드 스타일 차이)
    const int Value0 = 10;
    int const Value1 = 10;

    {
        int num = 0;

        const int* const Ptr = &num;
        //Ptr번지의 있는 값 num을 변경할 수도 없고, Ptr번지도 변경할 수 없음
    }
}