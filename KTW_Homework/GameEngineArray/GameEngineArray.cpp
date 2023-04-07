#include "GameEngineArray.h"

#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameEngineArray<int> NewArr(3);
    GameEngineArray<int> NewArr1(5);

    printf_s("NewArr의 크기 : %d\n", NewArr.Count());
    printf_s("NewArr1의 크기 : %d\n", NewArr1.Count());

    NewArr1 = NewArr;

    printf_s("\nNewArr1 = NewArr 실행 후\n");
    printf_s("NewArr의 크기 : %d\n", NewArr.Count());
    printf_s("NewArr1의 크기 : %d\n", NewArr1.Count());
}
