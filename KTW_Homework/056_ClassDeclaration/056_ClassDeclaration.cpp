#include <iostream>

// 순환 참조
// 순환 참조의 해결방법 : 선언과 구현의 철저한 분리

// 클래스 전방선언
class Monster;      // Monster라는 클래스가 있을거니까 호출해라 => 내용은 나중에

class Player
{
public:
    int Hp = 100;
    int Att = 10;

public:
    void Attack(Monster _Monster);

// 클래스 전방선언으로도 해결이 안 되는 경우

    // 내부에서 Monster의 내용을 사용하게 될 경우
    /*
        void Test1(Monster& _Monster)
        {
            전방선언에 경우 클래스의 내용을 알려주는 것이 아닌 해당 클래스가 있다는 사실을 알려줌
            클래스 내 내용을 사용할 경우 컴파일러는 해당 내용을 모르기 때문에 오류 발생
            _Monster.Hp -= 10;
        }
    */

    // class를 함수의 인자로 넘길 때 값으로 넘길 경우
    /*
        함수의 실행메모리를 정하려면 함수의 인자의 크기를 알아야 함
        class의 크기는 class 내 멤버변수의 종류와 개수로 인해 결정 => class 내용을 알아야 함
        class 내부의 내용을 알아야 하는 코드 이기 때문에 오류 발생
        Monster Test2(Monster _Monster)
        {
            return _Monster;
        }
    */

    // Monster 내부의 멤버 변수나 멤버 함수를 사용하지 않았기 때문에
    // => class 내부의 내용을 몰라도 실행 가능한 코드이기 때문에 오류 발생 X
    Monster* Test(Monster* _Monster)
    {
        return _Monster;
    }
};

class Monster
{
public:
    int Hp = 100;
    int Att = 10;

public:
    void Attack(Player* _Player);
};

int main()
{
    Player newPlayer;
    Monster newMonster;

    newPlayer.Attack(newMonster);
    newPlayer.Test(&newMonster);

    // newPlayer.Test1(newMonster);
    // newPlayer.Test2(newMonster);
}

void Player::Attack(Monster _Monster)
{
    _Monster.Hp -= Att;
}

void Monster::Attack(Player* _Player)
{
    _Player->Hp -= Att;
}