#include <iostream>

class Player
{
    // 속성이나 행동은
    // 내가 외부에 공개할지 안 할지를 결정

    // 접근 제한 지정자
    // 접근제한 지정자는 만들어진 위치부터 아래까지 새로운 접근제한 지정자가 없으면
    // 전부 다 자신의 접근제한 지정자로 판단한다.

/*
                내부 코드               자식 코드               외부 코드
public            공개                    공개                     공개
protected         공개                    공개                    비공개
private           공개                   비공개                   비공개
*/

public:
    int Att = 10;   // public
    int Def = 5;    // public
protected:
    int Hp = 100;   // protected
private:
    int Speed = 3;  // private
};
// 클래스의 시작과 끝 사이가 아니면 외부 코드

class Monster
{
    // 내부 코드
//private:          디폴트 접근 제한 지정자
    int Att = 10;
    int Def = 5;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    // 외부 코드
    Player newPlayer = Player();
}