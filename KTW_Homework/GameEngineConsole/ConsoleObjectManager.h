#pragma once
#include <vector>
#include <list>
#include "ConsoleGameObject.h"

class ConsoleObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)
	{
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}

		std::list<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		Group.push_back(NewObject);

		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();

	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
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

	static std::vector<std::list<ConsoleGameObject*>> AllObject;
};

