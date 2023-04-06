#include "GameScreen.h"
#include "GameObject.h"

void GameObject::Render()
{
	if (true == UpdateValue)
	{
		GameScreen::GetMainScreen().ScreenRenderAnything(Pos, Ch);
	}
	return;
}