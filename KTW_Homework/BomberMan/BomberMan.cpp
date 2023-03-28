#include <iostream>
#include <conio.h>
#include <Windows.h>
// 숙제0 : 전방향 다 움직이게 만들기
// 숙제1 : 잔상 지우기
// 숙제2 : 화면 밖으로 못 나가게 하기

// 안해도 되는 숙제
// 숙제3 : 장애물 만들고 배치하기
// 숙제4 : f를 누르면 폭탄이 설치되고 눈에 보여야 함.
// 숙제5 : 일정시간이 지나고 폭탄이 터지기

const int ScreenXSize = 3;
const int ScreenYSize = 3;

const char Floor = 'a';

char Arr[ScreenYSize][ScreenXSize] = {};

int PlayerX = ScreenXSize / 2;
int PlayerY = ScreenYSize / 2;

void ScreenPush() 
{
	for (int i = 0; i < ScreenYSize; i++)
	{
		for (int j = 0; j < ScreenXSize; j++)
		{
			Arr[i][j] = Floor;
		}
	}
}

void ScreenPrint()
{
	for (int i = 0; i < ScreenYSize; i++)
	{
		for (int j = 0; j < ScreenXSize; j++)
		{
			printf_s("%c", Arr[i][j]);
		}
		printf_s("\n");
	}
}

bool CheckOverScreen(int _X, int _Y)
{
	if (_X < 0)
	{
		return true;
	}

	if (_Y < 0)
	{
		return true;
	}

	if (_X >= ScreenXSize)
	{
		return true;
	}

	if (_Y >= ScreenYSize)
	{
		return true;
	}

	return false;
}

void PlayerMove()
{
	char Ch = _getch();

	switch (Ch)
	{
	case 'a':
	case 'A':
		if (CheckOverScreen(PlayerX - 1, PlayerY))
		{
			break;
		}
		else
		{
			PlayerX -= 1;
			break;
		}
	case 'd':
	case 'D':
		if (CheckOverScreen(PlayerX + 1, PlayerY))
		{
			break;
		}
		else
		{
			PlayerX += 1;
			break;
		}
	case 'w':
	case 'W':
		if (CheckOverScreen(PlayerX, PlayerY - 1))
		{
			break;
		}
		else
		{
			PlayerY -= 1;
			break;
		}
	case 's':
	case 'S':
		if (CheckOverScreen(PlayerX, PlayerY + 1))
		{
			break;
		}
		else
		{
			PlayerY += 1;
			break;
		}
	default:
		break;
	}
}

int main()
{
	ScreenPush();

	ScreenPrint();

	while (true)
	{
		system("cls");

		ScreenPush();

		Arr[PlayerY][PlayerX] = '*';

		ScreenPrint();

		PlayerMove();
	}

	int a = 0;
}