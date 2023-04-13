#include <iostream>


class B;
class A
{
// friend 문법 : 특정 클래스에서 자신의 접근제한 지정자를 취소시키는 문법
    friend B;   // B에게는 자신 내부를 공개

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
    void Function(A& _Other)
    {
        // _Other.Value = 20;     C에서는 A의 Value가 사용 불가
    }
};

int main()
{
    A NewA;
    B NewB;
    C NewC;

    NewB.Function(NewA);
}