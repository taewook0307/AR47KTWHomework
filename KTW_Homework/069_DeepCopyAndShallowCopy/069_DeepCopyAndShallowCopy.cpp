#include <iostream>

class A
{
public:
    int* NewInt = nullptr;

    void Create()
    {
        NewInt = new int();
    }

    void operator = (const A& _Other)
    {
        // 얕은 복사
        // NewInt = _Other.NewInt;
        if (nullptr == _Other.NewInt)
        {
            //if (nullptr != NewInt)
            //{
            //    delete NewInt;
            //    NewInt = nullptr;
            //}
            return;
        }

        if (nullptr == NewInt)
        {
            // 딥카피의 준비
            Create();
        }

        // 각클래스가 자신만의 메모리를 만들어야 한다
        *NewInt = *_Other.NewInt;

        return;
    }


public:
    ~A()
    {
        if (nullptr != NewInt)
        {
            delete NewInt;
            NewInt = nullptr;
        }
    }
};

int main()
{
    {
        // 얕은 복사
        // 참조 타입 데이터가 저장한 '메모리 주소값'을 복사한 것
        /*
        ex)
        int Value = 0;
        int* IntPtr = &Value;

        int* NewPtr = IntPtr;
        */

        // 깊은 복사
        // 새로운 메모리 공간을 할당받고 그 공간에 기존에 있던 데이터를 모두 복사하는 것
    }
}
