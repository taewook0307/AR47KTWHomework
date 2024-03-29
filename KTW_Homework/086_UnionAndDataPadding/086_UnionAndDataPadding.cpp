﻿#include <iostream>

//typedef union _LARGE_INTEGER {
//    struct {
//        DWORD LowPart;                  // DWORDD = unsigned long
//        LONG HighPart;                  // LONG = long
//    } DUMMYSTRUCTNAME;
//
//    // 구조체를 바로 변수화시키는 문법
//    struct {
//        DWORD LowPart;
//        LONG HighPart;
//    } u;
//    LONGLONG QuadPart;
//} LARGE_INTEGER;

class MyClass
{
public:
    int a;
    int b;
    __int64 c;
};

union MyUnion
{
public:
    int a;
    int b;
    __int64 c = 3;                          // 00000011 00000000 00000000 00000000 00000000 00000000 00000000 00000000
};                                          // Little endian으로 인해 a랑 b또한 3

class Test
{
public:
    // 맴버변수이면서 union의 메모리 구조를 가지게끔하는 문법
    union
    {
        int a;
        int b;
    };
};

/*
struct TestStruct
{
    int x;
    int y;
};
*/

union LastUnion
{
    struct
    {
        int x;
        int y;
    } ValueXY;

    // TestStruct ValueXY;

    __int64 z;
};

int main()
{
    // union은 내부의 메모리 주소값을 서로 공유
    // MyClass의 크기는 16byte
    {
        int Value = sizeof(MyClass);            // Value = 16;
        int ValueU = sizeof(MyUnion);           // ValueU = 8;

        MyClass NewClass;                       // NewClass의 주소가 200번지라 가정
        MyUnion NewUnion;                       // NewUnion의 주소가 300번지라 가정

        NewClass.a = 1;                         // Newclass.a는 200번지에서 204번지
        NewClass.b;                             // NewClass.b는 204번지에서 208번지
        NewClass.c;                             // NewClass.c는 208번지에서 216번지

        NewUnion.a;                             // NewUnion.a는 300번지에서 304번지
        NewUnion.b;                             // NewUnion.a는 300번지에서 304번지
        NewUnion.c;                             // NewUnion.a는 300번지에서 308번지
    }

    {
        int SizeTest = sizeof(Test);            // SizeTest = 4

        Test NewTest;

        NewTest.a = 1;
        NewTest.b;
    }

    {
        int Size = sizeof(LastUnion);           // Size = 8

        LastUnion NewLastUnion;

        NewLastUnion.ValueXY.x = 3;
        NewLastUnion.ValueXY.y;
        NewLastUnion.z;
    }
}