// 090_Shared_Ptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

class Monster
{
public:
    int Value0;
    int Value1;
};

template<typename PtrType>
class myshared_ptr
{
public:
    int* RefCount = 0;
    PtrType* Ptr = nullptr;

    ~myshared_ptr()
    {
        --(*RefCount);

        if(0 >= *RefCount)
        {
            delete RefCount;
            delete Ptr;
        }
    }

    myshared_ptr() {}

    void operator=(nullptr_t _Ptr)
    {
        --(*RefCount);

        if (0 >= *RefCount)
        {
            delete RefCount;
            delete Ptr;
        }

        RefCount = nullptr;
        Ptr = nullptr;
    }

    myshared_ptr(const myshared_ptr<PtrType>& _Other)
    {
        Ptr = _Other.Ptr;
        RefCount = _Other.RefCount;
        ++(*RefCount);
    }
};

template<typename PtrType>
myshared_ptr<PtrType> mymake_shared()
{
    myshared_ptr<PtrType> Return;
    Return.Ptr = new PtrType();
    Return.RefCount = new int();
    (*Return.RefCount) = 1;
    return Return;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // new를 이용해 객체를 만든 후 delete를 안 하면 leak이 발생
    // Monster* MonsterPtr = new Monster();

    // 포인터 대신 shared_ptr을 사용하는 방법
    std::shared_ptr<Monster> MonsterPtr = std::make_shared<Monster>();
    
    // shared_ptr
    // 스마트 포인터의 일종
    // 사용이 끝난 메모리를 자동으로 해제시켜준다
    // 메모리에서 동적으로 할당된 데이터를 가리키는 포인터 변수의 수가 0이 되지 않으면 절대로 지워지지 않는다 => 장점이자 단점으로 적용

    std::shared_ptr<Monster> MonsterPtr2 = MonsterPtr;

    // 더이상 사용하지 않겠다고 선언한 것 : delete
    MonsterPtr2 = nullptr;

    // shared_ptr의 단점
    // 1. 단 1개의 std::shared_ptr<>이 남아 있으면 해당 데이터는 메모리에서 지워지지 않음
    // 2. 순환 참조의 경우 지워지지 않음
}