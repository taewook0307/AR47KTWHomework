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

	// ���� ��ġ���� �� ��ġ�� ���� ���� Ȯ��
	Next->Dir = MyPos - MyNextPos;

	// ���⿡ ���� �ٸ� ����� ����
	if (Next->GetDir() == int2::Left)
	{
		Next->RenderChar = L'��';
	}
	else if (Next->GetDir() == int2::Right)
	{
		Next->RenderChar = L'��';
	}
	else if (Next->GetDir() == int2::Up)
	{
		Next->RenderChar = L'��';
	}
	else if (Next->GetDir() == int2::Down)
	{
		Next->RenderChar = L'��';
	}
	
	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}