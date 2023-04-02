#pragma once

#include "Position.h"

class GameObject
{
public:
	// ��ǥ ���� �Լ�
	void SetPos(Position _Pos)
	{
		Pos = _Pos;
	}

	// ��ǥ �������� �Լ�
	Position GetPos() const
	{
		return Pos;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	bool IsUpdate() const
	{
		return UpdateValue;
	}

protected:
	Position Pos;
	char RenderChar = ' ';

private:
	bool UpdateValue = true;
	bool DeleteValue = false;
};

