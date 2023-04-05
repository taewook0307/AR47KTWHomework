#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 정적 바인딩
    // 개수가 정해져 있고 코드가 실행되면 바뀌지 않는 메모리 영역들
    {
        int Arr[10];
        int* Ptr = Arr;
        Ptr[0];
    }
    
    // 동적 바인딩
    // 힙을 사용하는 행위
    {
        // new를 이용해서 배열을 힙에 할당
        int* ArrPtr = new int[100];

        // 힙에 할당된 배열을 지우는 방법

        // delete[] ArrPtr;     배열을 지우는 정석 방법
        // delete ArrPtr; => leak이 남지 않음 : 남을 수도 있으니 배열은 무조건 delete[] 로 지우기

        // 안전한 삭제 방법
        if (ArrPtr != nullptr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }
}