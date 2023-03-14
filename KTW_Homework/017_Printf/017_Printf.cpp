#include <iostream>

//컨트롤 + k + c 내가 선택한 범위 주석

int main()
{
    //콘솔창에 글자를 띄운다.
    printf_s("aaaa");

    char Arr[5] = { '1','2','3','4','5' };

    //char Value1 = Arr; <= 오류 발생 : 자료형이 다르기 때문에

    //제로 베이스 기반
    //배열의 개수를 셀 때 0부터 세는 것을 제로베이스 기반 인덱스 표현
    char Value1 = Arr[0]; //<= Value1 = '1';
    char Value2 = Arr[1]; //<= Value2 = '2';
    char Value3 = Arr[2]; //<= Value2 = '3';
    char Value4 = Arr[3]; //<= Value2 = '4';
    char Value5 = Arr[4]; //<= Value2 = '5';

    //문자열의 끝을 표현하기 위해 뒤에 0을 붙여줌
    //0이 없으면 문자열이 끝이라고 생각하지 않음
    //printf_s는 0을 만날때까지를 계속 출력하는 함수
    //printf_s(Arr);      //<= 12345 뒤에 이상한 값이 출력

    char Arr1[5] = { '1','2','3','4', 0 /*'5'*/};

    printf_s(Arr1);

    //char Arr[5] = "12345" <= 뒤에 0이 자동으로 붙기 때문에 Arr[5] > Arr[6]으로 바꿔주어야 한다
    char Arr2[6] = "12345";

    printf_s(Arr2);
}
