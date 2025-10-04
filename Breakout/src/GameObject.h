#pragma once
#include "ShapeType.h"


class GameObject
{
public:
	GameObject(ShapeType a_shape) : m_shapeType(a_shape) {}
	virtual void Draw() = 0;
	
	inline ShapeType GetShape() const
	{
		return m_shapeType;
	}

protected:
	ShapeType m_shapeType = {};
};