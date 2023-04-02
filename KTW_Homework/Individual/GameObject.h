#pragma once

#include "Position.h"

class GameObject
{
public:
	// 좌표 세팅 함수
	void SetPos(Position _Pos)
	{
		Pos = _Pos;
	}

	// 좌표 가져오는 함수
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

