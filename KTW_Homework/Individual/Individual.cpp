#include <iostream>

#include "ConsoleGameScreen.h"
#include "Player.h"

int main()
{
    ConsoleGameScreen::GetMainScreen().Clear();
    ConsoleGameScreen::GetMainScreen().Render();

    Player NewPlayer;
    NewPlayer.SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

    while (true)
    {
        ConsoleGameScreen::GetMainScreen().Clear();

        ConsoleGameScreen::GetMainScreen().ScreenRenderSomething(NewPlayer.GetPos(), NewPlayer.GetCh());

        system("cls");

        ConsoleGameScreen::GetMainScreen().Render();

        NewPlayer.Input();
    }

    int a = 0;
}

