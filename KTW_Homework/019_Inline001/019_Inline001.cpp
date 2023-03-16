#include <iostream>

// 컴파일러 판단에 따라 안 될 가능성이 있음
inline void Test() {
    printf_s("Function");
}

int main()
{
    Test();
    // inline은 최적화할 수 있다면 해달라는 코드
    // Test() 함수 안에 내용을 복사 붙여넣어 실행
    // 메모리 스택 영역에 Test() 함수를 위한 메모리 할당을 하지 않음
}
