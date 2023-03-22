#include <iostream>

int main()
{
    // 궁극적으로 모든 배열은 결국 1차원 배열 <= 배열은 램에 존재하고 램은 1차원 배열

    int Arr[3][2] = { {1,2},{3,4},{5,6} };
    /*  2차원 배열에 대한 생각
    [1] [2]
    [3] [4]
    [5] [6]
    */

    int Value00 = Arr[0][0];
    __int64 Address00 = (__int64) &Arr[0][0];
    int Value00 = Arr[0][1];
    __int64 Address01 = (__int64)&Arr[0][1];
    int Value00 = Arr[1][0];
    __int64 Address10 = (__int64)&Arr[1][0];
    int Value00 = Arr[1][1];
    __int64 Address11 = (__int64)&Arr[1][1];
    int Value00 = Arr[2][0];
    __int64 Address20 = (__int64)&Arr[2][0];
    int Value00 = Arr[2][1];
    __int64 Address21 = (__int64)&Arr[2][1];

    // 주소값을 통한 2차원 배열의 모양
    // [1][2][3][4][5][6]
}
