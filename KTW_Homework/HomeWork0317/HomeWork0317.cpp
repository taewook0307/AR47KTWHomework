#include <iostream>

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로
int StringCount(const char* _String)
{
    int Count = 0;

    while (_String[Count])
    {
        char Ch = _String[Count];
        Count++;
    }

    int Result = Count;

    return Result;
}

// 공백제거
int TrimDelete(char* _String)
{
    int check = 0;
    int num = 0;

    while (_String[check])
    {
        char ch = _String[check];

        if ((int)ch == 32)          // 가져온 문자가 띄어쓰기(빈칸)일 경우
        {
            check++;
        }

        else
        {
            _String[num] = _String[check];
            check++;
            num++;
        }
    }

    //공백제거 후 뒷부분을 0으로 변환
    _String[num] = 0;

    return 0;
}

// 문자열을 정수형으로 변환
int StringToInt(const char* _String)
{
    int Count = 0;

    int Result = 0;

    while(_String[Count])
    {
        char Check = _String[Count];

        // Result값이 0이 아닐 때
        if (Result != 0)
        {
            switch (Check)
            {
            case'1':
                Result *= 10;
                Result += 1;
                break;
            case'2':
                Result *= 10;
                Result += 2;
                break;
            case'3':
                Result *= 10;
                Result += 3;
                break;
            case'4':
                Result *= 10;
                Result += 4;
                break;
            case'5':
                Result *= 10;
                Result += 5;
                break;
            case'6':
                Result *= 10;
                Result += 6;
                break;
            case'7':
                Result *= 10;
                Result += 7;
                break;
            case'8':
                Result *= 10;
                Result += 8;
                break;
            case'9':
                Result *= 10;
                Result += 9;
                break;
            default:
                Result *= 10;
                break;
            }
        }

        // Result값이 0일때
        else
        {
            switch (Check)
            {
            case'1':
                Result += 1;
                break;
            case'2':
                Result += 2;
                break;
            case'3':
                Result += 3;
                break;
            case'4':
                Result += 4;
                break;
            case'5':
                Result += 5;
                break;
            case'6':
                Result += 6;
                break;
            case'7':
                Result += 7;
                break;
            case'8':
                Result += 8;
                break;
            case'9':
                Result += 9;
                break;
            default:
                break;
            }
        }
        Count++;
    }

    return Result;
}

// 문자열을 정수형으로 변환(switch 사용 안 하고 간단하게)
int StringToIntShortly(const char* _String)
{
    int Count = 0;

    int Result = 0;

    while (_String[Count] && _String[Count] >= '0' && _String[Count] <= '9')
    {
        char Check = _String[Count];

        Result = Result * 10 + ((int)_String[Count] - 48);
        Count++;
    }

    return Result;
}

// 숫자 외 다른 문자가 들어간 문자열에서 숫자를 빼와 정수형으로 변환
int StringCheckInt(const char* _String)
{
    int Count = 0;

    int Result = 0;

    while (_String[Count])
    {
        if (_String[Count] >= '0' && _String[Count] <= '9')
        {
            char Check = _String[Count];

            Result = Result * 10 + ((int)_String[Count] - 48);
            Count++;
        }
        else
        {
            Count++;
        }
    }

    return Result;
}

int main()
{
    int Return0 = StringCount("aaaa");
    int Return1 = StringCount("aaaa ggg sss");

    char Arr0[1024] = "a b c d e";
    char Arr1[1024] = "a    b c    d    e";
    char Arr2[1024] = "ab    cde    ";

    TrimDelete(Arr0);
    printf_s(Arr0);
    TrimDelete(Arr1);
    printf_s(Arr1);
    TrimDelete(Arr2);
    printf_s(Arr2);

    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1111");
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");

    // StringToInt 함수를 switch 안 쓰고 간략하게
    int IValue0 = StringToIntShortly("111");
    int IValue1 = StringToIntShortly("432");
    int IValue2 = StringToIntShortly("532");
    int IValue3 = StringToIntShortly("645");

    // 영어나 다른 문자가 섞여 들어가 있는 곳에서 숫자만 순서대로 출력
    int UValue0 = StringCheckInt("1a 34 2");
    int UValue1 = StringCheckInt("uao 342 45 4kd");
    int UValue2 = StringCheckInt("59 kkle 23k3");
    int UValue3 = StringCheckInt("sl2k3i4k k33");
    int UValue4 = StringCheckInt("나23$2i {:12");

    int a = 0;
}