#include "GameEngineMap.h"

#include <iostream>
#include <map>
#include <GameEngineBase/GameEngineDebug.h>

// map을 사용하는 이유
// 탐색을 용이하게 하기 위해 != 탐색이 빠르다
// 사용성이 좋음

int main()
{
    GameEngineDebug::LeckCheck();
    //{
    //    std::map<int, int> Test;

    //    // insert는 pair<int, int>를 달라고 하는 함수
    //    // 키가 겹칠때는 무시하면서 리턴해주는게 정상적으로 들어간 노드를 리턴
    //    Test.insert(std::pair<int, int>(10, rand()));
    //    Test.insert(std::pair<int, int>(7, rand()));
    //    Test.insert(std::pair<int, int>(15, rand()));
    //    Test.insert(std::pair<int, int>(25, rand()));
    //    Test.insert(std::pair<int, int>(17, rand()));
    //    Test.insert(std::pair<int, int>(15, rand()));
    //    Test.insert(std::pair<int, int>(18, rand()));
    //    Test.insert(std::pair<int, int>(6, rand()));
    //    Test.insert(std::pair<int, int>(4, rand()));
    //    Test.insert(std::pair<int, int>(5, rand()));
    //    Test.insert(std::pair<int, int>(2, rand()));
    //    Test.insert(std::pair<int, int>(9, rand()));
    //    Test.insert(std::pair<int, int>(8, rand()));
    //    Test.insert(std::pair<int, int>(1, rand()));

    //    /*
    //                                 10

    //                 7                                15

    //           6           9                                 25

    //       4           8                                  17

    //   2       5                                              18

    //1
    //    키 값이 작으면 왼쪽
    //    키 값이 크면 오른쪽

    //    키 값에 의해 들어오는 pair의 방향이 결정 : 키 값 변경 불가능
    //    value 값은 상관 없음
    //    */


    //    // insert 하는 방법
    //    // Test.insert(std::pair<int, int>(1, 1));
    //    // Test.insert(std::make_pair(1, 1));
    //    // Test.insert(std::map<int, int>::value_type(1, 1));

    //    std::map<int, int>::reverse_iterator Start = Test.rbegin();
    //    std::map<int, int>::reverse_iterator End = Test.rend();

    //    std::cout << "std::map 출력" << std::endl;

    //    for (; Start != End; ++Start)
    //    {
    //        int Key = Start->first;
    //        int Value = Start->second;

    //        std::cout << "Key : " << Key << std::endl;
    //        // printf_s("Value : %d\n", Value);
    //    }
    //}

    {
        GameEngineMap<int, int> Test;

        // insert는 pair<int, int>를 달라고 하는 함수
        // 키가 겹칠때는 무시하면서 리턴해주는게 정상적으로 들어간 노드를 리턴
        Test.insert(GameEnginePair <int, int>(10, rand()));
        Test.insert(GameEnginePair <int, int>(7, rand()));
        Test.insert(GameEnginePair <int, int>(15, rand()));
        Test.insert(GameEnginePair <int, int>(25, rand()));
        Test.insert(GameEnginePair <int, int>(17, rand()));
        Test.insert(GameEnginePair <int, int>(18, rand()));
        Test.insert(GameEnginePair <int, int>(6, rand()));
        Test.insert(GameEnginePair <int, int>(4, rand()));
        Test.insert(GameEnginePair <int, int>(5, rand()));
        Test.insert(GameEnginePair <int, int>(2, rand()));
        Test.insert(GameEnginePair <int, int>(9, rand()));
        Test.insert(GameEnginePair <int, int>(8, rand()));
        Test.insert(GameEnginePair <int, int>(1, rand()));

        /*
                                     10

                     7                                15

               6           9                                 25

           4           8                                  17

       2       5                                              18

    1
        키 값이 작으면 왼쪽
        키 값이 크면 오른쪽

        키 값에 의해 들어오는 pair의 방향이 결정 : 키 값 변경 불가능
        value 값은 상관 없음
        */


        // insert 하는 방법
        // Test.insert(std::pair<int, int>(1, 1));
        // Test.insert(std::make_pair(1, 1));
        // Test.insert(std::map<int, int>::value_type(1, 1));

        GameEngineMap<int, int>::iterator StartIter = Test.begin();
        GameEngineMap<int, int>::iterator EndIter = Test.end();

        std::cout << "GameEngineMap 출력" << std::endl;

        for (; StartIter != EndIter; ++StartIter)
        {
            int Key = StartIter->first;
            int Value = StartIter->second;

            std::cout << "Key : " << Key << std::endl;
            // printf_s("Value : %d\n", Value);
        }

        std::cout << "전위 순회" << std::endl;
        Test.FirstOrder();
        std::cout << "중위 순회" << std::endl;
        Test.MidOrder();
        std::cout << "후위 순회" << std::endl;
        Test.LastOrder();
    }
}