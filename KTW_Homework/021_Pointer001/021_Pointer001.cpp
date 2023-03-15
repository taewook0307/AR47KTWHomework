#include <iostream>

int main()
{
    {
        int Value0 = 0;
        int Value1 = 0;

        //& : 특정 변수의 메모리 영역의 주소값을 끌어내는 것
        int* ValuePtr0 = &Value0;
        int* ValuePtr1 = &Value1;
    }

    {
        int Arr[3] = { 0,1,2 };

        int* ValuePtr0 = &Arr[0];
        int* ValuePtr1 = &Arr[1];
        int* ValuePtr2 = &Arr[2];

        __int64 Address0 = 0;
        __int64 Address1 = 0;
        __int64 Address2 = 0;

        Address0 = (__int64)ValuePtr0;
        Address1 = (__int64)ValuePtr1;
        Address2 = (__int64)ValuePtr2;
    }
}