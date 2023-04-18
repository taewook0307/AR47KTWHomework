#pragma once
#include <vector>
#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	int2 GetScreenSize();

	void SetScreenSize(int2 _Size);

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, wchar_t _Ch);

protected:

private:
	std::vector<std::vector<wchar_t>> ArrScreen;

	int2 Size;

	ConsoleGameScreen();
	~ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};