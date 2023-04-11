#include "ConsoleObjectManager.h"

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	for (size_t i = 0; i < AllObject.Count(); i++)
	{
		for (size_t j = 0; j < AllObject[i].Count(); j++)
		{
			ConsoleGameObject* Object = AllObject[i][j];
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
	for (size_t i = 0; i < AllObject.Count(); i++)
	{
		for (size_t j = 0; j < AllObject[i].Count(); j++)
		{
			ConsoleGameObject* Object = AllObject[i][j];
			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Render();
		}
	}
}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (size_t i = 0; i < AllObject.Count(); i++)
	{
		for (size_t j = 0; j < AllObject[i].Count(); j++)
		{
			ConsoleGameObject* Object = AllObject[i][j];

			if (nullptr == Object)
			{
				delete[] Object;
				Object = nullptr;
			}
		}
	}
}