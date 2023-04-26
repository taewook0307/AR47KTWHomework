#include <iostream>

// 지역 static 변수
// 다른 곳에서는 사용할 수 없고 선언된 지역 내에서만 쓰이는 전역 변수

void TestFunction()
{
    static int Value = 0;
    std::cout << Value << std::endl;
    ++Value;
}

int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        TestFunction();
    }
}