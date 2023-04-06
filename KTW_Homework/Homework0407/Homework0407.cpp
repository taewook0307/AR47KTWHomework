#include <iostream>

#include <GameEngineConsole/ConsoleGameScreen.h>

int main()
{
    ConsoleGameScreen::GetMainScreen().ScreenClear();

    ConsoleGameScreen::GetMainScreen().ScreenPrint();
}
