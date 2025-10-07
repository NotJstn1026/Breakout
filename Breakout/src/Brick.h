/*****************************************************************************
* Project: Breakout
* File : Brick.h
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

