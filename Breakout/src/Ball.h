#pragma once
#include <raylib.h>
#include "GameObject.h"
#include "MinMaxValue.h"



class Ball : public GameObject
{
public:
	Ball(float a_startPostion, std::vector<GameObject*> a_gameObjects, ShapeType a_ballShape);
	~Ball();
	Vector2 GetBallPostion() const;
	float GetBallRadius() const;
	void Update();


	void Draw() override;
private:
	const float M_START_RADIUS = 5.5f;
	const float M_VERTICAL_SPEED = 3.0f;
	const MinMaxValue<float> M_RANDOM_VALUES = { -3.0f,3.0f };

	void OutOfBoundsCheck();
	void HitCheck();

	std::vector<GameObject*> m_gameObjects = {};
	Vector2 m_postion = {};
	Vector2 m_speed = {};
	float m_radius = M_START_RADIUS;
};

