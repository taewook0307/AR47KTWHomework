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
        // 함수 뒤에 const를 붙이는 것 : Player* const this -> const Player* const this
        printf_s("능력치 출력");
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
    std::cout << "Hello World!\n";
}