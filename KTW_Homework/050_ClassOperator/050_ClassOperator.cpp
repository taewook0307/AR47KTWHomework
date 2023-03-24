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
	int operator+(const int _Value)
	{
		return Value + _Value;
	}

	Number& operator+=(const int _Value)
	{
		Value = Value + _Value;
		return *this;
	}

	Number& operator++()
	{
		++Value;
		return *this;
	}

	// 후위의 경우 인자를 넣어주지만 사용할 수는 없음 => 예외
	int operator++(int)
	{
		int nResult = Value;
		Value += 1;
		return nResult;
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

		// unamed memory
		// (Value + 10) = 10;

		// 문법적으로 unamed memory에는 메모리 값을 수정할 수 없고 사용만 가능

		(Value += 10) = 10;

		// Value++ = 10;		<= unnamed memory를 리턴하므로 수정 불가능
		// ++Value = 10;		<= 자기 자신이 return 되기 때문에 수정 가능, 단 가독성이 떨어지므로 사용 자제
	}
}
