#pragma once
#include "Position.h"

class Screen
{
public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;
	static const char Floor = 'a';

	static Screen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	Screen();

	static Screen MainScreen;
};