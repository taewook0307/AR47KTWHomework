#include <iostream>

#include "GameEngineArray.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		GameEngineArray Array0(10);

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			Array0[i] = i;
		}

		Array0.ReSize(15);

		printf_s("15로 사이즈 변경\n");

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			printf_s("%d\n", Array0[i]);
		}

		Array0.ReSize(5);

		printf_s("5로 사이즈 변경\n");

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			printf_s("%d\n", Array0[i]);
		}
		
		printf_s("10으로 사이즈 변경\n");

		Array0.ReSize(10);

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			printf_s("%d\n", Array0[i]);
		}
	}

	{
		GameEngineArray Array0(10);
		GameEngineArray Array1(5);

		// Array1 = Array0;
		// 오류 나는 이유
		// 49번째 줄로 인해
		// Array1의 ArrPtr이 가리키는 힙 메모리 영역이 Array0가 가리키는 힙 메모리 영역과 같아진다.
		// 이후 코드가 끝난 후 delete를 실행할 때 같은 힙 메모리 영역을 두 번 delete 하므로
		// 메모리 크러쉬가 발생한다.
	}

	{
		GameEngineArray Array0(10);
		GameEngineArray Array1(5);

		for (size_t i = 0; i < Array0.Count(); i++)
		{
			Array0[i] = i;
		}

		Array1 = Array0;

		printf_s("\nArray1 출력\n");

		for (size_t i = 0; i < Array1.Count(); i++)
		{
			printf_s("%d\n", Array1[i]);
		}
	}
}