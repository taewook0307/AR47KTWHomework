#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	// ������
	Player()
	{
		RenderChar = '*';
	}

	// �÷��̾� ����� �������� ���� �Լ�
	char GetRenderChar() const
	{
		return RenderChar;
	}

	// �÷��̾� �۵��� ���� �Լ�
	void Input();
protected:

private:
};

