/*****************************************************************************
* Project: Breakout
* File : RectangleGameObject.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
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