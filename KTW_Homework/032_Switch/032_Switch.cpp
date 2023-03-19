#include <iostream>

int main()
{
	// 자동완성 기능
	// swi 입력 후 tab
	// if 입력 후 tab

	{
		int Value = 0;

		// if문은 메모리 영역이 참인지 거짓인지 판단해서 코드를 실행해주는 조건문
		// switch문은 메모리 영역과 완전히 같은 상수 메모리가 있는지 비교해주는 조건문

		switch (Value)
		{
		// case 뒤에는 상수 메모리(상수, 문자, const형 변수)만 가능
		// case Value: <= 변수 사용 불가능
		case 0:
			printf_s("Value = 0\n");
			break;

		// case 안에서 변수를 선언하려면 따로 지역을 분류해야됨
		case 1:
		{
			int a = 0;

			printf_s("Value = 0\n");
			break;
		}

		case 2:
			printf_s("Value = 0\n");
			break;

		// case에서 같은 메모리 영역이 없을 시 default 실행
		default:
			break;
		}
	}

	{
		char InputKey = 'a';

		switch (InputKey)
		{
		case 'a':
		case 'A':
			printf_s("에이를 쳤습니다\n");
			break;
		default:
			break;
		}
	}
}
