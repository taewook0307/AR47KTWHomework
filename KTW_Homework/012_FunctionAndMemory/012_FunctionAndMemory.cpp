﻿// main 이라는 이름의 실행흐름
// 실행흐름을 위한 메모리가 필요

// 내가 이름을 붙인 실행흐름 = 함수
void Function()         // 내가 만든 Function이란 이름의 실행흐름, 함수
{
    return;
}

int main()
{// 함수의 시작, 실행흐름의 시작
    
    int Value = 100;

    // 스코프
    // 실행흐름의 시작과 끝을 표현하는 기호 : {}
    // 단 이름이 있는 실행흐름 안에서만 만들기 가능

    // Unname scope
    {
        int Value = 10;     // Unname scope 메모리(스택 영역) 내에서 존재하다가 Unname scope가 끝나면 같이 사라짐
                            // 그래서 Unname scope 밖에서는 사용 불가능
        // main함수 내 Value와 Unname scope 내 Value는 서로 다른 메모리에 생성되기 때문에 서로 같은 변수가 아님
    }

    // 함수 실행 방법
    // f11을 누르면 다른 이름있는 실행흐름 내부로 들어갈 수 있음
    // f10은 그 실행흐름을 한 번에 다 실행해버리는 용도
    Function();

}// 함수의 끝, 실행흐름의 끝
