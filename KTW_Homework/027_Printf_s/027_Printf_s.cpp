#include <iostream>

void MyPrintf(const char* const _ptr)
{
    int Count = 0;
    while (0 != _ptr[Count])
    {
        char Ch = _ptr[Count];

        putchar(Ch);
        Count += 1;
    }
    /*putchar(_ptr[0]);
    putchar(_ptr[1]);
    putchar(_ptr[2]);*/
}

int main()
{
    //char Arr[10] = {};

    //MyPrintf(Arr);

    const char* Ptr = "test print";

    char ch0 = Ptr[0];
    char ch1 = Ptr[1];
    char ch2 = Ptr[2];
    char ch3 = Ptr[3];
    char ch4 = Ptr[4];
    char ch5 = Ptr[5];
    char ch6 = Ptr[6];
    char ch7 = Ptr[7];
    char ch8 = Ptr[8];

    MyPrintf("aaa");

    //printf_s("aaa", 1, 2, 3, 4);
    //가변 인자
}