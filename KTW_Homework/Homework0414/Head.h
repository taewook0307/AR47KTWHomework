#pragma once
#include "Parts.h"

#include <vector>

class Head : public Parts
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;

	bool CheckPos();


protected:
	void Update() override;
	void IsBodyCheck();
	void NewBodyCreate();
	void CheckScreenFull();

private:
	int2 Dir = int2::Up;

	int BodyCount = 0;

	std::vector<int2> VectorPos;

	inline void BodyPlus()
	{
		++BodyCount;
	}
};

