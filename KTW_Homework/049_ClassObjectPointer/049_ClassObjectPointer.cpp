#include <iostream>

class Player
{
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
}