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
		if (Dir == 1)
		{
			Dir = -1;
		}
		else if (Dir == -1)
		{
			Dir = 1;
		}
		else
		{
			return;
		}
	}

private:

	int Dir = 1;
};

