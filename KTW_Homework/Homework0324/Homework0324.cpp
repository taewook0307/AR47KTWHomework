#include <iostream>
#include <conio.h>
#include <Windows.h>
// 숙제0 : 전방향 다 움직이게 만들기
// 숙제1 : 잔상 지우기
// 숙제2 : 화면 밖으로 못 나가게 하기

// 안해도 되는 숙제
// 숙제3 : 장애물 만들고 배치하기
// 숙제4 : f를 누르면 폭탄이 설치되고 눈에 보여야 함.
// 
// --------------------------------------------------------- 숙제4까지 완료
// 숙제5 : 일정시간이 지나고 폭탄이 터지기

int main()
{
	const int ScreenYSize = 11;
	const int ScreenXSize = 11;

	char Floor = ' ';

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = Floor;
		}
	}

	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	char PlayerDirection = 'L';

#pragma region 장애물
	srand(time(0));

	for (int WallCount = 10; WallCount > 0; --WallCount)			// 장애물 위치를 랜덤하게 정해줌
	{
		int x = rand() % ScreenXSize;
		int y = rand() % ScreenYSize;

		Arr[y][x] = 'X';
	}
#pragma endregion

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

		printf_s("\n플레이어가 보는 방향 : %c", PlayerDirection);

		if (0 == _kbhit())		// 키를 누르지 않았다면
		{
			Sleep(200);

			continue;
		}

#pragma region 키 입력
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			if (Arr[PlayerY][PlayerX - 1] == '@' || Arr[PlayerY][PlayerX - 1] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}

			else if (PlayerDirection != 'L')			// 플레이어가 좌측을 보고 있지 않을 경우
			{
				PlayerDirection = 'L';
				break;
			}

			else
			{
				if (PlayerX == 0)						// 플레이어가 제일 좌측에 위치했을 경우
				{
					PlayerX = 0;
				}
				else
				{
					PlayerX -= 1;
					Arr[PlayerY][PlayerX + 1] = Floor;
				}
				break;
			}

		case 'd':
		case 'D':
			if (Arr[PlayerY][PlayerX + 1] == '@' || Arr[PlayerY][PlayerX + 1] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}

			else if (PlayerDirection != 'R')			// 플레이어가 우측을 보고 있지 않을 경우
			{
				PlayerDirection = 'R';
				break;
			}

			else
			{
				if (PlayerX == ScreenXSize - 1)			// 플레이어가 제일 우측에 위치했을 경우
				{
					PlayerX = ScreenXSize - 1;
				}
				else
				{
					PlayerX += 1;
					Arr[PlayerY][PlayerX - 1] = Floor;
				}
				break;
			}

		case 's':
		case 'S':
			if (Arr[PlayerY + 1][PlayerX] == '@' || Arr[PlayerY + 1][PlayerX] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}

			else if (PlayerDirection != 'D')			// 플레이어가 아래측을 보고 있지 않을 경우
			{
				PlayerDirection = 'D';
				break;
			}

			else
			{
				if (PlayerY == ScreenYSize - 1)			// 플레이어가 제일 아래쪽에 위치했을 경우
				{
					PlayerY = ScreenYSize - 1;
				}
				else
				{
					PlayerY += 1;
					Arr[PlayerY - 1][PlayerX] = Floor;
				}
				break;
			}

		case 'w':
		case 'W':
			if (Arr[PlayerY - 1][PlayerX] == '@' || Arr[PlayerY - 1][PlayerX] == 'X')		// 플레이어가 폭탄 혹은 장애물쪽으로 가려고 할 경우
			{
				break;
			}

			else if (PlayerDirection != 'U')			// 플레이어가 위쪽을 보고 있지 않을 경우
			{
				PlayerDirection = 'U';
				break;
			}

			else
			{

				if (PlayerY == 0)						// 플레이어가 제일 위쪽에 위치했을 경우
				{
					PlayerY = 0;
				}
				else
				{
					PlayerY -= 1;
					Arr[PlayerY + 1][PlayerX] = Floor;
				}
				break;
			}

		case 'f':										// 폭탄 설치
		case 'F':
			if (PlayerDirection == 'L' && Arr[PlayerY][PlayerX - 1] != 'X')					// 플레이어가 좌측을 보고 있는 경우 or 폭탄을 놓을 위치에 장애물이 있는 경우
			{
				if (PlayerX == 0)															// 플레이어가 맵에서 가장 좌측 라인에 있을 경우
				{
					break;
				}
				else
				{
					Arr[PlayerY][PlayerX - 1] = '@';
				}
			}

			else if (PlayerDirection == 'R' && Arr[PlayerY][PlayerX + 1] != 'X')				// 플레이어가 우측을 보고 있는 경우 or 폭탄을 놓을 위치에 장애물이 있는 경우
			{
				if (PlayerX == ScreenXSize - 1)													// 플레이어가 맵에서 가장 우측 라인에 있을 경우
				{
					break;
				}
				else
				{
					Arr[PlayerY][PlayerX + 1] = '@';
				}
			}

			else if (PlayerDirection == 'D' && Arr[PlayerY + 1][PlayerX] != 'X')			// 플레이어가 아래를 보고 있는 경우 or 폭탄을 놓을 위치에 장애물이 있는 경우
			{
				if (PlayerY == ScreenYSize - 1)												// 플레이어가 맵에서 가장 아래쪽 라인에 있을 경우
				{
					break;
				}
				else
				{
					Arr[PlayerY + 1][PlayerX] = '@';
				}
			}

			else if (PlayerDirection == 'U' && Arr[PlayerY - 1][PlayerX] != 'X')			// 플레이어가 위를 보고 있는 경우 or 폭탄을 놓을 위치에 장애물이 있는 경우
			{
				if (PlayerY == 0)															// 플레이어가 맵에서 가장 위쪽 라인에 있을 경우
				{
					break;
				}
				else
				{
					Arr[PlayerY - 1][PlayerX] = '@';
				}
			}
			break;
		default:
			break;
		}
#pragma endregion

		Sleep(200);
	}
}