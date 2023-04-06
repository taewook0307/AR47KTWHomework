#include "GameScreen.h"
#include "Bullet.h"
#include "ShootingGame.h"

void Bullet::Render()
{
	if (true == UpdateValue)
	{
		GameScreen::GetMainScreen().ScreenRenderAnything(Pos, Ch);
	}
	return;
}