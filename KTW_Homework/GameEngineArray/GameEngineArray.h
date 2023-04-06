#pragma once

#include <GameEngineBase/GameEngineDebug.h>

// #include <> => 포함 디렉터리에 들어가 있는 파일을 호출
// #include "" => 포함 디렉터리에 들어가 있지 않는 파일을 호출
// 포함 디렉토리 : 프로젝트 속성 => VC++ 디렉터리

typedef int DataType;

class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		if (0 >= _Value)
		{
			MsgBoxAssert("0 크기의 배열을 만들 수 없음");
		}
	}

	~GameEngineArray()
	{
		if (ArrPtr != nullptr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		if (ArrPtr != nullptr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new DataType[_Other.ArrCount];
		ArrCount = _Other.ArrCount;

		for (size_t i = 0; i < ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		/*DataType* CopyPtr = ArrPtr;

		if (nullptr == ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new DataType[_Value];
		ArrCount = _Value;

		for (size_t i = 0; i < _Value; i++)
		{
			ArrPtr[i] = CopyPtr[i];
		}*/

		DataType* NewPtr = new DataType[_Value];

		for (size_t i = 0; i < _Value; i++)
		{
			NewPtr[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = NewPtr;
		ArrCount = _Value;
	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;
};