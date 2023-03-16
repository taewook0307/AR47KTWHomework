#include <iostream>

void VarFunction(...)
{

}

void TestFunction(int _1, int _2, int _3)
{
    int* ValuePtr0 = &_1;
    int* ValuePtr1 = &_2;
    int* ValuePtr2 = &_3;

    __int64 Address0 = 0;
    __int64 Address1 = 0;
    __int64 Address2 = 0;

    Address0 = (__int64)ValuePtr0;
    Address1 = (__int64)ValuePtr1;
    Address2 = (__int64)ValuePtr2;

    int Value1 = ValuePtr0[0];
    int Value2 = ValuePtr0[2];
    int Value3 = ValuePtr0[4];

    int a = 0;
}

void TestFunction2(int _1, ...)
{
    int* Ptr = &_1;

    int Value0 = Ptr[0];
    int Value1 = Ptr[2];
    int Value2 = Ptr[4];
    int Value3 = Ptr[6];
    int Value4 = Ptr[8];
    int Value5 = Ptr[10];
}

int main()
{
    VarFunction(2, 3, 4, 5);

    VarFunction("1", "1", "1", "1", "1");

    VarFunction("1", 1, 2);

    TestFunction(1, 2, 3);

    TestFunction2(5, 1, 2, 3, 4, 5);
}
