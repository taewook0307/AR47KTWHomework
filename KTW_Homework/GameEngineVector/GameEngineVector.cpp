#include <iostream>
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>

// vector는 배열을 대체

// 일반적인 배열은 선언과 동시에 접근이 가능
// [][][][][][][][][][][접근]

typedef int DataType;

class MyVector
{
public:
    MyVector()
    {

    }

    void push_back(const DataType& _Value)
    {
        if (Size + 1 > Capacity)                // 배열 안에 빈 공간이 있는지 확인
        {
            reserve((Capacity + 1) * 1.5);      // 빈 공간이 없으면 확장
        }

        ArrData[Size] = _Value;
        ++Size;
    }

    void reserve(size_t _Value)
    {
        DataType* NewPtr = new DataType[_Value];
        size_t CopySize = _Value < Capacity ? _Value : Capacity;

        for (size_t i = 0; i < CopySize; i++)
        {
            NewPtr[i] = ArrData[i];
        }

        if (nullptr != ArrData)
        {
            delete[] ArrData;
            ArrData = nullptr;
        }

        ArrData = NewPtr;
        Capacity = _Value;
    }

    size_t size()
    {
        return Size;
    }

    size_t capacity()
    {
        return Capacity;
    }

    DataType& operator[](size_t _Index) const
    {
        if (Size <= _Index)
        {
            MsgBoxAssert("인덱스를 오버하여 벡터를 사용하려고 했습니다.");
        }
        return ArrData[_Index];
    }

private:
    size_t Capacity = 0;        // 배열의 크기

    size_t Size = 0;            // 넣어준 원소의 크기

    DataType* ArrData = nullptr;
};

int main()
{
    {
        std::vector<int> Test;
        int Value = (int)Test.size();       // Value = 0
        // 초기 벡터는 아무것도 없음
        // 벡터는 넣는다는 개념

        Test.push_back(0);
        // Test : [0]
        Test.push_back(0);
        // Test : [0][0]
        Test.push_back(0);
        // Test : [0][0][0]
        Test.push_back(0);
        // Test : [0][0][0][0]

        // push_back : 사용 시 자동으로 size를 늘리고 해당 값을 대입
        //   => vector의 최악의 사용법으로 불림 : 재할당이 일어나기 때문
    }

    {
        printf_s("vector의 올바른 사용법\n");
        std::vector<int> Standard;

        // reserve 함수를 통해 미리 공간을 확장시켜놓은 뒤에 push_back을 통해 원소만 넣어지도록 사용
        Standard.reserve(10);       // 재할당이 계속 잃어나는 일을 방지

        for (size_t i = 0; i < 10; i++)
        {
            Standard.push_back(i);
            printf_s("Capacity %zd\n", Standard.capacity());
            printf_s("Size %zd\n", Standard.size());
        }

        for (size_t i = 0; i < Standard.size(); i++)
        {
            printf_s("Value : %d\n", Standard[i]);
        }

        printf_s("size : %d", (int)Standard.size());
    }

    {
        std::vector<int> Test1;

        Test1.reserve(10);
        // 벡터에서의 공간만 확장하고 원소는 넣어주지 않는 함수 : reserve

        int Siz = Test1.size();             // Siz = 0
        int Cap = Test1.capacity();         // Cap = 10

        Test1.resize(10);

        int Siz1 = Test1.size();
        int Cap1 = Test1.capacity();

        std::vector<int> Test2;

        Test2.resize(10);
        // 벡터에서의 공간을 확장하면서 원소 자체도 넣어주는 함수 : resize

        int Siz2 = Test2.size();            // Siz2 = 10
        int Cap2 = Test2.capacity();        // Cap2 = 10

        int a = 0;
    }
}
