// 함수의 선언방법
// 1. 다른 함수 내부에서는 선언하지 못함
// 2. 함수는 리턴값이라는 것이 무조건 존재
   
// 함수는 만들면 만들수록 느려짐
   
//리턴값     이름      인자(이 함수에 넘길 메모리 = 매개변수 = parameter)
void    Function      ()
{// Function 함수의 시작
    return;
}// Function 함수의 끝

// 함수의 리턴값의 의미
// 이 함수의 결과를 외부로 보냄
// void는 아무것도 보내지 않겠다는 의미
// 외부에 자신의 결과값을 받기위한 메모리 공간이 필요함을 알림

// 이름의 의미
// 해당 함수의 램에서의 메모리 위치 주소값
// 변수의 이름의 의미와 동일

// 인자의 의미
// 그 실행흐름의 지역변수를 의미
   
// return의 의미
// 자신을 호출한 외부 메모리 영역에 전달하는 메모리값
// + 사용한 즉시 자신을 포함한 실행흐름을 끝낸다.



// 함수를 실행하는데 필요한 메모리 비용 : 인자 전체 크기 + a
int Plus(int _Left, int _Right)     // 필요한 메모리 비용 : 8byte(인자 _Left와 _Right의 byte값) + a
// Plus라는 이름의 함수
// 지역변수로 _Left, _right를 가짐
// 해당 함수를 실행한 외부 메모리 영역에 4byte 값을 전달
{
    return _Left + _Right;
}

void Test(int _Value) {     // 필요한 메모리 비용 : 4byte(인자 _Value의 byte값) + a
    _Value = 10;
    return;
}

int main()
{
    Plus(20, 30);   // 4byte를 메모리에서 사용한 것
    // 20, 30 처럼 함수를 호출할 때 사용하는 값 : 인수

    int ReturnResult = sizeof(Plus(20, 30));
    // void는 sizeof를 할 수 없음
    // sizeof(Test(20)) <= 실행 불가능 : Test()함수가 void 타입이라서
}