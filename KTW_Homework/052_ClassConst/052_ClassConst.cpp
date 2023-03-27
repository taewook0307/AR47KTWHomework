#include <iostream>

class Player
{
public:
    Player()
         : Hp(10)
        , Att(100)
    {

    }

    // 멤버 함수 뒤에 const
    // 이 함수를 호출해도 이 클래스를 통해서 만들어진 객체는 변화하지 않는다.

    void PrintStatus() const
    {
        // 멤버 함수 뒤에 const를 붙이는 것 : Player* const this -> const Player* const this
        // 즉 객체 자신이 const화 되는 것
        printf_s("능력치 출력-----------------------------------\n");
        printf_s("체  력 : %d\n", Hp);
        printf_s("공격력 : %d\n", Att);
        printf_s("----------------------------------------------\n");
    }

    int GetHp() const
    {
        return Hp;
    }

    void SetHp(int _Value)
    {
        Hp = _Value;
    }

    int GetAtt() const
    {
        return Att;
    }

    void SetAtt(int _Value)
    {
        Att = _Value;
    }

protected:
private:
    int Hp;
    int Att;
};

int main()
{
    Player newPlayer = Player();

    newPlayer.PrintStatus();
}