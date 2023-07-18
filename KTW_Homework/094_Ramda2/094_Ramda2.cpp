// 094_Ramda2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

int main()
{
    // []() => 이것 자체가 함수포인터
    // 이름없는 함수
    /*[]()
    {

    };

    void(*Ptr)() = []()
    {

    };*/

    // [=] : 외부의 변수를 받아서 나만의 복사본을 가지겠다는 의미
    {
        int A = 20;

        int* PtrA = &A;

        // std::function<void()> Ptr = [= const int A = A]()
        std::function<void()> Ptr = [=]()
        {
            const int* PtrAInner = &A;

            int a = 0;
        };
        // 지역변수 A와 람다로 내부에서 사용된 A는 서로 다른 변수

        Ptr();
    }

    // [&] : 외부에 존재하는 변수를 참조형으로써 가지고 있음을 의미
    {
        int A = 20;

        int* PtrA = &A;

        // std::function<void()> Ptr = [& int& A = A]()
        std::function<void()> Ptr = [&]()
        {
            const int* PtrAInner = &A;

            int a = 0;
        };
        // 지역변수 A와 람다로 내부에서 사용된 A는 서로 같은 변수

        Ptr();
    }

    // 람다 내부에서 변수마다 넘기는 방식을 지정할 수 있음
    {
        int A = 20;
        int B = 30;

        int* PtrA = &A;
        int* PtrB = &B;

        // A는 복사해서 B는 참조형으로 넘기도록 지정
        std::function<void()> Ptr = [A, &B]()
        {

        };

        Ptr();
    }
}

// 맴버 함수에서도 람다를 통해 this를 넘길 수 있음
class Test
{
public:
    int A = 10;

    void TestFunction()
    {
        std::function<void()> Ptr = [this]()
        {
            this->A = 20;
        };
    }
};