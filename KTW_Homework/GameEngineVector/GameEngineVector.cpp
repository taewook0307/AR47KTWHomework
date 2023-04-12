#include <iostream>
#include <vector>

// vector는 배열을 대체

// 일반적인 배열은 선언과 동시에 접근이 가능
// [][][][][][][][][][][접근]

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
        std::vector<int> Standard;
    }

    // Test.resize(10);
    // push_back 10번을 한 것과 똑같은 크기로 만들어줌
    // 원소 자체도 넣어주는 함수 : resize

    // Test.reserve(10);
}
