/*****************************************************************************
* Project: Breakout
* File : RectangleGameObject.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
* 
* The RectangleGameObject class is a specialized type of GameObject that represents a rectangular shape in the game. 
* It inherits from GameObject and adds specific properties for a rectangle's position and size. 
* The class also provides a ReturnRectangle() method to generate a Raylib Rectangle struct, 
* which is essential for drawing and collision detection.
*
* History:
* 04.10.25 JM Created
* 04.10.25 JM Added ReturnRectangle method
******************************************************************************/

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