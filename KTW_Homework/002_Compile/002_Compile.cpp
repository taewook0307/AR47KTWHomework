// 002_Compile.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


//.exe파일을 만들어내는 과정을 컴파일이라고 함
//전처리기 -> 컴파일러 -> 어셈블러 -> 링커 -> .exe   이러한 과정을 거침

// <= 주석 : 코드에 영향을 주지 않는 설명문 or comment, 전처리문의 일종

//전처리기는 전처리문을 처리하는 단계
//전처리기가 하는 일
//전처리문 제거

//전처리문의 종류
// 1. #이 붙어있으면 웬만하면 전처리문

//#include <파일명> => 파일명을 가진 파일을 사용하겠다는 의미
//#include <iostream> => iostream 파일을 사용하겠다는 의미
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
