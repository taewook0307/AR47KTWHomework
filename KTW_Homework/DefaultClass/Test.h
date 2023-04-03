#pragma once

class DefaultClass
{
public:
	// constrcuter destructer
	DefaultClass();
	~DefaultClass();

	// delete Function
	DefaultClass(const DefaultClass& _Other) = delete;
	DefaultClass(DefaultClass&& _Other) noexcept = delete;
	DefaultClass& operator=(const DefaultClass& _Other) = delete;
	DefaultClass& operator=(DefaultClass&& _Other) noexcept = delete;

protected:

private:

};

