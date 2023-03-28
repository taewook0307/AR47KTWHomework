#include <iostream>

// 객체를 지향한다 => 오직 클래스와 객체로만 코딩을 해야한다
// C++은 객체지향이 아님 => 전역의 존재 때문에
// 객체지향에서 전역은 필요가 없는가? No

class Monster
{
public:
    // static 멤버 함수 : 클레스에 속한 전역 함수
    // 객체를 생성하지 않고 클래스명 만으로 사용이 가능
    // 객체를 생성하지 않기 때문에 static 멤버 변수만 사용 가능
    static int GetAllMonsterCount()
    {
        return MonsterCount;
    }

    Monster()
    {
        ++MonsterCount;
    }
private:
    // static 멤버 변수 : 클레스에 속한 전역 변수
    // 객체별로 할당 되지 않고 해당 클래스의 모든 객체가 공유하는 멤버
    // 접근제한 지정자로 인해 static 멤버 변수는 접근 가능한 것에 제한을 둘 수 있음

    // 실체는 없고 선언만 해둔 것
    static int MonsterCount;        // static 멤버 변수는 클래스 내부에서 초기화 불가능
    static const int MonsterHp;     // 단 예외적으로 static const 타입은 내부에서 초기화 가능
};

// 실체를 둔다
int Monster::MonsterCount = 0;
const int Monster::MonsterHp = 200;

class Player
{
public:

private:
    // static 멤버 변수에 const를 붙이고 초기화까지 해주는 순간 그 멤버변수는 변하지 않는 수가 됨.
    static const int PlayerX = 3;
    static const int PlayerY = 4;

    int Arr[PlayerY][PlayerX];  // => 선언 가능
};

int main()
{
    Monster NewMonster0 = Monster();
    Monster NewMonster1 = Monster();
    Monster NewMonster2 = Monster();
    Monster NewMonster3 = Monster();
}