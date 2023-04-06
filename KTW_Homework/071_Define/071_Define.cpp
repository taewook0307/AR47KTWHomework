#include <iostream>

#define Ten 10

// 함수형
// 매크로 함수
// 일반 함수는 형에 대한 검사나 자료형에 의한 컴파일 체크를 하지만
// 매크로 함수는 무조건 복사 붙여넣기 형식을 하기 때문에 스택에 따로 함수를 위한 공간을 할당하지 않음
#define Plus(Value) Value + Value

#define Plus(Value, Value2) Value + Value2

int main()
{
    // define 보다 inline을 사용하도록 추천
    // inline 사용 시 컴파일러가 검사를 하기 때문에 더 안전
}