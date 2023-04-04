#include <iostream>

class FightUnit
{
public:
	// 각자 자식형일때는 자식들의 방식으로 동작하게 도와주는 문법이 필요
	// virtual : 가상함수 문법
	// 가상함수가 만들어지게 되면
	// 자식이 이걸 새롭게 정의하지 않으면 부모형으로 동작하고
	// 자식이 새롭게 정의하면 자식의 형으로 동작
	// 정의하는 방식은 부모와 완전히 동일
	virtual int GetAtt()
	{
		return Att;
	}

private:
	int Att = 10;
	int Hp = 100;
};

class Player : public FightUnit
{
public:
	// 오버라이드 문법
	// override 했드는 것을 명시적으로 함수 뒤에 표현 => 안 해도 동작은 함.(명시적으로 표현해주기 위해)
	int GetAtt() override
	{
		return FightUnit::GetAtt() + Lv + Equip;
	}


private:
	int Lv = 1;
	int Equip = 1; // 장비
};

class Monster : public FightUnit
{

};

// 업캐스팅을 이용한 함수
void Fight(FightUnit* _Left, FightUnit* _Right)
{
	// 다운캐스팅 => 최악의 방법(안전하지 않음)
	//  : 부모형을 자식형으로 바꾸는 것 => 강제 캐스팅
	Player* PlyaerPtr = (Player*)_Left;
	// _Left 에 Player가 들어오면 생각한대로 동작
	// _Left 에 Player말고 다른게 들어올 경우 무슨 일이 벌어질지 알 수 없음
	// 다운캐스팅을 사용할 경우 조건이 필요 => 이 경우에는 _Left에 무조건 Player가 들어와야 함
}

int main()
{
	Player NewPlayer;

	Player* PlayerPtr = &NewPlayer;

	// 업캐스팅
	// 자식형을 부모형으로 바꾸는 것
	//  : 메모리에 자식형은 부모형을 포함하고 있기 때문에
	FightUnit* Ptr = PlayerPtr;
}