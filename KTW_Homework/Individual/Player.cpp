#include <conio.h>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

void Player::Input()
{
	char Ch = _getch();

	Position MovePos = Position();

	switch (Ch)
	{
	case 'a':
	case 'A':
		MovePos = { Pos.X - 1, Pos.Y };
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(MovePos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		MovePos = { Pos.X + 1, Pos.Y };
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(MovePos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		MovePos = { Pos.X, Pos.Y - 1 };
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(MovePos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		MovePos = { Pos.X, Pos.Y + 1 };
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(MovePos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		break;
	default:
		break;
	}
}