#include <iostream>
#include <conio.h>
#include <Windows.h>
// 숙제0 : 전방향 다 움직이게 만들기
// 숙제1 : 잔상 지우기
// 숙제2 : 화면 밖으로 못 나가게 하기

// 안해도 되는 숙제
// 숙제3 : 장애물 만들고 배치하기
// 숙제4 : f를 누르면 폭탄이 설치되고 눈에 보여야 함.
// 숙제5 : 일정시간이 지나고 폭탄이 터지면서

int main()
{
	const int ScreenYSize = 11;
	const int ScreenXSize = 11;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}

	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	while (true)
	{
		system("cls");

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}

		// 키를 눌렀다는것을 체크해주는 함수 : 키를 눌렀으면 1, 아니라면 0을 리턴
		// 정지하지 않음
		if (0 == _kbhit())		// 키를 누르지 않았다면
		{
			Sleep(200);			// 0.3초간 멈춘다.

			continue;
		}

		// 어떤 키를 눌렀는지 알려주는 함수
		char Ch = _getch();

		// A 키를 눌렀을 때
		if (Ch == 'a' || Ch == 'A') {
			if (PlayerX == 0)						// 플레이어가 제일 좌측에 위치했을 경우
			{
				PlayerX = 0;
			}
			else
			{
				PlayerX -= 1;
				Arr[PlayerY][PlayerX + 1] = 'a';
			}
			continue;
		}

		// D 키를 눌렀을 때
		else if (Ch == 'd' || Ch == 'D')
		{
			if (PlayerX == ScreenXSize - 1)			// 플레이어가 제일 우측에 위치했을 경우
			{
				PlayerX = ScreenXSize - 1;
			}
			else
			{
				PlayerX += 1;
				Arr[PlayerY][PlayerX - 1] = 'a';
			}
			continue;
		}

		// S 키를 눌렀을 때
		else if (Ch == 's' || Ch == 'S')
		{
			if (PlayerY == ScreenYSize - 1)			// 플레이어가 제일 아래쪽에 위치했을 경우
			{
				PlayerY = ScreenYSize - 1;
			}
			else
			{
				PlayerY += 1;
				Arr[PlayerY - 1][PlayerX] = 'a';
			}
			continue;
		}

		// W 키를 눌렀을 때
		else if (Ch == 'w' || Ch == 'W')
		{
			if (PlayerY == 0)						// 플레이어가 제일 위쪽에 위치했을 경우
			{
				PlayerY = 0;
			}
			else
			{
				PlayerY -= 1;
				Arr[PlayerY + 1][PlayerX] = 'a';
			}
			continue;
		}

		Sleep(200);
	}
}