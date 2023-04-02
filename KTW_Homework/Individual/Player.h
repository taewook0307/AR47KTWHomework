#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	// 생성자
	Player()
	{
		RenderChar = '*';
	}

	// 플레이어 모양을 가져오기 위한 함수
	char GetRenderChar() const
	{
		return RenderChar;
	}

	// 플레이어 작동에 관한 함수
	void Input();
protected:

private:
};

