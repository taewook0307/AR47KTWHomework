#include <iostream>

int main()
{
    int Value = 10;

    //nullptr == 0
    //주소를 가리키지 않는다, 아직 아무도 가리키고 잇지 않다.
    //보통은 nullptr로 초기화
    int* Ptr = nullptr;

    //넣어줄 주소값이 있으면 바로 넣어줌.
    int* Ptr1 = &Value;

    //int* Ptr = 0;     <= c스타일
}
