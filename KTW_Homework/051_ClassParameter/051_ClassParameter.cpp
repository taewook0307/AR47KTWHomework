#include <iostream>

class Player
{
public:
    int Value;
    int Value1;
    int Value2;
    int Value3;
    int Value4;
    int Value5;
};

// 플레이어가 1마리도 없을 가능성이 있다면 포인터
void StatusRenderPtr(const Player* _Player) 
{
    // 방어 코드
    if (nullptr == _Player)
    {
        return;
    }
}

// 플레이어가 1마리도 없을 가능성이 없다면
void StatusRenderRef(const Player& _Player)        // 함수 인자를 사용할 경우 class는 메모리를 8바이트 이상 사용가능성이 있음 => reference를 넣을 경우 무조건 8바이트를 사용하므로 메모리 절약
{

}

int main()
{
    int Value = sizeof(Player);
}