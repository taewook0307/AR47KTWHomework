#include <crtdbg.h>

#include "ShootingGame.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    ShootingGame::GameSetting();
    ShootingGame::GameStart();
}