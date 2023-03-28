#include <iostream>

void Function()
{
    printf_s("Function()\n");
}

void Function(int _Value)
{
    printf_s("Function(int _Value)\n");
}

// 파라미터 자료형이 다르기 때문에 오버로딩 가능 => 모호하기 때문에 좋지 않은 오버로딩 방법
void Function(short _Value)
{
    printf_s("Function(short _Value)\n");
}

// 함수 오버로딩에 영향을 주는 요인 : 함수 이름, 파라미터 자료형
// 리턴 값은 함수 오버로딩에 영향을 주지 않음

// 함수라고 불리는 모든 것에 적용 가능 ex) 생성자, 멤버 함수, ...
int main()
{
    std::cout << "Hello World!\n";
}
