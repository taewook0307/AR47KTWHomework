#include <iostream>

class Number
{
private:
	int Value;

public:
	Number(int _Value)
		: Value(_Value)
	{
	}

// 대입 연산자
	void operator=(int _Value)
	{
		Value = _Value;
	}


// 산술 연산자

	// 더하기
	int operator+(int _Value)
	{
		return Value + _Value;
	}

	// 빼기
	int operator-(int _Value)
	{
		return Value - _Value;
	}

	// 곱하기
	int operator*(int _Value)
	{
		return Value * _Value;
	}

	// 나누기
	int operator/(int _Value)
	{
		return Value / _Value;
	}

	// 나머지
	int operator%(int _Value)
	{
		return Value % _Value;
	}


// 전위 증감 연산자
	int operator++()
	{
		return ++Value;
	}

	int operator--()
	{
		return --Value;
	}


// 비교 연산자 / 관계 연산자
	bool operator==(int _Value)
	{
		return Value == _Value;
	}

	bool operator!=(int _Value)
	{
		return Value != _Value;
	}

	bool operator>=(int _Value)
	{
		return Value >= _Value;
	}

	bool operator<=(int _Value)
	{
		return Value <= _Value;
	}

	bool operator>(int _Value)
	{
		return Value > _Value;
	}

	bool operator<(int _Value)
	{
		return Value < _Value;
	}


// 논리 연산자

	// and
	bool operator&&(bool _Value)
	{
		return Value && _Value;
	}

	// or
	bool operator||(bool _Value)
	{
		return Value || _Value;
	}


// 비트 단위 연산자

	// and
	int operator&(int _Value)
	{
		return Value & _Value;
	}

	// or
	int operator|(int _Value)
	{
		return Value | _Value;
	}

	// not
	int operator~()
	{
		return ~Value;
	}

	// xor
	int operator^(int _Value)
	{
		return Value ^ _Value;
	}

	// Shift
	int operator<<(int _Value)
	{
		return Value << _Value;
	}

	int operator>>(int _Value)
	{
		return Value >> _Value;
	}


// 복합 대입 연산자
	
	// 더하기
	void operator+=(int _Value)
	{
		Value = Value + _Value;
	}

	// 빼기
	void operator-=(int _Value)
	{
		Value = Value - _Value;
	}

	// 곱하기
	void operator*=(int _Value)
	{
		Value = Value * _Value;
	}

	// 나누기
	void operator/=(int _Value)
	{
		Value = Value / _Value;
	}

	// 나머지
	void operator%=(int _Value)
	{
		Value = Value % _Value;
	}

	// 비트 and
	void operator&=(int _Value)
	{
		Value = Value & _Value;
	}

	// 비트 or
	void operator|=(int _Value)
	{
		Value = Value | _Value;
	}

	// 비트 xor
	void operator^=(int _Value)
	{
		Value = Value ^ _Value;
	}

	// shift
	void operator<<= (int _Value)
	{
		Value = Value << _Value;
	}

	void operator>>= (int _Value)
	{
		Value = Value >> _Value;
	}
};

