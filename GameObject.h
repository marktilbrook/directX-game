#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"

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
	void Render();
	virtual void Update(double frametime) = 0;
	
};

