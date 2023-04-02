#include "ConsoleGameScreen.h"
#include "Bullet.h"

Bullet Bullet::ArrBullet[BulletCount] = {};

Bullet::Bullet()
{

}

void Bullet::AllSecting()
{
	ArrBullet[0].RenderChar = '^';
	ArrBullet[0].SetPos({ 0,0 });
}

void Bullet::AllRender()
{
	ConsoleGameScreen::GetMainScreen().ScreenRenderSomething(ArrBullet[0].GetPos(), ArrBullet[0].RenderChar);
}