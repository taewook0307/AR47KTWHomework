#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();

	int GetDir() const
	{
		return Dir;
	}

	void SetDir()
	{
		if (Dir != 1 && Dir != -1)
		{
			return;
		}
		else
		{
			Dir *= -1;
		}
	}

private:

	int Dir = 1;
};

