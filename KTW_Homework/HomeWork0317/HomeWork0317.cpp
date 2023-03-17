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
        if ((int)ch == 32)
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

//문자열을 정수형으로 변환
int StringToInt(const char* _String)
{
    int Count = 0;

    int Result = 0;

    while(_String[Count])
    {
        char Check = _String[Count];

        //Result값이 0이 아닐 때
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
        //Result값이 0일때
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
}