/*****************************************************************************
* Project: Breakout
* File : Brick.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The Brick class represents a brick object in the Breakout game, inheriting from RectangleGameObject.
* It includes methods to set and get the brick's position and size, as well as a method to destroy the brick,
* which notifies the GameManager to update the game state accordingly.
*
* History:
* 09.09.25 JM Created
* 09.09.25 JM Draw method implemented
* 09.09.25 JM Added methods to set and get position and size
* 25.09.25 JM Added DestroyBrick method to notify GameManager
******************************************************************************/

#pragma once
#include <raylib.h>
#include "RectangleGameObject.h"

class GameManager;

class Brick : public RectangleGameObject
{
public:
	Brick(GameManager* a_gameManager, ShapeType a_brickShape);
	~Brick();
	void SetBrickPosition(Vector2 a_position);
	void SetBrickSize(Vector2 a_size);
	void SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size);
	Vector2 GetBrickPostion() const;
	void DestroyBrick();

	//Interface
	void Draw() override;
private:
	GameManager* m_gameManager = nullptr;
};

