#include <iostream>

// 함수도 프로세스로 메모리에 올라가기 때문에 위치가 존재
void PlayerAttack()
{
    printf_s("공격\n");
}

void PlayerMove()
{
    printf_s("이동\n");
}

int main()
{
    // 리턴값 (*함수 포인터명) (인자)
    void(*Ptr)() = PlayerAttack;

    Ptr();

    Ptr = PlayerMove;

    Ptr();
}