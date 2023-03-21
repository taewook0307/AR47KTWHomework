#include <iostream>
#include <conio.h>

void StatusRender(
    const char* const _Name,    // 이름
    const int& _Att,            // 공격력
    const int& _Hp              // 체력
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

void Damage(
    const char* const _AttName,     // 공격자의 이름
    const char* const _DefName,     // 방어자의 이름
    const int& _Att,                // 공격자의 공격력
    const int& _AttHp,              // 공격자의 체력
    const int& _DefAtt,             // 방어자의 공격력
    int& _DefHp                     // 방어자의 체력
)
{
    _DefHp -= _Att;                 // 방어자의 체력깎기

    if (_AttName == "Player")
    {
        system("cls");              // 콘솔창 지움

        StatusRender(_AttName, _Att, _AttHp);                               // Player의 스테이터스 출력
        StatusRender(_DefName, _DefAtt, _DefHp);                            // Monster의 스테이터스 출력
        printf_s("%s가 공격을 시작합니다\n", _AttName);                     // Player의 행동 출력
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);       // Monster의 피해상황 출력
    }

    else if (_AttName == "Monster")
    {
        system("cls");              // 콘솔창 지움

        StatusRender(_DefName, _DefAtt, _DefHp);                            // Player의 스테이터스 출력
        StatusRender(_AttName, _Att, _AttHp);                               // Monster의 스테이터스 출력
        printf_s("%s가 공격을 시작합니다\n", _DefName);                     // Player의 행동 출력
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _AttName, _DefAtt);    // Monster의 피해상황 출력
        printf_s("%s가 공격을 시작합니다\n", _AttName);                     // Monster의 행동 출력
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);       // Player의 피해상황 출력
    }
}

int main()
{
    int PlayerAtt = 10;
    int PlayerHp = 100;

    int MonsterAtt = 10;
    int MonsterHp = 100;

    while (true)
    {
        system("cls");

        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        _getch();

        Damage("Player", "Monster", PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
        _getch();

        if (0 >= MonsterHp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        Damage("Monster", "Player", MonsterAtt, MonsterHp, PlayerAtt, PlayerHp);
        _getch();

        if (0 >= PlayerHp)
        {
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
