#pragma once

template<typename DataType>
class Temp
{
public:
	// constrcuter destructer
	Temp();
	~Temp();

	// delete Function
	Temp(const Temp& _Other) = delete;
	Temp(Temp&& _Other) noexcept = delete;
	Temp& operator=(const Temp& _Other) = delete;
	Temp& operator=(Temp&& _Other) noexcept = delete;

	void Function(DataType _Data)	// 템플릿을 이용하면 함수는 헤더에서 정의해야 함
	{
		DataType type = _Data;
		 
		std::cout << _Data << std::endl;
	}

protected:

private:

};

