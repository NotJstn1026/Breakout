/*****************************************************************************
* Project: Breakout
* File : GameObject.h
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