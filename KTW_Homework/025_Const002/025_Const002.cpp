#include <iostream>

int main()
{
    int Value = 10;

    int* Ptr = &Value;

    // 자료형* <= 포인터 문법
    const int* Ptr0 = &Value;

    // const int*
    // 포인터형 변수가 사용할 때 *을 붙이는 것은
    // 자신의 자료형에서 *을 뺀 자료형으로 사용하겠다는 의미
    // ex) const int* Ptr = &Value;   =>   *Ptr의 자료형은 const int
    // *Ptr = 20; <= 사용 불가능(오류 발생) : const int 타입이니까

    // 10번 줄의 코드처럼 Value를 const로 선언하지 않았더라도
    // 포인터 변수 Ptr0의 자료형을 const int로 했기 때문에
    // *Ptr0 = 20;   <= 코드는 실행 불가능 : Value의 값을 포인터 연산자를 이용해서 변경할 수 없음.

    // 둘은 동일 (코드 스타일 차이)
    const int Value0 = 10;
    int const Value1 = 10;

    {
        int num = 0;

        const int* const Ptr = &num;
        // Ptr번지의 있는 값 num을 변경할 수도 없고, Ptr번지도 변경할 수 없음
        // *뒤에 뭔가를 붙이는 건 *에 영향을 주는 문법

        char Test0 = 'A';
        // 100번지에 있는 A
        char Test1 = 'B';
        // 120번지에 있는 B

        const char* const Chr = &Test0;
        // 140번지에 있는 100
        // 자료형* const : 포인터 변수가 가리키는 주소값을 바꾸지 못하게 함
        // Chr = &Test1;    <= 오류 발생 : * 뒤에 const가 붙어있기 때문에
    }

    {
        // const int Value; <= 반드시 초기화를 해줘야 함
        const int Value = 0;
    }
}