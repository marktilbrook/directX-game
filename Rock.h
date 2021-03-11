#pragma once
#include "GameObject.h"
class Rock :
    public GameObject
{
private:
    
public:
    Rock();
    void Initialise(Vector2D position); //initialise with starting position
    void Update(float frametime);
};

