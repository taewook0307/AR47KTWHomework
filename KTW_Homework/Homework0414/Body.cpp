#include "Body.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

Body::Body() 
{
	RenderChar = '#';
	IsChange = false;
}

Body::~Body() 
{
}

void Body::Update()
{
	ConsoleGameObject::Render();
}	
