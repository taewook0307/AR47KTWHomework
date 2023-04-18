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

void Parts::NextMove()
{
	Parts* Next = GetNext();

	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}