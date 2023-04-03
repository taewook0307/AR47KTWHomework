#include <iostream>

// 멤버 이니셜라이저의 문법적 의미 : 멤버변수의 메모리 생성

class A
{
public:
    int Test = 3;

    A()
    {
        printf_s("A 생성자\n");
    }
    ~A()
    {
        printf_s("A 소멸자\n");
    }
};

class B : public A
{
public:
    B()
    {
        Test = 10;
        printf_s("B 생성자\n");
    }

    // 소멸자 : ~ 클래스 이름
    // 인자를 넣어줄 수 없음
    ~B()
    {
        printf_s("B 소멸자\n");
    }
};

int main()
{
    B NewB = B();

    // 호출할 수 있지만 메모리가 파괴되는 것은 아님 => 쓰는 사람은 없음
    // NewB.~B();
}