#include "GameScreen.h"
#include "Bullet.h"

void Bullet::Render()
{
	if (true == UpdateValue)
	{
		GameScreen::GetMainScreen().ScreenRenderAnything(Pos, Ch);
	}
	return;
}