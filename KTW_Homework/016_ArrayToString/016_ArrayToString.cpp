int main()
{
    //어떤 자료형을 봤다면 그것은 추가적인 문법으로 모두 다 배열로 변경 가능
    {
        int Value = 10;

        //배열로 만드는 방법
        //{}안에 값을 넣지 않으면, 자동으로 전부 다 0으로 초기화
        int ArrValue[5] = {};
        //ArrValue = { 0, 0, 0, 0, 0 };

        int ArrValue1[5] = { 2, };
        //ArrValue1 = { 2, 0, 0, 0, 0 };

        //int ArrValue[5]; <= 초기화를 안 한 상태

        bool ArrValue2[5] = { true, false, };

        //배열 내 값의 주소값
        //bool ArrValue = { true, true, false, false, false }
        //주소값             100   101   102    103    104  <= bool은 1바이트
        //int ArrayValue = { 0,  1,  2,  3,  4 }
        //주소값            100 104 108 112 116     <= int는 4바이트

        ArrValue[2];
        //ArrValue[정수]
        //ArrValue 시작위치 + sizeof(자료형) * 정수
        //위치의 데이터에 접근하겠다라는 뜻

        ArrValue2[3];
        //ArrValue2 == 100번지
        //100 + sizeof(char) * 3 => 100 + 1 * 3 => 103번지
    }

    //문자의 배열은 축약한 표현을 사용 가능
    {
        char ArrValue[5] = { 'a','b','c' };

        //쌍따옴표를 이용하여 축약 표현 가능
        char ArrValue1[5] = "abc";
    }
}
