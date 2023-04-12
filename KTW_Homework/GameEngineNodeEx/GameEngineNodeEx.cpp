#include <iostream>
#include <GameEngineConsole/GameEngineArray.h>
#include <conio.h>

class MapZone
{
private:
	const char* Name;
	GameEngineArray<MapZone*> LinkZone;

public:
	MapZone* SelectNext()
	{
		system("cls");
		printf_s("현재 이곳은 %s 입니다.\n", GetName());
		printf_s("어디로 가시겠습니까?\n");

		for (int i = 0; i < LinkZone.Count(); i++)
		{
			printf("%d. %s\n", i + 1, LinkZone[i]->GetName());
		}

		int Select = _getch();
		int SelectIndex = Select - '1';

		if (SelectIndex >= LinkZone.Count())
		{
			return this;
		}

		return LinkZone[SelectIndex];

	}

	const char* GetName()
	{
		return Name;
	}

	const char* GetName() const
	{
		return Name;
	}

	void SetName(const char* _Name)
	{
		Name = _Name;
	}

	void Link(MapZone* _OtherZone)
	{
		if (nullptr == _OtherZone)
		{
			return;
		}

		LinkZone.ReSize(LinkZone.Count() + 1);
		LinkZone[LinkZone.Count() - 1] = _OtherZone;

		_OtherZone->LinkZone.ReSize(_OtherZone->LinkZone.Count() + 1);
		_OtherZone->LinkZone[_OtherZone->LinkZone.Count() - 1] = this;
	}
};

int main()
{
	MapZone Map1;
	MapZone Map2;
	MapZone Map3;
	MapZone Map4;
	MapZone Map5;

	Map1.SetName("하이데의 폐허");
	Map2.SetName("청의성당");
	Map3.SetName("매듀라");
	Map4.SetName("하이데의 큰 불탑");
	Map5.SetName("숨겨진 항구");

	Map1.Link(&Map2);
	Map1.Link(&Map4);
	Map1.Link(&Map3);

	Map2.Link(&Map5);

	MapZone* CurMap = &Map1;
	while (nullptr != CurMap)
	{
		CurMap = CurMap->SelectNext();
	}
}