#include <iostream>

// Template 문법
// 특정 함수나 특정 클래스에서 자료형만 바뀐 완전히 동일한 함수나 완전히 동일한 클래스를 만들고 싶을 때 사용하는 문법
template<typename DataType>
void Function(DataType _Value)
{
    printf_s("%d\n", _Value);
}

// Template 특수화 문법
// 템플릿 문법을 이용한 함수가 있는데 특정 자료형에서는 따로 동작하게 해주는 문법
template<>
void Function(char _Value)
{
    printf_s("%c\n", _Value);
}

// Template 클래스
template<typename DataType>
class Test
{
public:
    DataType Value;
};

class Bullet
{
public:
    void Update()
    {

    }
};

int main()
{
    // 템플릿 함수의 경우
    {
        Function<int>(10);
        Function<short>(5);
        Function<char>('a');

        // 인자추론
        // 함수 템플릿 호출 시 타입이 명시적이지 않아도 주어진 함수 인자에 기반해 템플릿 파라미터를 결정하는 것
        Function(10);   // <int> 생략
    }

    // 템플릿 클래스의 경우
    {
        Test<int> NewTestInt;
        NewTestInt.Value = 20;

        Test<char> NewTestChar;
        NewTestChar.Value = 'a';

        Test<Bullet> NewTestBullet;
        NewTestBullet.Value.Update();

        // 템플릿 클래스는 인자추론이 불가능
        // 이유 : main함수는 실행 시 필요한 메모리크기가 정해져 있는데 클래스에 경우 크기를 모르기 때문에

        // NewTestInt = NewTestBullet; => 불가능 : 둘의 클래스가 전혀 다르기 때문에
    }
}