#include <iostream>

// 플레이어가 만들어지면 내부에 int Att를 가지고 있어야 한다.
// Player가 만들어질때의 내부는 코드 영역
class Player
{
    int Att = 10;    // Player::Att
};

/* 같은 이름의 클래스를 사용 불가능
class Player
{

};
*/

class Monster
{
    int Att = 5;    // Monster::Att
};

void Test()
{
    int Att = 0;    // Test::Att
}

// 범위 확인(스코프 확인)
// 범위 확인 연산자 ::
// A::B <= A 안에 있는 B

namespace AProgramer
{
    class Item
    {

    };
}

namespace BProgramer
{
    class Item
    {

    };
}

/*  namespace 안에 namespace로 감쌀 수 있음
namespace BProgramer
{
    namespace UseI
    {
        class Item
        {

        };
    }
}
*/

// using namespace AProgramer;     <= 'namespace를 생략할 수 있다면 생략해라' 라는 의미

int main()
{
    AProgramer::Item NewItemA;

    BProgramer::Item NewItemB;

    // std : c++ 공인 C++ 스탠다드의 약어
    // c++ 만든 사람들이 품질 보증한 객체 혹은 클래스 혹은 모든 코드적 요소들
    std::cout << "Hello World!\n";
}
