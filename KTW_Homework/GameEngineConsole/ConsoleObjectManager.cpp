#include "ConsoleObjectManager.h"
#include "ConsoleGameScreen.h"

std::vector<std::list<ConsoleGameObject*>> ConsoleObjectManager::AllObject;

ConsoleObjectManager::ConsoleObjectManager()
{
}

ConsoleObjectManager::~ConsoleObjectManager()
{
}

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Update();
		}
	}
}

void ConsoleObjectManager::ConsoleAllObjectRender()
{
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Render();
		}
	}

	ConsoleGameScreen::GetMainScreen().ScreenPrint();
}

void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End;)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object || false == Object->IsDeath())
			{
				++Start;
				continue;
			}

			Start = Group.erase(Start);

			delete Object;
			Object = nullptr;
		}

	}
}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object)
			{
				continue;
			}
			delete Object;
			Object = nullptr;
		}
	}
}