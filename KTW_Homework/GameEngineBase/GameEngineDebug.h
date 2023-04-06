#pragma once

//class GameEngineBase
//{
//public:
//	// constrcuter destructer
//	GameEngineBase();
//	~GameEngineBase();
//
//	// delete Function
//	GameEngineBase(const GameEngineBase& _Other) = delete;
//	GameEngineBase(GameEngineBase&& _Other) noexcept = delete;
//	GameEngineBase& operator=(const GameEngineBase& _Other) = delete;
//	GameEngineBase& operator=(GameEngineBase&& _Other) noexcept = delete;
//
//protected:
//
//private:
//
//};

#include <Windows.h>
#include <assert.h>

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);
