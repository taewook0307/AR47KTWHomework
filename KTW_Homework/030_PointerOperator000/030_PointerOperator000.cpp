#include <iostream>

int main()
{
    int Value = 0;
    // Value의 번지가 100번지라 가정

    int* Ptr = &Value;
    // Ptr은 100이 저장

    __int64 Address = 0;

    Ptr = Ptr + 1;
    // Ptr의 주소값 100 + sizeof(int) * 1
    Address = (__int64)Ptr;

    Ptr += 1;
    Address = (__int64)Ptr;

    Ptr = Ptr - 1;
    Address = (__int64)Ptr;

    Ptr -= 1;
    Address = (__int64)Ptr;

    int a = 0;
}
