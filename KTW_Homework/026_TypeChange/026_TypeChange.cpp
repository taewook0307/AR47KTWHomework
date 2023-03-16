#include <iostream>

int main()
{
	{
		//형변환은 연산을 해서 비트를 변경하는 일

		bool bValue = true;
		int AValue = 12345678;
	}
	{
		//아예 변환을 허용하지 않는 자료형 관계
		int Value = 0;
		int* Ptr = nullptr;
		//Value = Ptr;
		//Ptr = Value;
	}
	{
		//메모리가 생기면 자료형이 존재
		int Arr[10] = {};		//배열의 자료형 : int [10]

		// int*	  int[10]
		//자료형이 다른데 대입이 됨 => 암시적 형변환
		int* Ptr = Arr;
	}

	printf_s("aaaaa");
	// const char* const <= const char[6] : 암시적 형변환이 발생
}
