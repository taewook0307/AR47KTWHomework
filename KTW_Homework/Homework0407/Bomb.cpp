#include "Bomb.h"

Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (0 >= --BoomCount)
	{
		Off();
	}
}


void Bomb::Render()
{
	ConsoleGameObject::Render();
}