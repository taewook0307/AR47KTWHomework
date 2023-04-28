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

	void Function(DataType _Data)	// ���ø��� �̿��ϸ� �Լ��� ������� �����ؾ� ��
	{
		DataType type = _Data;
		 
		std::cout << _Data << std::endl;
	}

protected:

private:

};

