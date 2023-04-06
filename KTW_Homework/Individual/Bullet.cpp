#include "GameScreen.h"
#include "Bullet.h"

void Bullet::PosUpdate()
{
	if (false == GameScreen::GetMainScreen().ScreenOver(Pos))
	{
		--Pos.Y;
	}
	return;
}