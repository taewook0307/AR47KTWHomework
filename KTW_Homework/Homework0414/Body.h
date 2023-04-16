#pragma once
#include "Parts.h"

class Body : public Parts
{
public:
	// constrcuter destructer
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	bool SameHeadPos();
	bool SameHeadPos(int2 _Pos);
	bool SameAnotherBodyPos(int2 _Pos);

protected:
	void Update() override;
	void Render() override;
	
private:
};

