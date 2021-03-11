#include "ObjectManager.h"

void ObjectManager::AddObject(GameObject* _newObject)
{
	//add new game object to end of list
	pObjectList.push_back(_newObject);
}

void ObjectManager::RenderAll()
{
	//loop through objects in list and render
	for (GameObject* pNext : pObjectList)
	{
		if (pNext != nullptr)
		{
			pNext->Render();
		}
		
	}
}


void ObjectManager::UpdateAll(float _frametime)//frametime will be passed from gamecode
{
	//loop through objects in list and update
	for (GameObject* pNext : pObjectList)
	{
		if (pNext != nullptr)
		{
			pNext->Update(_frametime);
		}
	}
}

void ObjectManager::DeleteAll()
{
	//loop through objects in list and delete and null out
	for (GameObject* pNext : pObjectList)
	{
		delete pNext;
		pNext = nullptr;
	}
	pObjectList.clear();
}
