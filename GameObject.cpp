#include "GameObject.h"

void GameObject::LoadImage(const wchar_t* image) 
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	m_image = pDE->LoadPicture(image);
}

void GameObject::Render()
{
	//check if object is active
	if (m_isActive)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(m_position, m_image, 1.5, m_angle);
	}
	
}

