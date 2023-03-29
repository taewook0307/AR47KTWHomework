#include <iostream>
#include "Player.h"
#include "Monster.h"

int main()
{
    // 컴파일러는 2가지 처리
    // 먼저 Cpp들을 다 검사
    // 하나의 프로젝트의 내가 친 모든 코드는 단 1개의 파일로 응축

    Player NewPlayer = Player();

    NewPlayer.Damage(10);

    Monster NewMonster = Monster();

    // 내가 사용하지 않는 건 컴파일러가 맘대로 지워 버릴 때가 있기 때문에
    // 구현이 안 된 변수나 함수를 쓰면 에러 발생
    // Monster::MonsterCount = 10;
}