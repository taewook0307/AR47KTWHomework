#include <iostream>

inline int MyPrintf(const char* const _Value, ...)
{
    __int64 Address = (__int64)&_Value;
    char* Ptr = (char*)Address;

    Ptr += 8;

    int* PtrInt = (int*)Ptr;

    int Value0 = *PtrInt;

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
                break;
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
