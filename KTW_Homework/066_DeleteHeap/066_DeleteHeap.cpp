#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 중복 할당
    {
        int* Newint = new int();
        // Newint = new int();          새로운 int로 받을 시 원래 받았던 heap 데이터는 잃어버리게 됨
        delete Newint;
    
        int* Newint = new int();
        delete Newint;
        Newint = new int();
        delete Newint;
    }

    {
        // 힙이 한계에 도달하면 nullptr을 반환
        // 거의 없긴 함 => 확인하는 습관
        int* Newint = new int();

        if (nullptr == Newint)
        {
            return;
        }

        delete Newint;
    }

    // 지운 거 또 지우기
    {
        int* Newint = new int();

        delete Newint;

        // 메모리 크러쉬 발생
        // delete Newint;

        int* Newint = new int();

        // 안전한 삭제
        if (nullptr != Newint)
        {
            delete Newint;      // delete를 했다고 Newint가 nullptr이 되는게 아님 => Newint = nullptr; : 내가 따로 nullptr로 바꿔주어야 함.
            Newint = nullptr;
        }
    }

    {
        int* NewPtr = new int();

        if (NewPtr == nullptr)
        {
            return;
        }

        *NewPtr = 20;

        printf_s("%d\n", *NewPtr);

        if (NewPtr != nullptr)
        {
            delete NewPtr;
            NewPtr = nullptr;
        }
    }
}