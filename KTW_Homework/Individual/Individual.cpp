#include <iostream>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
	// 맵 전체 세팅
	ConsoleGameScreen::GetMainScreen().ScreenClear();
	// 맵 전체 출력
	ConsoleGameScreen::GetMainScreen().ScreenRender();

	// Player 생성
	Player NewPlayer;
	// 생성된 플레이어를 맵 중앙부분에 위치
	NewPlayer.SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());

	while (true)
	{
		// 콘솔창 클리어
		system("cls");

		// 맵 전체 세팅
		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// Player 위치 다시 세팅
		ConsoleGameScreen::GetMainScreen().ScreenRenderSomething(NewPlayer.GetPos(), NewPlayer.GetRenderChar());

		// 맵 전체 출력
		ConsoleGameScreen::GetMainScreen().ScreenRender();

		// 플레이어 작동에 관한 키 입력
		NewPlayer.Input();
	}
}