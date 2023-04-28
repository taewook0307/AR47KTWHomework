#include "Player.h"
#include "BaseHeader.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Damage(int _Damage)
{
	if (0 == _Damage)
	{
		// MessageBoxA(nullptr, "데미지가 0입니다", "Error", MB_OK); assert(false);
		MsgBoxAssert("데미지가 0입니다");
	}
}