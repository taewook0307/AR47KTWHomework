#pragma once

#include <GameEngineConsole/GameEngineArray.h>

#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	int2 GetScreenSize()
	{
		return Size;
	}

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	// GameEngineArray<char>* ArrScreen
	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};