int main()
{
	int Result = 0;

	Number NewNumber = Number(10);

	NewNumber = 5;							// NewNumber.Value = 5
	NewNumber.operator=(10);				// NewNumber.Value = 10

	Result = NewNumber + 10;				// Result = 20
	Result = NewNumber.operator+(3);		// Result = 13

	Result = NewNumber - 10;				// Result = 0
	Result = NewNumber.operator-(3);		// Result = 7

	Result = NewNumber * 10;				// Result = 100
	Result = NewNumber.operator*(3);		// Result = 30

	Result = NewNumber / 10;				// Result = 1
	Result = NewNumber.operator/(3);		// Result = 3

	Result = NewNumber % 3;					// Result = 1
	Result = NewNumber.operator%(2);		// Result = 0


	Result = ++NewNumber;					// Result = 11, NewNumber.Value = 11
	Result = NewNumber.operator++();		// Result = 12, NewNumber.Value = 12

	Result = --NewNumber;					// Result = 11, NewNumber.Value = 11
	Result = NewNumber.operator--();		// Result = 10, NewNumber.Value = 10


	bool bResult = true;

	bResult = NewNumber == 0;				// bResult = false;
	bResult = NewNumber.operator==(0);		// bResult = false;

	bResult = NewNumber != 0;				// bResult = true;
	bResult = NewNumber.operator!=(0);		// bResult = true;

	bResult = NewNumber >= 0;				// bResult = true;
	bResult = NewNumber.operator>=(0);		// bResult = true;

	bResult = NewNumber <= 0;				// bResult = false;
	bResult = NewNumber.operator<=(0);		// bResult = false;

	bResult = NewNumber > 0;				// bResult = true;
	bResult = NewNumber.operator>(0);		// bResult = true;

	bResult = NewNumber < 0;				// bResult = false;
	bResult = NewNumber.operator<(0);		// bResult = false;


	bResult = NewNumber && true;			// bResult = true;
	bResult = NewNumber.operator&&(true);	// bResult = true;

	bResult = NewNumber && false;			// bResult = false;
	bResult = NewNumber.operator&&(false);	// bResult = false;

	bResult = NewNumber || true;			// bResult = true;
	bResult = NewNumber.operator||(true);	// bResult = true;
	NewNumber = false;							// NewNumber.Value = 0
	bResult = NewNumber || true;			// bResult = true;
	bResult = NewNumber.operator||(true);	// bResult = true;
	bResult = NewNumber || false;			// bResult = false;
	bResult = NewNumber.operator||(false);	// bResult = false;


	NewNumber = 5;							// NewNumber.Value = 5
	Result = NewNumber & 3;
	Result = NewNumber.operator&(3);
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	3               = 0b00000000000000000000000000000011
	Result          = 0b00000000000000000000000000000001			Result = 1
	*/
	Result = NewNumber | 3;
	Result = NewNumber.operator|(3);
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	3               = 0b00000000000000000000000000000011
	Result          = 0b00000000000000000000000000000111			Result = 7
	*/
	Result = ~NewNumber;
	Result = NewNumber.operator~();
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	Result          = 0b11111111111111111111111111111010			Result = -6
	*/
	Result = NewNumber ^ 3;
	Result = NewNumber.operator^(3);
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	3               = 0b00000000000000000000000000000011
	Result          = 0b00000000000000000000000000000110			Result = 6
	*/
	Result = NewNumber << 3;
	Result = NewNumber.operator<<(3);
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	Result          = 0b00000000000000000000000000101000			Result = 40
	*/

	NewNumber = 16;							// NewNumber.Value = 16
	Result = NewNumber >> 3;
	Result = NewNumber.operator>>(3);
	/*
	NewNumber.Value = 0b00000000000000000000000000010000
	Result          = 0b00000000000000000000000000000010			Result = 2
	*/


	NewNumber += 10;						// NewNumber.Value = 26
	NewNumber.operator+=(10);				// NewNumber.Value = 36

	NewNumber -= 10;						// NewNumber.Value = 26
	NewNumber.operator-=(10);				// NewNumber.Value = 16

	NewNumber *= 10;						// NewNumber.Value = 160
	NewNumber.operator*=(10);				// NewNumber.Value = 1600

	NewNumber /= 10;						// NewNumber.Value = 160
	NewNumber.operator/=(10);				// NewNumber.Value = 16

	NewNumber %= 3;							// NewNumber.Value = 1
	NewNumber.operator%=(3);				// NewNumber.Value = 1


	NewNumber &= 2;
	/*
	NewNumber.Value = 0b00000000000000000000000000000001
	2               = 0b00000000000000000000000000000010
	NewNumber.Value = 0b00000000000000000000000000000000			NewNumber.Value = 0
	*/
	NewNumber.operator&=(2); 
	/*
	NewNumber.Value = 0b00000000000000000000000000000000
	2               = 0b00000000000000000000000000000010
	NewNumber.Value = 0b00000000000000000000000000000000			NewNumber.Value = 0
	*/

	NewNumber |= 2;
	/*
	NewNumber.Value = 0b00000000000000000000000000000000
	2               = 0b00000000000000000000000000000010
	NewNumber.Value = 0b00000000000000000000000000000010			NewNumber.Value = 2
	*/
	NewNumber.operator|=(2);
	/*
	NewNumber.Value = 0b00000000000000000000000000000010
	2               = 0b00000000000000000000000000000010
	NewNumber.Value = 0b00000000000000000000000000000010			NewNumber.Value = 2
	*/

	NewNumber ^= 7;
	/*
	NewNumber.Value = 0b00000000000000000000000000000010
	7               = 0b00000000000000000000000000000111
	NewNumber.Value = 0b00000000000000000000000000000101			NewNumber.Value = 5
	*/
	NewNumber.operator^=(2);
	/*
	NewNumber.Value = 0b00000000000000000000000000000101
	2               = 0b00000000000000000000000000000010
	NewNumber.Value = 0b00000000000000000000000000000111			NewNumber.Value = 7
	*/

	NewNumber <<= 2;
	/*
	NewNumber.Value = 0b00000000000000000000000000000111
	NewNumber.Value = 0b00000000000000000000000000011100			NewNumber.Value = 28
	*/
	NewNumber.operator<<=(2);
	/*
	NewNumber.Value = 0b00000000000000000000000000011100
	NewNumber.Value = 0b00000000000000000000000001110000			NewNumber.Value = 112
	*/

	NewNumber >>= 2;
	/*
	NewNumber.Value = 0b00000000000000000000000001110000
	NewNumber.Value = 0b00000000000000000000000000011100			NewNumber.Value = 28
	*/
	NewNumber.operator>>=(2);
	/*
	NewNumber.Value = 0b00000000000000000000000000011100
	NewNumber.Value = 0b00000000000000000000000000000111			NewNumber.Value = 7
	*/

	int a = 0;
}
