#include <iostream>

class Player
{
public:
    Player()
        : Hp(100)
        , Att(10)
    {

    }

    void Damage(/*Player* const this*/ int _AttackAtt)
    {
        /*this->*/Hp -= _AttackAtt;

        // 멤버함수에는
        // 첫번째 인자로 무조건 자기자신의 클래스의 포인터가 들어가게 된다.

        // * const이기 때문에 this가 가리키는 대상은 바꿀 수 없다.
        // this = nullptr; <= 불가능
    }

    inline int GetHp()
    {
        return Hp;
    }
    inline int SetHp(int _Hp)
    {
        Hp = _Hp;
    }
    inline int GetAtt()
    {
        return Att;
    }
    inline int SetAtt(int _Att)
    {
        Att = _Att;
    }

protected:

private:
    int Hp;
    int Att;
};

int main()
{
    Player NewPlayer0 = Player();
    Player NewPlayer1 = Player();

    NewPlayer0.Damage(/* &NewPlayer0, */20);
    NewPlayer1.Damage(/* &NewPlayer1, */50);
}
