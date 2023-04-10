#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;
class Bomb : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Bomb();
	~Bomb();

	// delete Function
	Bomb(const Bomb& _Other) = delete;
	Bomb(Bomb&& _Other) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;

protected:
	void Update() override;
	void Render() override;

private:
	int BoomCount = 10;
};

