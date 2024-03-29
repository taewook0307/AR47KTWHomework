﻿#include <iostream>

// virtual이 붙어 있는 클래스가 존재하고 이 클래스의 객체가 생성될 때
// 함수포인터의 배열을 만들어내고 그걸 함수포인터의 포인터로 저장
// void(*__vfptr[???])() <= 가상함수 테이블 : 함수포인터의 배열
// void(**__vfptr)() : 함수포인터의 포인터

// 부모 class에서는 자신의 가상 함수를 함수포인터로 넣어놓고
// 자식 class에서는 오버라이드하면 자신의 것으로 바꾸고 오버라이드 하지 않으면 부모의 것을 그대로 가지고 있음 

class FightUnit
{
public:
    virtual void Damage()
    {

    }

    virtual void FightStatusRender()
    {

    }

public:
    FightUnit()
        // [0]FightUnit::Damage
        // [1]FightUnit::FightStatusRender
    {
        this;
        int a = 0;
    }
};

class Player : public FightUnit
{
public:
    void Damage() override
    {

    }

    //void FightStatusRender() override
    //{

    //}

public:
    Player()
        // [0]Player::Damage
        // [1]FightUnit::FightStatusRender
    {
        this;
        int a = 0;
    }
};

class Fighter : public Player
{
// public:
    // Fighter() {
        // [0]Player::Damage
        // [1]FightUnit::FightStatusRender
    // }

};

int main()
{
    std::cout << "Hello World!\n";
}