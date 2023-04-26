#include <iostream>

// 함수 호출 규약

// 일반적인 전역함수 __cdecl
void __cdecl Test()
{

}

// 윈도우 함수에서 많이 사용
void __stdcall Test()
{

}

// 멤버 함수는 thiscall 이란 규약을 사용

int main()
{
    std::cout << "Hello World!\n";
}