#include <iostream>

// 재귀 함수
// 함수 안에서 자기 자신을 호출하는 방식

int Count = 0;

void Test()
{
    ++Count;
    printf_s("%d\n", Count);

    if (20 <= Count)
    {
        return;
    }

    Test();
}

int Test2()
{
    // 리턴에다가 재귀를 거는 경우 : 꼬리재귀
    // inline이랑 비슷
    // 단 스택 메모리를 아껴주는 게 아님

    if (true)
    {
        return 20;
    }

    return Test2();
}

int main()
{
    Test();

    // 재귀 함수의 주의점 : 스택 오버플로우 발생 가능성
    // 스택 오버플로우 : 스택의 메모리 영역이 가득 차 힙 메모리 영역을 침범할 우려가 있는 현상
}