#include <iostream>

// 이제부터 자료형 unsigned __int64를 size_t라고 부르겠다.
// typedef         unsigned __int64   size_t;
// unsigned __int64 == size_t
// 유저가 정의한 자료형(사용자 정의 자료형의 일종)

// typedef __int64 __time64_t;
// typedef __time64_t time_t;

// using __int64 __time64_t
// using하고 typedef와 같음

int main()
{
    time_t DTime = time(0);     // unsigned __int64 DTime = time(0);
}