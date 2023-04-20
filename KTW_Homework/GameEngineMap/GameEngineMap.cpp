#include <iostream>
#include <map>

// map을 사용하는 이유
// 탐색을 용이하게 하기 위해 != 탐색이 빠르다
// 사용성이 좋음

int main()
{
    std::map<int, int> Test;

    // insert는 pair<int, int>를 달라고 하는 함수
    // 키가 겹칠때는 무시하면서 리턴해주는게 정상적으로 들어간 노드를 리턴
    Test.insert(std::pair<int, int>(6, 1));
    Test.insert(std::pair<int, int>(3, 5));
    Test.insert(std::pair<int, int>(10, 15));
    Test.insert(std::pair<int, int>(1, 23));
    Test.insert(std::pair<int, int>(5, 45));
    Test.insert(std::pair<int, int>(8, 5));
    Test.insert(std::pair<int, int>(11, 6));
    Test.insert(std::pair<int, int>(2, 23));
    Test.insert(std::pair<int, int>(4, 36));
    Test.insert(std::pair<int, int>(7, 25));
    Test.insert(std::pair<int, int>(9, 126));

    /*
                                 6

                 3                                10

          1            5                   8               11

              2     4                 7         9
    키 값이 작으면 왼쪽
    키 값이 크면 오른쪽
    
    키 값에 의해 들어오는 pair의 방향이 결정 : 키 값 변경 불가능
    value 값은 상관 없음
    */
    

    // insert 하는 방법
    // Test.insert(std::pair<int, int>(1, 1));
    // Test.insert(std::make_pair(1, 1));
    // Test.insert(std::map<int, int>::value_type(1, 1));

    std::map<int, int>::iterator Start = Test.begin();
    std::map<int, int>::iterator End = Test.end();

    for (; Start != End; Start++)
    {
        int Key = Start->first;
        int Value = Start->second;

        printf_s("Key : %d\n", Key);
        // printf_s("Value : %d\n", Value);
    }
}