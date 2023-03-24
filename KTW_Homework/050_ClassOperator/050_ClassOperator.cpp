#include <iostream>

class Number
{
private:
	int Value;

public:
	// 맴버 이니셜라이저.
	Number(int _Value)
		: Value(_Value)
	{

	}

	// operator : 클래스가 연산자를 사용할수 있게 만들어주는 것.
	int operator+(int _Value)
	{
		return Value + _Value;
	}
};

int main()
{
    {
        int Value = 10;
		Value + 10;
    }

	{
		Number Value = 10;

		// 연산자 겹지정 함수
		Value + 10;
		Value.operator+(10);
	}
}
