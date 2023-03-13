int main()
{
    //삼항 연산자
    //a ? b : c
    //참 혹은 거짓 메모리 ? 참일 때 메모리 : 거짓일 때 메모리

    int Left = 7;
    int Right = 3;
    int Result = 0;

    Result = (Left != Right ? 100 : 200);

    //sizeof        단항 연산자
    //()에 있는 메모리 영역의 바이트 크기를 리턴
    //사용법 : sizeof(메모리 영역)
    Result = sizeof(Left);
    Result = sizeof(int);
    Result = sizeof(bool);
    Result = sizeof(true);
}
