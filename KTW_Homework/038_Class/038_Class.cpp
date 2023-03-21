#include <iostream>
#include <conio.h>

// c++ => c를 기반 문법으로 해서
// + 객체지향을 추가한 언어
// + 다른 언어에서 좋다고 칭찬받은 문법들을 마구잡이로 흡수

void StatusRender(const char* const _Name, const int& _Att, const int& _Hp)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

void Damage(const char* const _AttName, const char* const _DefName, const int& _Att, int& _Hp)
{
    printf_s("%s가 공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
    _Hp -= _Att;
}

int main()
{
    // 초기형 프로그래밍인 절차지향은 데이터가 기반
    // 객체라는 개념이 없음
    // 어떠한 함수를 만들면 해당 함수를 여러개가 돌려쓸 수 있게 개발

    int PlayerHp = 100;
    int PlayerAtt = 10;

    int MonsterHp = 100;
    int MonsterAtt = 10;

    while (true)
    {
        system("cls");
        // 추후설명
        // 콘솔 화면에 모든 글자를 지웁니다.

        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        _getch();

        Damage("Player", "Monster", PlayerAtt, MonsterHp);
        _getch();

        if (0 >= MonsterHp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        Damage("Monster", "Player", MonsterAtt, PlayerHp);
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