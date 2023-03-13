int main()
{
    //f5 => 중단점이 존재하는 데까지 한 번에 실행
    //f10 => 
    int Left = 9;
    int Right = 5;
    int Result = 0;

    //연산자
    //단항 연산자 : 메모리 영역이 1개만 필요
    //이항 연산자 : 메모리 영역이 2개만 필요
    //삼항 연산자 : 메모리 영역이 3개만 필요

    //산술 연산자
    Result = Left + Right;
    Result = Left - Right;
    Result = Left * Right;
    Result = Left / Right;
    Result = Left % Right;
    Result -= Left;
    Result += Left;
    //전위, 전치
    Result = ++Left;
    Result = --Left;
    //후위, 후치
    Result = Left++;
    Result = Left--;

    //연산자 순서
    Result = 1 + 2 * 3;     // *, / 연산자가 +, - 연산자 보다 먼저
    Result = (1 + 2) * 3;   // () 안에 연산자를 먼저

    //bool
    //논리형 : true 와 false 2가지로만 표현할 수 있는 자료형
    //true 논리형 상수 참
    //false 논리형 상수 거짓
    bool bResult = true;
    bResult = false;

    //비교 연산자 / 관계 연산자
    bResult = Left == Right;        //false
    bResult = Left != Right;        //true
    bResult = Left < Right;         //false
    bResult = Left > Right;         //true
    bResult = Left <= Right;        //false
    bResult = Left >= Right;        //true

    //논리 연산자
    //and : 둘 다 참이면 참, 하나라도 거짓이면 거짓
    bResult = true && true;         // true
    bResult = true && false;        // false
    bResult = false && true;        // false
    bResult = false && false;       // false
    //or : 둘 중 하나라도 참이면 참, 둘 다 거짓이면 거짓
    bResult = true || false;        // true
    bResult = true || false;        // true
    bResult = false || true;        // true
    bResult = false || false;       // false
 }