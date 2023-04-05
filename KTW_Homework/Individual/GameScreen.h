#pragma once

#include "Location.h"

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

	inline Location GetScreenSize() const
	{
		return Location{ ScreenXSize, ScreenYSize };
	}

	void ScreenSetting();

	void ScreenPrint();

	bool ScreenOver(Location _Pos);

	void ScreenRenderAnything(Location _Pos, char _Ch);
protected:

private:
	static GameScreen MainScreen;

	GameScreen();

	char Screen[ScreenYSize][ScreenXSize] = {};

};

