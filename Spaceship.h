#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Spaceship :
    public GameObject
{
private:
    Vector2D m_velocity;
    MyInputs* pInputs = MyInputs::GetInstance();
    float m_shootDelay;
    
public:
    Spaceship();
    void Initialise(Vector2D position); //initialise with starting position
    void Update(float frametime);

    
};

