#include "Bullet.h"


//constructor
Bullet::Bullet()
{
	m_isActive = false;
}

void Bullet::Initialise(Vector2D position, Vector2D velocity)
{
	LoadImage(L"res/bullet.bmp");
	m_isActive = true;
	m_angle = 0.f;
	m_position = position;
	m_velocity = velocity;
	m_lifespan = 2.f;
}

void Bullet::Update(float frametime)
{
	m_position = m_position + m_velocity * frametime;
	m_lifespan = m_lifespan - frametime;
	if (m_lifespan <= 0)
	{
		m_isActive = false;
	}
}
