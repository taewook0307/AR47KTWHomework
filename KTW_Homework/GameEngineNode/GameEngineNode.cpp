#include <iostream>

// 노드 형태
// 어떤 클래스가 자신 내부에 자기자신의 참조형(보통 포인터)을 n개 들고 있는 형태

class MapZone
{
private:
	const char* Name;
	MapZone* LinkZone;

public:
	void SetName(const char* _Name)
	{
		Name = _Name;
	}

	void Link(MapZone* _LinkZone)
	{
		LinkZone = _LinkZone; 
	}
};

int main()
{

}