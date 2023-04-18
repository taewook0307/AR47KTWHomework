#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>

// 설명 :
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

	inline int2 GetPrevPos() const
	{
		return PrevPos;
	}

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			return this;
		}
		return Next->GetLast();
	}

	inline Parts* GetNext() const
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("nullptr을 Next로 지정하려고 했습니다.");
		}
		Next = _Next;

		_Next->Prev = this;
	}

	inline Parts* GetPrev() const
	{
		return Prev;
	}

	inline void SetPrev(Parts* _Prev)
	{
		if (nullptr == _Prev)
		{
			MsgBoxAssert("nullptr을 Prev로 지정하려고 했습니다.");
		}
		Prev = _Prev;

		_Prev->Next = this;
	}

	void NextMove();

	void SetPos(const int2& _Pos) override;
protected:

private:
	Parts* Next;
	Parts* Prev;

	int2 PrevPos;
};

