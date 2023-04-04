#include <iostream>

// 함수도 프로세스로 메모리에 올라가기 때문에 위치가 존재
void PlayerAttack()
{
    printf_s("공격\n");
}

void PlayerMove()
{
    printf_s("이동\n");
}

int main()
{
    // 리턴값 (*함수 포인터명) (인자)
    void(*Ptr)() = PlayerAttack;

    Ptr();

    Ptr = PlayerMove;


    Ptr();

	int Value = sizeof(Ptr);		// 함수 포인터도 포인터이기 때문에 크기는 8바이트

	{
		int ArrValue[20];
		int* Ptr = ArrValue;
		*Ptr;

		// ArrValue = int[]
		// Ptr = int*
		// *Ptr = int
		// Ptr[0] = int
		// Ptr[1] = int


		int* ArrTest[20];
		int** PtrAAA = ArrTest;
		*PtrAAA;

		// ArrTest = int*[]
		// PtrAAA = int**
		// *PtrAAA = int*
		// PtrAAA[0] = int*
		// PtrAAA[1] = int*
	}

	{
		// void(*Ptr)();		void(*)()형
		void(*ArrFunction[20])();
		ArrFunction[0] = PlayerAttack;
		void(**PtrTest)() = ArrFunction;
		PtrTest[0]();
		int Size = sizeof(PtrTest);

		// ArrTest = void(*[])()
		// PtrTest = void(**)()
		// *PtrTest = void(*)()
		// PtrTest[0] = void(*)()
		// PtrTest[1] = void(*)()

		// sizeof(PtrTest) == 8
	}
}