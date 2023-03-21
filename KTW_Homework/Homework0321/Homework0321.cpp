#include <iostream>
#include <conio.h>

void StatusRender(const char* const _Name, const int& _Att, const int& _Hp)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

void Damage(const char* const _AttName, const char* const _DefName, const int& _Att, const int& _AttHp, const int& _DefAtt, int& _DefHp)
{
    _DefHp -= _Att;
    if (_AttName == "Player")
    {
        system("cls");

        StatusRender(_AttName, _Att, _AttHp);
        StatusRender(_DefName, _DefAtt, _DefHp);
        printf_s("%s가 공격을 시작합니다\n", _AttName);
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
    }

    else if (_AttName == "Monster")
    {
        system("cls");

        StatusRender(_DefName, _DefAtt, _DefHp);
        StatusRender(_AttName, _Att, _AttHp);
        printf_s("%s가 공격을 시작합니다\n", _DefName);
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _AttName, _DefAtt);
        printf_s("%s가 공격을 시작합니다\n", _AttName);
        printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
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
