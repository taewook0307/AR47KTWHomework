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

	int2 MyPos = GetPos();
	int2 MyNextPos = GetPrevPos();

	// 현재 위치에서 전 위치를 빼서 방향 확인
	Next->Dir = MyPos - MyNextPos;

	// 방향에 따라 다른 모양을 대입
	if (Next->GetDir() == int2::Left)
	{
		Next->RenderChar = L'◀';
	}
	else if (Next->GetDir() == int2::Right)
	{
		Next->RenderChar = L'▶';
	}
	else if (Next->GetDir() == int2::Up)
	{
		Next->RenderChar = L'▲';
	}
	else if (Next->GetDir() == int2::Down)
	{
		Next->RenderChar = L'▼';
	}
	
	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}