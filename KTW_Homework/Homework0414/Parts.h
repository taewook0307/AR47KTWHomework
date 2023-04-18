#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>

// ���� :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			return this;
		}

		return Next->GetLast();
	}

	inline Parts* GetNext()
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("�ڽ��� NextNode�� nullptr�� �����Ϸ��� �߽��ϴ�.");
		}

		Next = _Next;
	}

	inline int2 GetPrevPos()
	{
		return PrevPos;
	}

	inline void SetPos(const int2& _Value) override
	{
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	void NextMove();

protected:
	void Update() override;

private:
	Parts* Next;
	Parts* Prev;

	int2 PrevPos;
};

