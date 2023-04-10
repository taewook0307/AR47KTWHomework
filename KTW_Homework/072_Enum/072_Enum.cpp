#include <iostream>

// 컴파일 시 enum은 int로 변형
enum GameJobTypeEnum
{
    Fighter = 5,    // 5
    Magician,       // 6
    Archer,         // 7
    Paladin,        // 8
    Anything        // 9
};

// enum class는 int로의 암시적 형변환이 불가능
// 생략하고 사용하기 불가능 
enum class GameJobType
{
    Fighter,  // 0
    Magician,   // 1
    Archer,     // 2
    Paladin     // 3
};


class FightUnit
{
private:
    GameJobType JobType;

public:
    void SetJobType(GameJobType _Type)
    {
        JobType = _Type;
    }

    void Test(GameJobTypeEnum _Type)
    {
        printf_s("%d", _Type);
    }
};

int main()
{
    FightUnit NewUnit;

    NewUnit.Test(Anything);                     // enum은 생략해서 사용 가능

    NewUnit.SetJobType(GameJobType::Archer);    // enum class는 생략해서 사용 불가능

    int Value = GameJobTypeEnum::Archer;        // enum은 암시적 형변환이 가능

    int Value1 = (int)GameJobType::Archer;      // enum class는 암시적 형변환이 불가능 하기에 반드시 형변환을 따로 해줘야 함.
}