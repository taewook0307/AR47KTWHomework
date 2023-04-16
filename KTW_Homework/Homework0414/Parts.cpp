#include "Parts.h"

Parts::Parts() 
{
	Prev = nullptr;
	Next = nullptr;
}

Parts::~Parts() 
{
}

void Parts::Update() 
{
	ConsoleGameObject::Update();
}