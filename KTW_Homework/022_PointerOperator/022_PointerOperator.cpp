#include <iostream>

void ValueChange(int num)
{
    num = 20;
}

void ValueChangePtr(int* Ptr)
{
    *Ptr = 0;
}

int main()
{
    {
        int Value = 10;

        int* Ptr = &Value;

        // 포인터 변수 앞에 *을 붙이는 연산자
        // 그 위치의 메모리를 사용하겠다.
        *Ptr = 20;
        // Value의 위치에 있는 값을 사용하겠다.

        ValueChange(Value);
        // ValueChange의 num과 main의 Value는 다른 메모리 위치를 가지는 다른 값
        // ValueChange의 num이 Value의 값을 넘겨받아 다른 값을 넣어도
        // Value는 변하지 않음 => 변하는 값은 ValueChange의 num

        ValueChangePtr(&Value);
        ValueChangePtr(Ptr);
        // ValueChangePtr의 인자가 받는 값이 Value의 주소값
        // ValueChangePtr에서 *Ptr을 통해 포인터변수 내 값을 변경시키면
        // main에서의 Value값을 변경하는 것
    }
}