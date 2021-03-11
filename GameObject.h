#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "myinputs.h"

class GameObject
{
protected:
	Vector2D m_position;
	float m_angle;
	bool m_isActive;

private:
	PictureIndex m_image;

protected:
	void LoadImage(const wchar_t* image);

public:
	virtual void Render();
	virtual void Update(float frametime) = 0;

	

	Vector2D GetCurrentPosition();
	
};

