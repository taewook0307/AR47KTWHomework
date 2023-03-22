#include <iostream>

int main()
{
    // 스택 영역에 있는 const char*형				코드 영역에 있는 char[7]형
    const char* Ptr = "김태욱";

    // char [][] 2차원
    // 글자 20개짜리 배열을 30개 만들어라
    // char Arr[30][20] = {};

    // 궁극적으로 모든 배열은 결국 1차원 배열 <= 배열은 램에 존재하고 램은 1차원 배열

    int Arr[3][2] = { {1,2},{3,4},{5,6} };
    /*  2차원 배열에 대한 생각
    [1] [2]
    [3] [4]
    [5] [6]
    */

    int Value00 = Arr[0][0];
    __int64 Address00 = (__int64) &Arr[0][0];       // Address00 = 200이라 가정
    int Value01 = Arr[0][1];
    __int64 Address01 = (__int64)&Arr[0][1];        // Address01 = 204
    int Value10 = Arr[1][0];
    __int64 Address10 = (__int64)&Arr[1][0];        // Address10 = 208
    int Value11 = Arr[1][1];
    __int64 Address11 = (__int64)&Arr[1][1];        // Address11 = 212
    int Value20 = Arr[2][0];
    __int64 Address20 = (__int64)&Arr[2][0];        // Address20 = 216
    int Value21 = Arr[2][1];
    __int64 Address21 = (__int64)&Arr[2][1];        // Address21 = 220

    // 주소값을 통한 2차원 배열의 모양
    // [1][2][3][4][5][6]

    // Arr 2차원
    // Arr[0]; => 2차원 배열에서 1차원 배열로 변환

    int a = 0;
}
