#include "Spaceship.h"

//constructor
Spaceship::Spaceship()
{
	m_isActive = false;
}

void Spaceship::Initialise(Vector2D pos)
{
	LoadImage(L"res/basic.bmp");
	m_isActive = true;
	m_angle = 0.f;
	m_position = pos;
	m_velocity = Vector2D(0, 0);
}

void Spaceship::Update(double frametime)
{
	//Position = Position + Velocity*FrameTime

	//Sample Keyboard
	pInputs->SampleKeyboard();

	//UP
	if (pInputs->KeyPressed(DIK_W))
	{
		Vector2D accelleration(0, 300);
		
		m_velocity = m_velocity + accelleration*frametime;
	}
	//DOWN
	if (pInputs->KeyPressed(DIK_S))
	{
		Vector2D accelleration(0, -300);
		m_velocity = m_velocity  + accelleration * frametime;
	}
	//LEFT
	if (pInputs->KeyPressed(DIK_A))
	{
		Vector2D accelleration(-300, 0);
		m_velocity = m_velocity + accelleration * frametime;
		
	}
	//RIGHT
	if (pInputs->KeyPressed(DIK_D))
	{
		Vector2D accelleration(300, 0);
		m_velocity = m_velocity + accelleration * frametime;
		
	}
	Vector2D friction = -0.7 * m_velocity;
	m_velocity = m_velocity + friction*frametime;
	m_position = m_position + m_velocity*frametime;
}
