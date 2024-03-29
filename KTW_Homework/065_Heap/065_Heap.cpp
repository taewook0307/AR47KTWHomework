﻿#include <iostream>
#include <crtdbg.h>

int main()
{
    // 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 가장 자유롭게 메모리를 할당할 수 있는 영역 : 힙 영역

    // 연산자  자료형  생성자
    //  new    자료형    ();
    // ex) new int();           => 메모리의 힙영역에 int하나를 만든 것 : 주소값
    int* Ptr = new int();   // 받아야 사용가능 
    // new int(); 잃어버린 힙 : 포인터 변수로 받지 않으면 사용 불가

    *Ptr = 20;

    // 힙은 사용한 후 메모리를 지워야 함 : 지우지 않아도 잃어버린 메모리
    delete Ptr; // 사용 후 지우는 코드

    // 힙영역을 할당하고 지우지 않으면
    // Leak 혹은 메모리 누수
    // 메모리 누수 때문에 프로그램을 종료해도 컴퓨터가 느려지지 않음 => 내 프로그램이 느려질 수는 있음
    // 강제 종료의 경우 어쩔 수 없이 릭이 남을 수 있음
}