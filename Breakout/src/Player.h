/*****************************************************************************
* Project: Breakout
* File : Player.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The Player class represents the player's paddle in the Breakout game, inheriting from RectangleGameObject.
* It includes methods for drawing the paddle, updating its position based on player input, and handling movement in specified directions.
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
	const float M_SEVEN = 7.0f;
	const float M_EIGHTH = 8.0f;
	const float M_HALF = 0.5f;
	const float M_SCREEN_BORDER_OFFSET = 30.0f;
	float m_speed = 5;

};