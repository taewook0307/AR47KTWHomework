#include <iostream>

int main()
{
	{
		// 음수(부호비트)를 사용하겠다
		signed int Value = 0b00000000000000000000000000000001;
	}

	{
		// 부호비트를 사용하지 않겠다.(양수만 사용)
		// 자료형은 그 자체로 처리형태와 어떻게 값을 보여줘야할지를 표현
		unsigned int Value = ~0;
	}
}
