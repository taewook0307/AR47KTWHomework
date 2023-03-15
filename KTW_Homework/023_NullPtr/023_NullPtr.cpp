#include <iostream>

int main()
{
    int Value = 10;

    //nullptr == 0
    //주소를 가리키지 않는다, 아직 아무도 가리키고 잇지 않다.
    int* Ptr = nullptr;

    *Ptr = 200;

    //int* Ptr = 0;     <= c스타일
}
