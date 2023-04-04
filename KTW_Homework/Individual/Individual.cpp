#include <iostream>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
    Player NewPlayer = Player();

    NewPlayer.SetBulletPtr(Bullet::GetArrBullet());

    NewPlayer.SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

    Bullet::BulletAllOff();

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

