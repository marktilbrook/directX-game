#pragma once
#include <list>
#include "GameObject.h"
#include "gametimer.h"

class ObjectManager
{

private:
	std::list<GameObject*> pObjectList;

public:
	void AddObject(GameObject* _newObject);
	void RenderAll();
	void UpdateAll(float _frametime);
	void DeleteAll();

	
};

