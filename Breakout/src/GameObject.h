/*****************************************************************************
* Project: Breakout
* File : GameObject.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The GameObject class is an abstract base class that defines a common interface for all game objects in the Breakout game.
* It includes a pure virtual Draw() method that must be implemented by all derived classes, ensuring that each game object can be rendered appropriately.
*
* History:
* 24.09.25 JM Created
* 24.09.25 JM Added Draw method as pure virtual and ShapeType member
******************************************************************************/

#pragma once
#include "ShapeType.h"


class GameObject
{
public:
	GameObject(ShapeType a_shape) : m_shapeType(a_shape) {}
	virtual void Draw() = 0;
	
	inline void SetColor(Color a_color)
	{
		m_color = a_color;
	}

	inline ShapeType GetShape() const
	{
		return m_shapeType;
	}

protected:
	ShapeType m_shapeType = {};
	Color m_color = WHITE;
};