#include <iostream>


class B;
class A
{
// friend 문법 : 특정 클래스에서 자신의 접근제한 지정자를 취소시키는 문법
    friend B;

private:
    int Value = 0;
};

class B
{
public:
    void Function(A& _Other)
    {
        _Other.Value = 20;
    }
};

class C
{

};

int main()
{

}