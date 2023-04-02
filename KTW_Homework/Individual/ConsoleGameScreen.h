#pragma once
class Position;

class ConsoleGameScreen
{
public:
	static const int ScreenXSize = 21;
	static const int ScreenYSize = 11;
	const char Floor = 'a';

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static Position GetScreenSize();

	void ScreenRenderSomething(const Position& _Pos, char _Ch);

	void ScreenClear();

	void ScreenRender() const;

	bool IsScreenOver(Position& _Pos);
protected:

private:
	static ConsoleGameScreen MainScreen;

	ConsoleGameScreen();

	char ArrScreen[ScreenYSize][ScreenXSize] = {};
};

