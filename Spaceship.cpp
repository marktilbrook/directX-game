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

	if (pInputs->KeyPressed(DIK_W))
	{
		Vector2D accelleration(0, 300);
		
		m_velocity = m_velocity + accelleration*frametime;
	}
	if (pInputs->KeyPressed(DIK_S))
	{
		Vector2D accelleration(0, -300);
		m_velocity = m_velocity  + accelleration * frametime;
	}

	if (pInputs->KeyPressed(DIK_A))// TODO: Directional Movement
	{
		Vector2D accelleration;
		accelleration.setBearing(m_angle, -25.f);
		m_velocity = m_velocity + accelleration;
		
	}

	if (pInputs->KeyPressed(DIK_D))
	{
		Vector2D accelleration;
		accelleration.setBearing(m_angle, 25.f);
		m_velocity = m_velocity + accelleration;
		
	}
	Vector2D friction = -0.5 * m_velocity;
	m_velocity = m_velocity + friction*frametime;
	m_position = m_position + m_velocity*frametime;
}
