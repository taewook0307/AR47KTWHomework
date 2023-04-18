#include "Parts.h"

Parts::Parts() 
{
	Prev = nullptr;
	Next = nullptr;
}

Parts::~Parts() 
{
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

void Parts::SetPos(const int2& _Pos)
{
	PrevPos = GetPos();

	ConsoleGameObject::SetPos(_Pos);
}