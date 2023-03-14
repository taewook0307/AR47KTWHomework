#include <iostream>

int main()
{
	int ArrSize = 20;

	int Value[10] = {};
	//int Value[ArrSize] = {};	<= 오류
	//함수의 스택에서의 메모리 크기는 컴파일시 고정되어야 하기 때문이다.
	//c++의 함수의 실행흐름을 만들기 위한 (스택크기)는 exe파일에 이미 다 정의되어 있어야 한다.
	//int Value[변수] = {}; <= 사용 불가

	const int ArrSize1 = 20;

	int Value[ArrSize1] = {};

	//특정 자료형 앞에 const 키워드를 붙이면 그 메모리의 비트적 상수화를 시킨다.
	//ArrSize1 = 30;	<= const를 붙이면 해당 메모리(변수)는 상수화 : 변경 불가능
}