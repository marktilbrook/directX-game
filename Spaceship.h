#pragma once
#include "GameObject.h"
#include "vector2D.h"
#include "myinputs.h"
class Spaceship :
    public GameObject
{
private:
    Vector2D m_velocity;
    MyInputs* pInputs = MyInputs::GetInstance();
    
public:
    Spaceship();
    void Initialise(Vector2D position); //initialise with starting position
    void Update(double frametime);
};

