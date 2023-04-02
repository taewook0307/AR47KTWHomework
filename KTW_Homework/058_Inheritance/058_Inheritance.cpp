#include <iostream>

// 객체 지향 언어

// 캡슐화
// 클래스가 특정 기믹을 내부에 품고 있는 것
// 캡슐화를 지원하는 문법 : 접근제한 지정자

// 상속
// 특정 개념의 특성들을 하위 개념들이 물려받는 것
// Is a 관계

// 기본 클래스
class Item
{
//           내부 코드        자식 코드       외부 코드
// public      공개              공개            공개 
// protected   공개              공개           비공개
// private     공개             비공개          비공개

public:
    int Gold = 0;
protected:
    void Buy()
    {

    }
private:
    void Sell()
    {

    }
};

// public Item 상속을 의미
// Weapon class는 Item 클래스를 상속받음
class Weapon : public Item
{
// 각각의 자료형을 비교 => 공개 범위가 적은 접근제한 연산자를 남김
// public:  비교 public    : public       =>  전부 사용 가능
//     int Gold = 0;
// protected:  비교 public : protected    =>  protected 이므로 자신과 자신을 상속받은 클래스에서 사용 가능
//     void Buy()
//     {
// 
//     }
// private:                               =>  private 이므로 상속 불가능
//     void Sell()
//     {
// 
//     }
public:
    Weapon()
    {
        Buy();

        Gold = 20;
    }
};

class Postion : protected Item
{
// public:  비교 protected    : protected
//     int Gold = 0;
// protected:  비교 protected : protected
//     void Buy()
//     {
// 
//     }
// private:             => 상속 불가
//     void Sell()
//     {
// 
//     }
public:
    Postion()
    {
        Gold = 20;
    }
};

class Armor : private Item
{
// public:  비교 private    : private
//     int Gold = 0;
// protected:  비교 private : private
//     void Buy()
//     {
// 
//     }
// private:             => 상속 불가
//     void Sell()
//     {
// 
//     }
public:
    Armor()
    {
        Gold = 15; 
    }
};

int main()
{
     
}