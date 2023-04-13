#include <iostream>

class Test
{
public:
    // 이너클래스 문법 : 클래스 안의 다른 클래스를 만들 수 있는 문법
    class PublicInner
    {

    };

protected:
    class ProtectedInner
    {

    };

private:
    class PrivateInner
    {

    };
};

int main()
{
    Test::PublicInner NewPublicInner;
}