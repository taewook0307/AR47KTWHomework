// 메모리는 연속되어있을 때 가장 빠름

// vector : 배열형 시퀸스 자료구조
// vector의 장점 : 메모리가 연속되어 있어 자료구조 중 가장 빠름
// vector의 단점 : 상황에 따른 너무나도 큰 재할당과 복사 연산의 위험성

// vector의 단점을 해결하기 위한 자료구조 : List
// List의 장점 : 편의성
// List의 단점 : 연산이 느림

#include <iostream>
#include <crtdbg.h>
#include <list>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::list<int> NewList; 

    NewList.push_back(9);
    NewList.push_back(5);
    NewList.push_back(4);
    NewList.push_back(7);

    // Node형태의 자료들 중 시작점을 지정해주는 클래스
    std::list<int>::iterator Start = NewList.begin();
    std::list<int>::iterator End = NewList.end();

    for (; Start != End; ++Start)
    {
        printf_s("%d\n", *Start);
    }
}