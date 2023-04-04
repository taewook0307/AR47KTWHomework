#include <iostream>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
    Player NewPlayer;
    NewPlayer.SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

    Bullet::BulletAllOff();
    NewPlayer.SetBulletPtr(Bullet::GetArrBullet());

    while (true)
    {
        system("cls");

        ConsoleGameScreen::GetMainScreen().Clear();

        ConsoleGameScreen::GetMainScreen().ScreenRenderSomething(NewPlayer.GetPos(), NewPlayer.GetCh());

        Bullet::BulletAllRender();

        ConsoleGameScreen::GetMainScreen().Render();

        NewPlayer.Input();

        Bullet::BulletAllUpdate();
    }
}

