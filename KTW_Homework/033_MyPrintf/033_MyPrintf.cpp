#include <iostream>

inline int MyPrintf(const char* const _Value, ...)
{
    __int64 Address = (__int64)&_Value;
    Address += 8;

    int Count = 0;

    while (0 != _Value[Count])
    {
        char Value = _Value[Count];
        
        if ('%' == Value)
        {
            ++Count;
            char Format = _Value[Count];

            switch (Format)
            {
            case 'd':
            {
                int* ValuePtr = (int*)Address;
                int Value = *ValuePtr;
                printf_s("%d", Value);
                break;
            }
            case 's':
                break;
            default:
                break;
            }
        }
        else
        {
            putchar(Value);
        }

        Count++;
    }

    return 0;
}

int main()
{
    MyPrintf("abcdefg %d", 100);
}
