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

// 인자의 이름이 필요할 때는 그걸 이름을 사용할 때 뿐입니다.
// 이름을 넣어주지 않아도 인자를 사용 가능
void TestFunction2(int _1, ...)
{
    int* Ptr = &_1;

    int Count = 2;

    while (_1--)
    {
        int Value = Ptr[Count];
        Count += 2;
    }

    int a = 0;
}

/*  가변인자를 사용하면 컴파일러가 해당 인자의 개수만큼의 함수를 만들게 됨 <= 컴파일 시간이 길어짐
    void TestFunction2(int _1, int, int, int, int, int)
    {
        int* Ptr = &_1;

        int Count = 2;

        while(_1--)
        {
            int Value = Ptr[Count];
            Count += 2;
        }
    }
*/


int main()
{
    // VarFunction(2, 3, 4, 5);

    // VarFunction("1", "1", "1", "1", "1");

    // VarFunction("1", 1, 2);

    // TestFunction(10, 20, 30);

    // TestFunction2(5, 1, 2, 3, 4, 5);

    // %를 사용하게 되면 이는 포매팅 문자라고 해서
    // 숫자나 다양한 다른 변수들을 사용해서 출력을 요청
    // %d : 정수, %s : 문자열, %c : 문자
    printf_s("%d %s", 1, "asdf");

    int a = 0;
}
