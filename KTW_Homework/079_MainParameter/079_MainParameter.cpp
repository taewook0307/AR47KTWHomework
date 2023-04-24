#include <iostream>

int main(int _Count, const char** _InitText)
{
    // 내 프로세스가 다른 프로세스를 실행할 수도 있다.
	int Result = system("C:\\Users\\user\\Desktop\\AR\\Project\\AR47KTWHomework\\KTW_Homework\\x64\\Debug\\078_BitTest.exe");

	std::cout << std::endl << "main함수 경로" << std::endl;

	for (size_t i = 0; i < _Count; i++)
	{
		// 프로그램이 실행되는 경로를 줌 : main의 인자
		// char*
		std::cout << _InitText[i] << std::endl;
	}

	return 1;
}