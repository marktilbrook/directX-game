#include "Rock.h"

Rock::Rock()
{
	m_isActive = false;
}

void Rock::Initialise(Vector2D position)
{
	LoadImage(L"res/rock1.bmp");
	m_isActive = true;
	m_angle = 0.f;
	m_position = position;
	
	
}

void Rock::Update(double frametime)
{

}
