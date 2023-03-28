#include <iostream>

// 순환 참조
// 순환 참조의 해결방법 : 선언과 구현의 철저한 분리

// 클래스 전방선언
class Monster;

class Player
{
public:

};

class Monster
{
public:

};

int main()
{
    std::cout << "Hello World!\n";
}