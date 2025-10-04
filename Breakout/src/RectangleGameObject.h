#pragma once
#include "ShapeType.h"
#include "GameObject.h"
#include <raylib.h>

class RectangleGameObject : public GameObject
{
public:
	RectangleGameObject(ShapeType a_shape) : GameObject(a_shape) {}
	Rectangle ReturnRectangle()
	{
		return Rectangle{ m_position.x,m_position.y,m_size.x,m_size.y };
	}
	virtual void Draw() override = 0;
protected:
	Vector2 m_position = {};
	Vector2 m_size = {};
};