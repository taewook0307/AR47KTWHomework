class Player
{
    // private: 디폴트 접근제한 지정자가 private
    int Att = 10;
    int Def = 5;
    int Hp = 100;
    int Speed = 3;
};

// 구조체는 디폴트 접근제한 지정자가 public이란걸 제외하고 class와 완전 동일
struct Monster
{
    // public: 디폴트 접근제한 지정자가 public
    int Att = 10;
    int Def = 5;
    int Hp = 100;
    int Speed = 3;
};

/*  밑에 코드는 위에 class Player와 동일
struct Player
{
private:
    int Att = 10;
    int Def = 5;
    int Hp = 100;
    int Speed = 3;
};
*/

int main()
{
    Player newPlayer = Player();
    Monster newMonster = Monster();
}