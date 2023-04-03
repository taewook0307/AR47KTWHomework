#pragma once

#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
    static const int ScreenXSize = 3;
    static const int ScreenYSize = 3;
    static const char Floor = 'a';

    static ConsoleGameScreen& GetMainScreen();

    int2 GetScreenSize()
    {
        return { ScreenXSize, ScreenYSize };
    }

    void Clear();

    void Render();

    void ScreenRenderSomething(int2 _Pos, char _Ch);

    bool IsScreenOver(int2 _Pos);

protected:

private:
    char ArrScreen[ScreenYSize][ScreenXSize] = {};

    static ConsoleGameScreen MainScreen;

    ConsoleGameScreen();
};

