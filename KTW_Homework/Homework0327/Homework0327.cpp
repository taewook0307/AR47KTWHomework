#include <iostream>
#include <conio.h>
#include <Windows.h>

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};
 
class ConsoleGameScreen
{
public:
	static const int ScreenYSize = 3;
	static const int ScreenXSize = 3;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}


	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint() const
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	bool IsScreenOver(const int2& _Pos) const
	{
		if (0 > _Pos.X)
		{
			return true;
		}

		if (0 > _Pos.Y)
		{
			return true;
		}

		if (ScreenXSize <= _Pos.X)
		{
			return true;
		}

		if (ScreenYSize <= _Pos.Y)
		{
			return true;
		}

		return false;
	}

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		if (true == IsScreenOver(_Pos))
		{
			return;
		}

		Arr[_Pos.Y][_Pos.X] = _Ch;
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
};



class Player
{
public:
	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	void Input(const ConsoleGameScreen& NewConsoleGameScreen)
	{
		if (0 == _kbhit())
		{
			Sleep(InterFrame);
			return;
		}

		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
		{
			int2 NextPos = Pos;
			NextPos.X -= 1;
			if (NewConsoleGameScreen.IsScreenOver(NextPos) == false)
			{
				Pos.X -= 1;
			}
			break;
		}
		case 'd':
		case 'D':
			if (NewConsoleGameScreen.IsScreenOver({ Pos.X + 1, Pos.Y }))
			{
				break;
			}
			else
			{
				Pos.X += 1;
				break;
			}
		case 'w':
		case 'W':
			if (NewConsoleGameScreen.IsScreenOver({ Pos.X, Pos.Y - 1 }))
			{
				break;
			}
			else
			{
				Pos.Y -= 1;
				break;
			}
		case 's':
		case 'S':
			if (NewConsoleGameScreen.IsScreenOver({ Pos.X, Pos.Y + 1 }))
			{
				break;
			}
			else
			{
				Pos.Y += 1;
				break;
			}
		default:
			break;
		}

		Sleep(InterFrame);
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	ConsoleGameScreen NewConsoleGameScreen;
};


int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*');

		NewScreen.ScreenPrint();

		NewPlayer.Input(NewScreen);
	}
}