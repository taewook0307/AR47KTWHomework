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
    Test.insert(std::pair<int, int>(7, 1));
    Test.insert(std::pair<int, int>(6, 5));
    Test.insert(std::pair<int, int>(3, 15));
    Test.insert(std::pair<int, int>(16, 23));
    Test.insert(std::pair<int, int>(12, 45));

    /*
                    7       <= R
                    oot Node

                6       16
                        
            3         12
    
    키 값이 작으면 왼쪽
    키 값이 크면 오른쪽
    
    키 값에 의해 들어오는 pair의 방향이 결정 : 키 값 변경 불가능
    value 값은 상관 없음
    */
    

    // insert 하는 방법
    // Test.insert(std::pair<int, int>(1, 1));
    // Test.insert(std::make_pair(1, 1));
    // Test.insert(std::map<int, int>::value_type(1, 1));
}