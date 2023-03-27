#include <iostream>

// C++ 은 전역의 존재 때문에 객체지향 언어가 아님

// static 멤버 변수

class Player
{
public:
    Player()
    {
        ++PlayerCount;
    }

    int GetAllPlayerCount()
    {
        return PlayerCount;
    }

private:
    static int PlayerCount;
};

int Player::PlayerCount = 0;

int main()
{
    Player NewPlayer0 = Player();
    Player NewPlayer1 = Player();
    Player NewPlayer2 = Player();


    int a = 0;
}