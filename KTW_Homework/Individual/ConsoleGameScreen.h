#pragma once

#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
    static const int ScreenXSize = 5;
    static const int ScreenYSize = 5;
    static const char Floor = 'a';

    int2 GetScreenSize()
    {
        return { ScreenXSize, ScreenYSize };
    }

    static ConsoleGameScreen& GetMainScreen();

    void Clear();

    void Render() const;

    void ScreenRenderSomething(int2 _Pos, char _Ch);

    bool IsScreenOver(int2 _Pos);

protected:

private:
    char ArrScreen[ScreenYSize][ScreenXSize] = {};

    static ConsoleGameScreen MainScreen;

    ConsoleGameScreen();
};


