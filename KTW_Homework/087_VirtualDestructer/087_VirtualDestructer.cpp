#include <iostream>

class A
{
public:
    virtual void Function()
    {

    }

    A()
    {
        std::cout << "A의 생성자 실행" << std::endl;
    }

    // 소멸자의 특수성
    // 컴파일러는 소멸자의 이름을 ~로 생각
    // virtual을 붙이지 않았을 때는 일반적인 함수와 동일하게 판단
    virtual ~A()
    {
        std::cout << "A의 소멸자 실행" << std::endl;
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B의 생성자 실행" << std::endl;
    }

    ~B()
    {
        std::cout << "B의 소멸자 실행" << std::endl;
    }
};

int main()
{
    A* NewA = new B();

    delete NewA;
    // ~A에 virtual이 없을 경우
    /*
    A의 생성자 실행
    B의 생성자 실행
    A의 소멸자 실행
    */

    // ~A에 virtual이 있을 경우
    /*
    A의 생성자 실행
    B의 생성자 실행
    B의 소멸자 실행
    A의 소멸자 실행
    */
}