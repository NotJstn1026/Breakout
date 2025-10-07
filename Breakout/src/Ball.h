/*****************************************************************************
* Project: Breakout
* File : Ball.h
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
* 24.09.25 JM Added Update method with logic
* 04.10.25 JM Added HitCheck method with collision logic
* 07.10.25 JM Added GameManager member to 
******************************************************************************/

#pragma once
#include <raylib.h>
#include "GameObject.h"
#include "MinMaxValue.h"


class GameManager;

class Ball : public GameObject
{
public:
	Ball(float a_startPostion, std::vector<GameObject*> a_gameObjects, GameManager* a_gameManager, ShapeType a_ballShape);
	~Ball();
	void Update();
	inline int GetBounceCounter() const { return m_bounceCounter; }

	void Draw() override;
private:
	const float M_START_RADIUS = 5.5f;
	const float M_VERTICAL_SPEED = 3.0f;
	const MinMaxValue<float> M_RANDOM_VALUES = { -3.0f,3.0f };
	const Vector2 M_MAX_SPEED = { 5.0f,5.0f };
	const float M_SPEED_FACTOR = 0.15f;

	void OutOfBoundsCheck();
	void HitCheck();

	GameManager* m_gameManager = nullptr;
	std::vector<GameObject*> m_gameObjects = {};
	Vector2 m_postion = {};
	Vector2 m_speed = {};
	float m_radius = M_START_RADIUS;
	int m_bounceCounter = 0;
};

