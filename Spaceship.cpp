#include "Spaceship.h"
#include "gamecode.h"

const int ACCELLERATION = 500;
const float FRICTION = -1;

const float BULLETSPEED = 800.f;

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
	m_shootDelay = 0.f;
}


//todo refactor into functions
void Spaceship::Update(float frametime)
{
	//Position = Position + Velocity*FrameTime

	if (m_isActive)
	{
		//Sample Keyboard
		pInputs->SampleKeyboard();

		//UP
		if (pInputs->KeyPressed(DIK_W))
		{
			Vector2D accelleration(0, ACCELLERATION);

			m_velocity = m_velocity + accelleration * frametime;
		}
		//DOWN
		if (pInputs->KeyPressed(DIK_S))
		{
			Vector2D accelleration(0, -ACCELLERATION);
			m_velocity = m_velocity + accelleration * frametime;
		}
		//LEFT
		if (pInputs->KeyPressed(DIK_A))
		{
			Vector2D accelleration(-ACCELLERATION, 0);
			m_velocity = m_velocity + accelleration * frametime;

		}
		//RIGHT
		if (pInputs->KeyPressed(DIK_D))
		{
			Vector2D accelleration(ACCELLERATION, 0);
			m_velocity = m_velocity + accelleration * frametime;

		}
		Vector2D friction = FRICTION * m_velocity;
		m_velocity = m_velocity + friction * frametime;
		m_position = m_position + m_velocity * frametime;


		//shoot
		if (pInputs->KeyPressed(DIK_SPACE) && m_shootDelay <= 0)
		{
			Bullet* pBullet = new Bullet();
			Vector2D bulletVelocity;
			Vector2D bulletOffset(0, 100);
			bulletVelocity.setBearing(m_angle, BULLETSPEED);

			pBullet->Initialise(GetCurrentPosition() + bulletOffset, bulletVelocity + m_velocity);

			Game::instance.GetObjectManager().AddObject(pBullet);
			m_shootDelay = 0.5f;
		}
		m_shootDelay = m_shootDelay - frametime;
	}

	
}


