#pragma once
#include "Parts.h"

// Ό³Έν :
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

	int2 GetDir() const
	{
		return Dir;
	}

protected:
	void Update() override;
	bool IsBodyCheck();
	void NewBodyCreateCheck();

private:
	int2 Dir = int2::Up;

};

