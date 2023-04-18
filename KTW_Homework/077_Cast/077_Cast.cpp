#include <iostream>

class A
{
    virtual void Test()
    {

    }
};

class B : public A
{

};

class C : public A
{

};

int main()
{
    // static_cast
    // 메모리 크기만 다를 뿐 서로 값대 값형태의 형변환
    {
        short Test = 10;
        int Value = (int)Test;
        // 권장하지 않는 방식

        // 메모리 크기만 다를 뿐 서로 값형태
        Value = static_cast<int>(Test);
        // int Value = (int)Test;  <= 컴파일러가 자동으로 static_cast<int>로 변환 시킴 : 컴파일 시간이 더 걸림
    }

    // reinterpret_cast
    // 정수를 포인터로 포인터를 정수로 변경할 때 사용
    {
        int Value = 3;

        __int64 Address = reinterpret_cast<__int64>(&Value);

        int* Ptr = reinterpret_cast<int*>(Address);
    }

    // dynamic_cast
    // 부모자식구조에서 사용됨 => 다운 캐스팅에 사용
    // 가상함수 테이블을 참조해서 다운캐스팅이 가능한지를 확인
    {
        A* PtrA = new B();
        B* PtrB = dynamic_cast<B*>(PtrA);       // 다운 캐스팅이 가능하므로 PtrB는 null이 아님

        int a = 0;
    }

    {
        A* PtrA = new C();
        B* PtrB = dynamic_cast<B*>(PtrA);       // 다운 캐스팅이 아니므로 PtrB = null

        int a = 0;
    }

    // const_cast
    // const형태의 값을 변경하는데 사용하는데 굳이 사용 필요성이 없음
}