#pragma once
#include "GameObject.h"

class Bullet :
    public GameObject
{
private:
    Vector2D m_velocity;
    float m_lifespan;
    

public:
    Bullet();
    void Initialise(Vector2D position, Vector2D velocity); //initialise with starting position
    void Update(float frametime);

};

