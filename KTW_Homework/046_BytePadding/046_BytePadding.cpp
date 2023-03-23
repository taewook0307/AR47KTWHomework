#include <iostream>

// BytePadding 현상
// 8byte 이하 가장 큰 바이트의 자료형을 찾는다
// 가장 큰 바이트만큼 메모리 할당
// 할당받은 메모리에 첫번째 변수를 넣음
// 그다음 변수를 넣을 수 있으면 넣고 아니면 가장 큰 바이트만큼 메모리 다시 할당
// 두번째로 할당받은 메모리에 넣지 못한 다음 변수 넣음

//short : 2바이트 정수형

class Test
{
public:                 // 주소값 확인(padding byte) : 숙제
    int Value;
    short Value0;
    __int64 Value1;
};

class Test0
{
public:
    char Num;
    int Num0;
    short Num1;
    char Num2;
    __int64 Num3;
};

class Player
{
public:
    char Name;
    __int64 Hp;
    int Att;
    int Def;
    short Speed;
    char SubName;
    int Armor;
};

int main()
{
    Test NewTest = Test();
    Test0 NewTest0 = Test0();
    Player NewPlayer = Player();

    int Size = sizeof(Test);            // Size = 16
    int Size0 = sizeof(Test0);          // Size = 24
    int SizeP = sizeof(Player);

    printf_s("%d\n", Size);
    printf_s("%d\n", Size0);
    printf_s("%d", SizeP);

    int* IntPtr = &NewTest.Value;
    __int64 AddressValue = (__int64)IntPtr;                     // AddressValue = 200 이라 가정

    short* ShortPtr = &NewTest.Value0;
    __int64 AddressValue0 = (__int64)ShortPtr;                  // AddressValue0 = 204

    __int64* __Int64Ptr = &NewTest.Value1;
    __int64 AddressValue1 = (__int64)__Int64Ptr;                // AddressValue1 = 208

/*
 200    201    202    203    204    205    206    207    208    209    210    211    212    213    214    215
Value                      |Value0        |             Value1                                
*/



    char* CharPtr0 = &NewTest0.Num;
    __int64 AddressNum = (__int64)CharPtr0;                     // AddressNum = 200 이라 가정

    int* IntPtr0 = &NewTest0.Num0;
    __int64 AddressNum0 = (__int64)IntPtr0;                     // AddressNum0 = 204

    short* ShortPtr0 = &NewTest0.Num1;
    __int64 AddressNum1 = (__int64)ShortPtr0;                   // AddressNum1 = 208

    char* CharPtr02 = &NewTest0.Num2;
    __int64 AddressNum2 = (__int64)CharPtr02;                   // AddressNum2 = 210

    __int64* __Int64Ptr0 = &NewTest0.Num3;
    __int64 AddressNum3 = (__int64)__Int64Ptr0;                 // AddressNum3 = 216

/*
200    201    202    203    204    205    206    207    208    209    210    211    212    213    214    215    216    217    218    219    220    221    222    223
Num |                       Num0                      | Num1        | Num2 |                                    Num3
*/



    char* NamePtr = &NewPlayer.Name;
    __int64 AddressName = (__int64)NamePtr;                     // AddressName = 200 이라 가정

    __int64* HpPtr = &NewPlayer.Hp;
    __int64 AddressHp = (__int64)HpPtr;                         // AddressHp = 208

    int* AttPtr = &NewPlayer.Att;
    __int64 AddressAtt = (__int64)AttPtr;                       // AddressAtt = 216

    int* DefPtr = &NewPlayer.Def;
    __int64 AddressDef = (__int64)DefPtr;                       // AddressDef = 220

    short* SpeedPtr = &NewPlayer.Speed;
    __int64 AddressSpeed = (__int64)SpeedPtr;                   // AddressSpeed = 224

    char* SubNamePtr = &NewPlayer.SubName;
    __int64 AddressSubName = (__int64)SubNamePtr;               // AddressSubName = 226

    int* ArmorPtr = &NewPlayer.Armor;
    __int64 AddressArmor = (__int64)ArmorPtr;                   // AddressArmor = 228

/*
200    201    202    203    204    205    206    207    208    209    210    211    212    213    214    215    216    217    218    219    220    221    222    223    224    225    226    227    228
Name  |                                                  Hp                                                    |Att                        |Def                       |Speed        |SubN  |       Armor
*/
    
    int a = 0;
}