#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet()
	{
		Ch = '^';
	}
	void PosUpdate();

private:
};

