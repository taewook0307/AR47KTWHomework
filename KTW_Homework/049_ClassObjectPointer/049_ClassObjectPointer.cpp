#include <iostream>

class Player
{
public:
    void Damage(/*Player* const this*/)
    {
        // this => 30번째 줄은 this 값이 0

        //this->Hp = 20;        => this값이 0이어서 nullptr 익셉션 발생
        printf_s("맞았습니다");
    }

public:
    int Hp = 100;
    int Att = 10;
};

int main()
{
    int Value = int();
    Player NewPlayer = Player();

    int* ValuePtr = nullptr;
    Player* NewPlayerPtr = &NewPlayer;

    // *ValuePtr = 20;  <= nullptr 익셉션 발생

    NewPlayerPtr = nullptr;     // NewPlayerPtr이 가리키는 값이 0
    NewPlayerPtr->Damage();     // NewPlayerPtr이 가리키는 곳의 Damage => 0번지의 Damage 실행
    // Damage에서 this를 사용하지 않았기 때문에 30번째 코드는 실행
}