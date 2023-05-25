#include <iostream>

// #define은 복사 붙여넣기
// TEST를 정의했다는 의미
#define TEST

// TEST가 정의되어 있지 않으면
#ifdef TEST

//
#else

//
#endif

int main()
{
    std::cout << "Hello World!\n";
}