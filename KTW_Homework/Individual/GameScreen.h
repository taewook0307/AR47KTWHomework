#pragma once

#include "Position.h"

class GameScreen
{
public:
	static const int ScreenXSize = 5;
	static const int ScreenYSize = 5;
	static const char Floor = 'L';

	inline static GameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	inline Position GetScreenSize() const
	{
		return Position{ ScreenXSize, ScreenYSize };
	}

	void ScreenSetting();

	void ScreenPrint();

	bool ScreenOver(Position _Pos);

	void ScreenRenderAnything(Position _Pos, char _Ch);
protected:

private:
	static GameScreen MainScreen;

	GameScreen();

	char Screen[ScreenYSize][ScreenXSize] = {};

};

