/*****************************************************************************
* Project: Breakout
* File : Player.h
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
* 09.09.25 JM Created
* 09.09.25 JM Draw method implemented
* 24.09.25 JM Added Movement method and Update logic
* 07.10.25 JM Added ReturnRectangle method for collision detection
******************************************************************************/

#pragma once
#include <raylib.h>
#include "RectangleGameObject.h"
#include "MOVEMENTDIRECTION.h"

class Player : public RectangleGameObject
{
public:
	Player(ShapeType a_playerShape);
	~Player();
	Vector2 GetPostion() const;
	Vector2 GetSize() const;
	void Draw()override;
	void Update();
	Rectangle ReturnRectangle();
private:
	void Movement(MOVEMENTDIRECTION a_movementDirection);
	const int M_HALFSCREEN = 2;
	float m_speed = 5;
};