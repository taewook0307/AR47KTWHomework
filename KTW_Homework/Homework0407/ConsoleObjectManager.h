#pragma once
#include <GameEngineConsole/GameEngineArray.h>
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)
	{
		if (_Order >= AllObject.Count())
		{
			AllObject.ReSize(_Order + 1);
		}

		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		Group.ReSize(Group.Count() + 1);
		Group[Group.Count() - 1] = NewObject;

		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectDelete();

	static GameEngineArray<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}


private:
	// constrcuter destructer
	ConsoleObjectManager();
	~ConsoleObjectManager();

	// delete Function
	ConsoleObjectManager(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _Other) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _Other) noexcept = delete;

	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;
};

